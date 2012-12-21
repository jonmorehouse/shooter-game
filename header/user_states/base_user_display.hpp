#ifndef BASE_USER_DISPLAY_HPP
#define BASE_USER_DISPLAY_HPP

// we essentially want to create a layout and add the proper elements to it!
#include "base_user_state.hpp"

// qt libraries
#include <QString>

class Base_user_display : public Base_user_state {

	Q_OBJECT

	public:
		Base_user_display(Game_state * game_state);
		~Base_user_display();//delete this element

	protected:
		virtual void create_body();//this will be responsible for calling the line edit readOnly on all elements

		User * user;//current user's elements
		std::vector<QLineEdit *>elements;

};



#endif