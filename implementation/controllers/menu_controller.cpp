#include "controllers/menu_controller.hpp"

#include <QDebug>

using namespace std;

Menu_controller::Menu_controller(Game_state * game_state) : Base_controller(game_state) {

	QGraphicsWidget * temp;//this is used during iteration to add to the layout

	this->layout = new QGraphicsLinearLayout(Qt::Vertical);//q graphics view layout
	this->menu = new QGraphicsWidget;//holds the layout


	// initialize the proper buttons
	(this->game_state->is_logged_in()) ? (this->logged_in()) : (this->not_logged_in());//test whether or not the user is logged in to generate the correct menu

	// now iterate through each button and add to the layout
	for (int i = 0, z = this->buttons.size(); i < z; i++) {

		temp = this->scene->addWidget(this->buttons[i]);//add widget to the scene
		this->layout->addItem(temp);//add this widget to the layou
		connect(this->buttons[i], SIGNAL(menu_selection(QString)), this, SLOT(set_menu_option(QString)));//connect the button to this
	}

	// set menu layout as the layout and then add the menu to the scene
	this->menu->setLayout(this->layout);
	this->position();
	this->scene->addItem(this->menu);
}
	
Menu_controller::~Menu_controller() {

	// all items removed from scene -- need to disconnect and call delete later
	// disconnect all items
	this->menu->disconnect();

	for (int i = 0, z = this->buttons.size(); i < z; i++) {
	
		this->buttons[i]->disconnect();
		this->buttons[i]->deleteLater();
	}

	this->menu->deleteLater();
	// delete this->layout;
}

/* INITIALIZER FUNCTIONS TO BUILD THE MENU **/
void Menu_controller::logged_in() {

	// all users, add, remove friend, sort friends scores, sort all scores, list all users, play
	vector<QString>titles;
	vector<QString>messages;

	// initialize all menu options below
	titles.push_back("Show all friends");
	messages.push_back("show_friends");

	titles.push_back("Add Friend");
	messages.push_back("add_friend");

	titles.push_back("Remove Friend");
	messages.push_back("remove_friend");

	titles.push_back("Friends High Scores");
	messages.push_back("friends_high_scores");

	titles.push_back("All High Scores");
	messages.push_back("all_high_scores");

	titles.push_back("Show All Users");
	messages.push_back("show_all_users");

	titles.push_back("Play");
	messages.push_back("play");

	titles.push_back("Exit");
	messages.push_back("exit");

	// create buttons for each menu options
	for (int i = 0, z = titles.size(); i < z; i++)
		this->buttons.push_back(new Button(titles[i], messages[i]));
}

/* SLOTS **/
void Menu_controller::not_logged_in() {

	vector<QString>titles;
	vector<QString>messages;

	// initialize menu options 
	titles.push_back("Show All Users");
	messages.push_back("show_all_users");

	titles.push_back("Add User");
	messages.push_back("add_user");

	titles.push_back("Delete User");
	messages.push_back("delete_user");

	titles.push_back("Login");
	messages.push_back("login");

	titles.push_back("Show All High Scores");
	messages.push_back("all_high_scores");

	titles.push_back("Play");
	messages.push_back("play");

	titles.push_back("Exit");
	messages.push_back("exit");


	// create button widgets
	for (int i = 0, z = titles.size(); i < z; i++) 
		this->buttons.push_back(new Button(titles[i], messages[i]));

}

void Menu_controller::position() {

	int width = this->game_state->get_width(),
		height = this->game_state->get_height();

	int left = width * 0.25,
		top = height * 0.25,
		_width = width * 0.5,
		_height = height * 0.5;

	this->menu->setGeometry(left, top, _width, _height);
}

/* SLOTS */
void Menu_controller::set_menu_option(QString option) {

	this->game_state->set_application(option);
	emit application_update();//call the application_controller to update the game state

}
