#ifndef FRIEND_MANAGEMENT_STATE_HPP
#define FRIEND_MANAGEMENT_STATE_HPP
	
// need a process segment
// need a submission segment
#include "base_user_management.hpp"

#include <QCheckBox>

class Friend_management_state : public Base_user_management {


	public:
		Friend_management_state(Game_state * game_state, bool add);//constructor
		~Friend_management_state();//destructor

	public slots:
		virtual void process(QString message);//takes in a string for submit or menu 

	private://worker functions
		virtual void create_body();//responsible for creating the body elements for this 		
		void remove_friends();//responsible for removing users
		void add_friends();//add friends

	private:

		std::vector<QCheckBox *>checkboxes;//checkboxes for the elements
		bool add;//if false we will assume to remove a friend

};

#endif