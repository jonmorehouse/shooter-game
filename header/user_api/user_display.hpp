#ifndef USER_DISPLAY_HPP
#define USER_DISPLAY_HPP

// project libraries
#include "list_templates/list_templates"
#include "user.hpp"//only dependency is the user element
//maybe include a sorting utility? -- maybe a binary search tree?

class User_display {

	public:
		User_display(std::vector<User *> * users, std::vector<std::vector<bool> > * friend_network);//
		~User_display();//deletes all elements local to this class

	public: //basic getters
		int get_length() const;//returns the length of valid users
		int get_id(QString username) const;//returns the user id by searching based on usernames
		User * get_user(int id) const;//returns a pointer to the proper user id

		// user vectors
		std::vector<User *>get_all_users();//returns all usernames -- not sorted -- can iterate through
		std::vector<User *>get_friends(int id);//this is the list of friends -- not indexed by id
		std::vector<User *>get_friends_scores(int id);//returns all users sorted on score
		std::vector<User *>get_all_scores();//returns all usernames based upon sorted scores

		// individual tools
		std::vector<QString>get_shortest_path(QString user_1, QString user_2);//returns usernames only

	public://basic sorters


	private:
		std::vector<User *> * users;
		std::vector<std::vector<bool> > * friend_network;

	private://worker functions
		std::vector<User *> sort_scores(std::vector<User *>);

};

#endif