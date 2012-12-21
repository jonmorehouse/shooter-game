#include "controllers/application_controller.hpp"

using namespace std;

Application_controller::Application_controller(Game_state * game_state) : game_state(game_state), QGraphicsView(game_state->get_scene()) {

	this->game_state->set_application("menu");
	this->application_change();

}

Application_controller::~Application_controller() {


}

//slots
void Application_controller::keyPressEvent(QKeyEvent * event) {

	emit keyPress(event);
}

// responds to calls from sub classed controllers to update the application state
void Application_controller::application_change() {


	QString new_application = this->game_state->get_application();

	if (new_application == this->current_application) return;//don't need to update

	if (this->current_controller) {

		this->clear_screen();//clear the scene 
		this->current_controller->disconnect();//disconnect the current_controller
		delete this->current_controller;//delete the current_controller
		
	}

	if (new_application == "play" || new_application == "start" || new_application == "game")
		this->current_controller = new Game_controller(this->game_state);

	else if (new_application == "menu")
		this->current_controller = new Menu_controller(this->game_state);

	else if (new_application == "exit") {

		this->game_state->get_window()->quit();//quit the application
		return;
	}

	else
		this->current_controller = new User_controller(this->game_state);

	// set the object application state
	this->current_application = new_application;
	connect(this->current_controller, SIGNAL(application_update()), this, SLOT(application_change()));//connect the 
	connect(this, SIGNAL(keyPress(QKeyEvent *)), this->current_controller, SLOT(keyPressEvent(QKeyEvent *)));


}

void Application_controller::clear_screen() {

	// responsible for clearing the screen completely
	QGraphicsScene * scene = this->game_state->get_scene();

	QList<QGraphicsItem *> list = scene->items();
    QList<QGraphicsItem *>::Iterator it = list.begin();

	for (; it != list.end(); ++it)
		if (*it)
			scene->removeItem(*it);
}









