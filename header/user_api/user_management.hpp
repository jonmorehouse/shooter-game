#ifndef USER_MANAGEMENT_HPP
#define USER_MANAGEMENT_HPP

// project libraries
#include "user.hpp"
#include "read_data.hpp"
#include "save_data.hpp"

// c++ libraries

// qt libraries
#include <QString>

/*
	vector of friend lists
	a vector of int-vectors
	
*/
class User_management {

	public:
		User_management(char * file_name, std::vector<User *> * users, std::vector<std::vector<bool> > * friend_network);
		~User_management();

	public://getter functions
		bool user_exists(unsigned int id) const;
		bool valid_username(QString username) const;

	public://setter functions
		void load_file(QString file_name);//opens a new file after clearing the previous list
		void add_user(User * user);//adds the user to the element
		void remove_user(unsigned int id);//removes this from the list and all friends
		void remove_friend(unsigned int id_1, unsigned int id_2);//removes a friend from both 
		void add_friend(unsigned int id_1, unsigned int id_2);//add a friend to each party

	protected://worker functions
		void update_network();//responsible for updating the network of friends

	private:
		QString file_name;
		std::vector<User *> * users;//vector of all user information -- a list -- each index corresponds to the user id -- for fast lookup
		std::vector<std::vector<bool> > * friend_network;//this is the adjacency list of the elements
};

#endif
