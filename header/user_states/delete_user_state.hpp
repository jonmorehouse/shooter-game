#ifndef DELETE_USER_STATE_HPP
#define DELETE_USER_STATE_HPP

#include "base_user_management.hpp"

class Delete_user_state : public Base_user_management {

	Q_OBJECT

	public:
		Delete_user_state(Game_state * game_state);//
		~Delete_user_state();//


	public slots://
		virtual void process(QString message);//--once we click one, need to replace the buttons with a not sure dialog etc .. this can come later

	private:
		virtual void create_body();//create the actual elements
		void delete_users();

	private:
		std::vector<QString>flagged_usernames;//these are the usernames of the elements that need to be deleted

};

#endif