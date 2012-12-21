#include "user_api/user_display.hpp"

using namespace std;

User_display::User_display(vector<User *> * users, vector<vector<bool> > * friend_network) : users(users), friend_network(friend_network) {



}

User_display::~User_display() {






}

/*********** PUBLIC GETTER FUNCTIONS ***********/
int User_display::get_length() const {

	int counter = 0;

	for (int i = 0, z = this->users->size(); i < z; i++)
		if ((*this->users)[i])
			counter++;

	return counter;
}

int User_display::get_id(QString username) const {

	for (int i = 0, z = this->users->size(); i < z; i++) {
		
		if ((*this->users)[i]) {

			if ((*this->users)[i]->get_username() == username)
				return (*this->users)[i]->get_id();
		}
	}

	return -1;//--username does not exist
}

User * User_display::get_user(int id) const {


	if ((*this->users)[id] && (*this->users)[id]->get_id() == id)
		return (*this->users)[id];//return the user pointer

	return NULL;


}


/********  WORKER FUNCTIONS *******/
vector<User *> User_display::get_all_users() {

	vector<User *>all_users;//a full list of all users

	for (int i = 0, z = this->users->size(); i < z; i++) {

		if ((*this->users)[i])
			all_users.push_back((*this->users)[i]);
	}

	return all_users;
}

vector<User *> User_display::get_all_scores() {


	vector<User *> all_users = this->get_all_users();//gets all the users

	if (all_users.size() <= 1) return all_users;

	return this->sort_scores(all_users);


}

vector<User *>User_display::get_friends(int id) {

	vector<User *>friends;

	// make sure that the id is even in the range of the vector
	if (unsigned(id) >= this->users->size()) return friends;


	User * user = (*this->users)[id];//current users

	// validate the user exists and is not null
	if (!user) return friends;

	vector<bool>raw_friends = vector<bool>(user->get_friends());


	for (int i = 0, z = raw_friends.size(); i < z; i++)
		if (raw_friends[i] && (*this->users)[i])
			friends.push_back((*this->users)[i]);

	return friends;
}

vector<User *>User_display::get_friends_scores(int id) {//sorts friend based on score

	vector<User *> friends = this->get_friends(id);

	if (friends.size() <= 1) return friends;//no need to sort

	else return this->sort_scores(friends);//returns a sorted list

}

vector<QString> User_display::get_shortest_path(QString username_1, QString username_2) {

	vector<QString> user_path = vector<QString>(3, "TEST USER");

	return user_path;

}


/******* PRIVATE WORKER FUNCTIONS ******/
vector<User *> User_display::sort_scores(vector<User *>users) {

	if (users.size() <= 0) return users;//don't even bother sorting it once

	// responsible for taking the vector of users and sorting based on user high score
	User * temp;//temporary for swapping
	bool flag = false;//

	do {

		flag = true;//initialized to false to ensure we don't loop too many times

		for (int i = 0, z = users.size(); i < (z-1); i++) {

			if (users[i]->get_high_score() > users[i+1]->get_high_score()) {

				flag = false;//need to run the sort again
				temp = users[i];//previous element
				users[i] = users[i+1];//make the left one the right value
				users[i+1] = temp;//make the left value
			}
		}//end for loop

	} while(!flag);//run the sort again if necessary

	return users;
	
}


