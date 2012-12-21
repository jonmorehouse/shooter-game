#include "user_states/friend_management_state.hpp"

using namespace std;

Friend_management_state::Friend_management_state(Game_state * game_state, bool add) : Base_user_management(game_state) {

	this->add = false;
	if (add && this->game_state->is_logged_in()) this->add = true;


	this->create_body();//
}

Friend_management_state::~Friend_management_state() {


}

// PUBLIC SLOTS
void Friend_management_state::process(QString message) {

	if (message == "exit" || message == "menu") return Base_user_state::process(message);

	(this->add) ? (this->add_friends()) : (this->remove_friends());

	Base_user_state::process("menu");//return to the menu	

}

/******** WORKER FUNCTIONS *********/
void Friend_management_state::create_body() {

	Base_user_state::create_body();//create the general button and connect it -- for going back to the main menu
	
	vector<User *>options = (!this->add) ? (this->user_api->user_display->get_friends(this->game_state->get_user()->get_id())) : (this->user_api->user_display->get_all_users());	

	// now loop through all elements

	for (int i = 0, z = options.size(); i < z; i++) {

		if (options[i]->get_id() != this->game_state->get_user()->get_id()) {
		
			this->checkboxes.push_back(new QCheckBox());
			this->checkboxes.back()->setText(options[i]->get_username());
			this->layout->addRow(this->checkboxes.back());	
		}
	}

	QString button_title = (this->add) ? ("Add Friends") : ("Remove Friends");
	this->buttons.push_back(new Button(button_title, "submit"));
	connect(this->buttons.back(), SIGNAL(menu_selection(QString)), this, SLOT(process(QString)));
	this->layout->addRow(this->buttons.back());

	// add main menue button to the layout
	this->layout->addRow(this->buttons.front());

	this->create_layout();

}

void Friend_management_state::remove_friends() {

	for (int i = 0, z = this->checkboxes.size(); i < z; i++) {
		if (this->checkboxes[i]->isChecked())
			this->user_api->user_management->remove_friend(this->game_state->get_user()->get_id(), this->user_api->user_display->get_id(this->checkboxes[i]->text()));
	}

}

void Friend_management_state::add_friends() {

	for (int i = 0, z = this->checkboxes.size(); i < z; i++) {
		if (this->checkboxes[i]->isChecked())
			this->user_api->user_management->add_friend(this->game_state->get_user()->get_id(), this->user_api->user_display->get_id(this->checkboxes[i]->text()));
	}
}
