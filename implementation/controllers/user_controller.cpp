#include "controllers/user_controller.hpp"

using namespace std;

User_controller::User_controller(Game_state * game_state) : Base_controller(game_state) {

	QString application = this->game_state->get_application();

	this->live = true;

	if (application == "add_user") this->current_state = new Add_user_state(game_state);//create a new state

	else if (application == "delete_user") this->current_state = new Delete_user_state(game_state);//

	else if (application == "login") this->current_state = new Login_user_state(game_state);//shows a list of buttons to login to

	else if (application == "all_high_scores") this->current_state = new High_scores_state(game_state, false);//show all high scores for all users

	else if (application == "friends_high_scores") this->current_state = new High_scores_state(game_state, true);//show friends high scores

	else if (application == "show_all_users") this->current_state = new Show_users_state(game_state, false);//show all users

	else if (application == "show_friends") this->current_state = new Show_users_state(game_state, true);//show friends for a user

	else if (application == "add_friend") this->current_state = new Friend_management_state(game_state, true);//add friends

	else if (application == "remove_friend") this->current_state = new Friend_management_state(game_state, false);
	
	else {//application is not yet built or not a part of the user_controller at this time -- return to the main menu

		this->game_state->set_application("menu");
		this->live = false;
		emit application_update();
	}

	// 
	connect(this->current_state, SIGNAL(generate_state_change()), this, SLOT(process_state_change()));

}

User_controller::~User_controller() {

	if (this->live)
		delete this->current_state;//this is responsible for disconnecting itself and then being deleted

}


void User_controller::process_state_change() {//this is processed when we are finished in the application state

	// game state should already be initialized 
	// can put in logic here to account for when the application stays in the same menu
	emit application_update();//this is connected directly to the application_controller

}


