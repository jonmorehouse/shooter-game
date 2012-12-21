#ifndef SHOW_USERS_STATE_HPP
#define SHOW_USERS_STATE_HPP

// project libraries
#include "base_user_display.hpp"

class Show_users_state : public Base_user_display {

	public:
		Show_users_state(Game_state * game_state, bool friends_only);
		~Show_users_state();

	protected:
		virtual void create_body();


	private:
		bool friends_only;//whether or not to only show for friends


};

#endif