#include "user_api/read_data.hpp"

using namespace std;

Read_data::Read_data(vector<User *> * users, QString file_name) : users(users), file_name(file_name) {


	this->file = new QFile(this->file_name);

	if (!this->file->open(QIODevice::ReadOnly | QIODevice::Text)) {
		this->bad_file_handler();
		return;
	}

	QTextStream in(this->file);

	while(!in.atEnd()) {

		QString current_line = in.readLine();
		this->lines.push_back(current_line);
	}
	this->read_users();//will add the users to the Linked_list of users -- if there is an error will print a message

}	

Read_data::~Read_data() {

	this->file->close();//close file handler
	delete this->file;//delete the file handlers

}

void Read_data::read_users() {

	int length = this->lines.size();

	if (length == 0) return;

	if ((length -1) % 5 != 0) {//bad file -- the lines are not in order!
		this->bad_file_handler();//bad file call the handler here
		return;
	}

	// file is good
	vector<QString> temp;

	for (int i = 1; i < this->lines.size(); i++) {

		temp.push_back(this->lines[i]);//push the current line to the back

		if (temp.size() == 5) {
			this->read_user(temp);//read through the user data
			temp.clear();
		}
	}

}


void Read_data::read_user(vector<QString> current) {//this takes in a qstring list that is of size 6


	User * new_user = new User(current[0].toInt());

	QStringList friends = current[4].split("\t", QString::SkipEmptyParts);//be sure to split the string and remove the tabs

	new_user->set_username(current[1].split("\t", QString::SkipEmptyParts)[0]);//set username for the current username
	new_user->set_year(current[2].toInt());//set year for the inputted username
	new_user->set_high_score(current[3].toLong());//set high score

	// add each friend to the user's friend list
	for (int i = 0, z = friends.size(); i < z; i++) {

		if ((*this->users)[i]) {

			new_user->add_friend(i);//responsible for resizing as necessary
			(*this->users)[i]->add_friend(new_user->get_id());//

		}
	}

	// add the user into the vector of elements
	if (this->users->size() <= new_user->get_id())
		this->users->resize(new_user->get_id() + 1, NULL);

	(*this->users)[new_user->get_id()] = new_user;//add the element into the list
}

void Read_data::bad_file_handler() {
	
	cout << "This file could not be opened. Please restart the application with a new file or manually add all users." << endl;

}
