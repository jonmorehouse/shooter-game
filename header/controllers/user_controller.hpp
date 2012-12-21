#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

// project libraries
#include "base_controller.hpp"
#include "user_states/base_user_state.hpp"
#include "user_states/add_user_state.hpp"
#include "user_states/delete_user_state.hpp"
#include "user_states/login_user_state.hpp"
#include "user_states/high_scores_state.hpp"
#include "user_states/show_users_state.hpp"
#include "user_states/friend_management_state.hpp"

/**
	This controller is responsible for updating the game menu based upon what the gamestate change happens
	This is instantiated from the application_controller
	Will instantiate application_states
**/

class User_controller : public Base_controller {

	Q_OBJECT
	
	public:
		User_controller(Game_state * game_state);
		~User_controller();

	public slots:
		void process_state_change();

	private:
		Base_user_state * current_state;//will be add user, delete user etc
		bool live;


};

#endif