#include "user_api/user_api.hpp"

using namespace std;

User_api::User_api(char * file_name) {

	// responsible for initialize all of the accessor elements
	this->users = new vector<User *>(10, NULL);//create the new vector element
	this->friend_network = new vector<vector<bool> >(10, vector<bool>(10, false));

	// create proper objects for access from outside the api
	this->user_management = new User_management(file_name, this->users, this->friend_network);//responsible for initializing all list elements and users
	this->user_display = new User_display(this->users, this->friend_network);

}

User_api::~User_api() {

	// responsible for clearing the user_management elements
	delete this->user_display;//should only delete user_display elements
	delete this->user_management;//responsible for saving to the user_data file database.qtxt

	// for_each is not application
	for_each(this->users->begin(), this->users->end(), utilities::delete_ptr());//delete each user
	this->friend_network->erase(this->friend_network->begin(), this->friend_network->end());//erase all elements
	delete this->friend_network;//delete the friend_network

}

