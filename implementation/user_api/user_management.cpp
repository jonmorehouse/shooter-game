#include "user_api/user_management.hpp"

using namespace std;


User_management::User_management(char * file_name, vector<User *> * users, vector<vector<bool> > * friend_network) : file_name(QString(file_name)), users(users), friend_network(friend_network) {

	// read proper data from the file
	Read_data read_data(this->users, this->file_name);//generate the data

	// update the friend networks
	this->update_network();

}

User_management::~User_management() {

	Save_data save(this->users, this->file_name);//save all users to a file
}

/********* PROTECTED FUNCTIONS *******/

void User_management::update_network() {//this will be responsible for looping through each user and then updating the adjacency list


	if (this->friend_network->size() != this->users->size()) this->friend_network->resize(this->users->size());

	for (int i = 0, z = this->users->size(); i < z; i++) {
		
		if ((*this->users)[i])
			(*this->friend_network)[i] = vector<bool>((*this->users)[i]->get_friends());//((*this->users)[i]->get_friends());

	}
}

/********** PUBLIC SETTER FUNCTIONS *************/
void User_management::load_file(QString file_name) {

	// delete all users
	this->users->erase(this->users->begin(), this->users->end());
	this->friend_network->erase(this->friend_network->begin(), this->friend_network->end());

	// set file name and then load the data again
	this->file_name = file_name;

	// read data
	Read_data read_data(this->users, file_name);

}

void User_management::add_user(User * user) {//needs to resize the users vector if necessary and set the index to the proper element

	// ensure that the vector is large enough
	if (user->get_id() >= this->users->size()) {
		this->users->resize(user->get_id() + 1, NULL);
	}

	// add the user id ot the users list
	(*this->users)[user->get_id()] = user;//add the pointer of the user to this vector to be maintained

	// now need to make sure that all friends are equal
	vector<bool> temp_friends = user->get_friends();

	for (int i = 0, z = temp_friends.size(); i < z; i++) {

		if (temp_friends[i])
			this->add_friend(i, user->get_id());
	}

	// update the friend network now!
	this->update_network();

}

void User_management::remove_user(unsigned int id) {

	if (!this->user_exists(id)) return;//make sure the user exists

	//we know the user exists
	User * removal = (*this->users)[id];

	vector<bool>friends = removal->get_friends();

	for (int i = 0, z = friends.size(); i < z; i++)
		if (friends[i])
			this->remove_friend(id, i);

	(*this->users)[id] = NULL;
	delete removal;
}

void User_management::add_friend(unsigned int id_1, unsigned int id_2) {

	if (!this->user_exists(id_1) || !this->user_exists(id_2)) return;//make sure that both users exist

	(*this->users)[id_1]->add_friend(id_2);//user class checks for duplicates
	(*this->users)[id_2]->add_friend(id_1);

}

void User_management::remove_friend(unsigned int id_1, unsigned int id_2) {

	if (!this->user_exists(id_1) || !this->user_exists(id_2)) return;//make sure that both users exist

	(*this->users)[id_1]->remove_friend(id_2);//user class makes sure this is all valid
	(*this->users)[id_2]->remove_friend(id_1);
	
}


/********** PUBLIC TESTER FUNCTIONS -- FOR ADDING VALID USERS *********/

bool User_management::user_exists(unsigned int id) const {

	if (id < this->users->size() && (*this->users)[id] != NULL) return true;

	return false;

}

bool User_management::valid_username(QString username) const {


	for (int i = 0, z = this->users->size(); i < z; i++) {
		if ((*this->users)[i])
			if ((*this->users)[i]->get_username() == username) 
				return false;

	}

	return true;
}


