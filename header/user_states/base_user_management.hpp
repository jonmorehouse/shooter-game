#ifndef BASE_USER_MANAGEMENT_HPP
#define BASE_USER_MANAGEMENT_HPP

// project libraries
#include "base_user_state.hpp"

// QT Libraries
#include <QCheckBox>

class Base_user_management : public Base_user_state {

	Q_OBJECT

	public:
		Base_user_management(Game_state * game_state);
		~Base_user_management();

	protected:
		virtual bool validate(){};//uses the user_management module to validate the elements
		virtual void submit(){};//this submits the current object's state to the proper elements

	protected:
		User * user;//this is the current element 
		std::vector<QLineEdit *>form_elements;//form elements
		std::vector<QCheckBox *>checkboxes;//checkboxes -- not used everywhere but in 3 different classes

};

#endif