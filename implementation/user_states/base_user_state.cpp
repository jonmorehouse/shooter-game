#include "user_states/base_user_state.hpp"

using namespace std;

Base_user_state::Base_user_state(Game_state * game_state) : game_state(game_state), QGraphicsView(game_state->get_scene()), scene(game_state->get_scene()), user_api(game_state->get_user_api()) {

	// create the container widgets
	this->body = new QGroupBox();
	this->layout = new QFormLayout;

	// initialize vectors
	this->buttons = vector<Button *>();
	this->elements = vector<QWidget *>();//qwidgets hold anything from 

}

Base_user_state::~Base_user_state() {

	this->disconnect();

	for (int i = 0, z = this->buttons.size(); i < z; i++) {

		this->buttons[i]->disconnect();
		this->buttons[i]->deleteLater();

	}


	this->body->deleteLater();//delete the body later
	delete this->layout;

}

/********** PUBLIC SLOTS *********/
void Base_user_state::process(QString message) {
	
	if (message == "exit" || message == "menu") {

		this->game_state->set_application("menu");//set the menu application as the destination
		emit generate_state_change();//
	}
}



/********* GENERAL FUNCTIONS *****/
QRect Base_user_state::get_position() {

	int height = this->game_state->get_height(),
		width = this->game_state->get_width();

	// will assume that we want the 25,25,50,50 element percentages
	return QRect(0.25*width, 0.25*height, 0.5*height, 0.5*width);

}

void Base_user_state::create_body() {

	this->buttons.push_back(new Button("Main Menu", "exit"));
	connect(this->buttons.back(), SIGNAL(menu_selection(QString)), this, SLOT(process(QString)));
}

void Base_user_state::create_layout() {//responsible for creating the body of the application menu

	// initialize the actual elements
	this->scene->addWidget(this->body);//add body to the element
	this->body->setLayout(this->layout);//set layout
	this->body->setGeometry(this->get_position());//initialize position
}
	
