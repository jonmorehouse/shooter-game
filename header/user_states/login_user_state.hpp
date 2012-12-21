#ifndef LOGIN_USER_STATE_HPP
#define LOGIN_USER_STATE_HPP

#include "base_user_management.hpp"

class Login_user_state : public Base_user_management {

	Q_OBJECT

	public:
		Login_user_state(Game_state * game_state);
		~Login_user_state();

	public slots:
		virtual void process(QString message);//will be responsible for logging in the proper user

	private:
		virtual void create_body();//create elements
		void submit(int id);//submits the actual user to the 

};

#endif