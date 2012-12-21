#ifndef ADD_USER_STATE_HPP
#define ADD_USER_STATE_HPP

// project libraries
#include "base_user_management.hpp"

/*
	Note this class was originally virtually inherited
	However, Q_MOC does not allow virtual inheritance from Q_OBJECTS 
*/

class Add_user_state : public Base_user_management {

	Q_OBJECT 
	
	public:
		Add_user_state(Game_state * game_state);
		~Add_user_state();

	public slots:
		virtual void process(QString message);//will respond to the logic and will create the proper messages or signal completion

	private:
		virtual void create_body();//overwrites the parent create body element if necessary
		virtual bool validate();//will ensure that the user is valid--using user_management methods
		virtual void submit();//inputs the users to be added to the system

};

#endif