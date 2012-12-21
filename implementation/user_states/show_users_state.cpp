#include "user_states/show_users_state.hpp"

using namespace std;

Show_users_state::Show_users_state(Game_state * game_state, bool friends_only) : Base_user_display(game_state) {

	this->friends_only = false;

	if (friends_only && this->game_state->is_logged_in()) this->friends_only = true;

	QString title = (this->friends_only) ? ("Friends") : ("All Users");

	this->body->setTitle(title);

	this->create_body();

}

Show_users_state::~Show_users_state() {


}

void Show_users_state::create_body() {

	Base_user_state::create_body();

	vector<User *>users = (this->friends_only) ? (this->user_api->user_display->get_friends(this->game_state->get_user()->get_id())) : (this->user_api->user_display->get_all_users());

	for (int i = 0, z = users.size(); i < z; i++ ) {
		this->elements.push_back(new QLineEdit(users[i]->get_username()));
		this->layout->addRow(this->elements.back());
	}	

	this->layout->addRow(this->buttons.front());

	Base_user_display::create_body();
	this->create_layout();

}

