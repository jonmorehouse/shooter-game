#include "user_states/high_scores_state.hpp"

High_scores_state::High_scores_state(Game_state * game_state, bool friends_only) : Base_user_display(game_state) {

	this->friends_only = false;

	if (this->game_state->is_logged_in() && friends_only) this->friends_only = true;

	QString title = (this->friends_only) ? ("Friends High Scores") : ("All High Scores");
	this->body->setTitle(title);
	this->create_body();
}

High_scores_state::~High_scores_state() {



}

void High_scores_state::create_body() {

	Base_user_state::create_body();//creates the button to go back to the main menu 

	
	vector<User *>users = (this->friends_only) ? (this->user_api->user_display->get_friends_scores(this->game_state->get_user()->get_id())) : (this->user_api->user_display->get_all_scores());
	

	for (int i = 0, z = users.size(); i < z; i++) {

		this->elements.push_back(new QLineEdit(QString::number(users[i]->get_high_score())));
		// QLabel label;
		QString title = QString("%1:").arg(users[i]->get_username());
		this->layout->addRow(tr(title.toLocal8Bit().data()), this->elements.back());

	}
	
	this->layout->addRow(this->buttons.front());//add the exit button in to this menu


	Base_user_display::create_body();//sets all qline edits to read only!

	this->create_layout();

	
}