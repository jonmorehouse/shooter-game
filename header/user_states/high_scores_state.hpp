#ifndef HIGH_SCORES_STATE_HPP
#define HIGH_SCORES_STATE_HPP

#include "base_user_display.hpp"
#include <QLabel>

class High_scores_state : public Base_user_display {

	public:
		High_scores_state(Game_state * game_state, bool user_only);
		~High_scores_state();//deletion method for this element

	protected:
		virtual void create_body();//responsible for creating all elements

	private:
		bool friends_only;



};

#endif