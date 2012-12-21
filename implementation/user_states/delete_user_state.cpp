#include "user_states/delete_user_state.hpp"

using namespace std;//

Delete_user_state::Delete_user_state(Game_state * game_state) : Base_user_management(game_state) {

	this->flagged_usernames = vector<QString>();//usernames to delete
	this->body->setTitle("Delete User");
	this->create_body();//create the elemenets
}

Delete_user_state::~Delete_user_state() {

	// delete the vector of qcheckboxes here after disconnecting them

}
 
/********* SLOTS ********/
void Delete_user_state::process(QString message) {

	if (message == "exit" || message == "menu")
		return Base_user_state::process(message);

	// else application needs to run to delete the proper users
	for (int i = 0, z = this->checkboxes.size(); i < z; i++)
		if (this->checkboxes[i]->isChecked())//only for checked users
			this->flagged_usernames.push_back(this->checkboxes[i]->text());//send the username to be deleted to the vector


	this->delete_users();//deletes the users

	Base_user_state::process("menu");//call the main menu

}

void Delete_user_state::create_body() {

	Base_user_state::create_body();//add general buttons etc to the layout

	vector<User *>all_users = this->user_api->user_display->get_all_users();//get all the users

	for (int i = 0, z = all_users.size(); i < z; i++) {

		this->checkboxes.push_back(new QCheckBox());//create a new checkbox
		this->checkboxes.back()->setText(all_users[i]->get_username());//set the username
		this->layout->addRow(this->checkboxes.back());
	}

	// create the final button and connect it to be processed
	this->buttons.push_back(new Button("Delete Users", "submit"));
	connect(this->buttons.back(), SIGNAL(menu_selection(QString)), this, SLOT(process(QString)));
	this->layout->addRow(this->buttons.back());

	// add the main menu button
	this->layout->addRow(this->buttons.front());//add the main menu button

	this->create_layout();//actually append the layout to the main screen

}

void Delete_user_state::delete_users() {

	int id;

	for (int i = 0, z = this->flagged_usernames.size(); i < z; i++) {

		id = this->user_api->user_display->get_id(this->flagged_usernames[i]);
		if (id >= 0)
			this->user_api->user_management->remove_user(id);
	}
}

