#include "user_states/login_user_state.hpp"

Login_user_state::Login_user_state(Game_state * game_state) : Base_user_management(game_state) {

	this->body->setTitle("Login");
	this->create_body();

} 


Login_user_state::~Login_user_state() {




}

void Login_user_state::process(QString message) {

	if (message == "exit" || message == "menu") return Base_user_state::process(message);

	// else we were given a username
	int id = this->user_api->user_display->get_id(message);

	if (id <= 0) return;//do nothing

	else this->submit(id);

	Base_user_state::process("menu");

}

void Login_user_state::create_body() {

	Base_user_state::create_body();

	vector<User *> users = this->user_api->user_display->get_all_users();

	for (int i = 0, z = users.size(); i < z; i++) {

		this->buttons.push_back(new Button(users[i]->get_username(), users[i]->get_username()));//
		connect(buttons.back(), SIGNAL(menu_selection(QString)), this, SLOT(process(QString)));//add the button to the layout
		this->layout->addRow(this->buttons.back());//add the button to the layout
	}

	this->layout->addRow(this->buttons.front());

	this->create_layout();

}

void Login_user_state::submit(int id) {

	//submits the user

	User * user = this->user_api->user_display->get_user(id);//

	this->game_state->set_user(user);//set the actual user

}
