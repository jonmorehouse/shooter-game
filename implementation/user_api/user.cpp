#include "user_api/user.hpp"

using namespace std;

User::User(unsigned int id) : id(id)  {

	this->friends = vector<bool>(10, false);
	this->high_score = 0;
}

User::~User() {


}

void User::print_friends() const{

	for (int i = 0, z = this->friends.size(); i < z; i++)
		if (this->friends[i])
			cout << i << endl;

	cout << "END USER" << endl;

}
/*************** SETTER FUNCTIONS ***********/
void User::set_id(unsigned int id) {

	this->id = id;

}


void User::set_username(QString username) {

	this->username = username;

}

void User::set_year(unsigned int year) {

	this->year = year;

}

void User::set_high_score(unsigned long high_score) {

	this->high_score = high_score;
}

void User::set_password(QString password) {

	this->password = password;

}

void User::add_friend(unsigned int id) {//assumes that the friend id exists

	if (this->get_id() == id) return;
	
	if (id >= this->friends.size())
		this->friends.resize(id + 1, false);

	this->friends[id] = true;

}

void User::remove_friend(unsigned int id) {

	if (id <= this->friends.size())
		this->friends[id] = false;
}

/**************** GETTER FUNCTIONS **************/

unsigned int User::get_id() const {

	return this->id;
}

QString User::get_username() const {

	return this->username;

}

unsigned int User::get_year() const{

	return this->year;
}

unsigned int User::get_high_score() const{

	return this->high_score;
}

QString User::get_password() const {

	return this->password;
}

bool User::is_friend(unsigned int id) const {

	if (id < this->friends.size() && this->friends[id])
		return true;

	return false;

}


vector<bool> & User::get_friends() {

	return this->friends;
}

