#include "user_api/save_data.hpp"

using namespace std;

Save_data::Save_data(vector<User *> * users, QString file_name) : users(users), file_name(file_name) {

	this->file = new QFile(file_name);
	this->file->open(QFile::WriteOnly | QFile::Truncate);

	this->save_users();

}

Save_data::~Save_data() {

	this->file->close();
	delete this->file;
}

void Save_data::save_users() {//responsible for saving all users to the file that is open

	QTextStream out(this->file);

	int counter = 0;

	for (int i = 0, z = this->users->size(); i < z; i++)
		if ((*this->users)[i])
			counter++;

	out << counter << endl;

	for (int i = 0, z = this->users->size(); i < z; i++)
		if ((*this->users)[i])
			this->save_user((*this->users)[i], out);

}

void Save_data::save_user(User * user, QTextStream & out) {

	vector<bool> friends = user->get_friends();
	// print initial elements -- as documented in project rubric - refer to methods in user.hpp

	out << user->get_id() << endl;
	out << "\t" << user->get_username() << endl;
	out << "\t" << user->get_year() << endl;
	out << "\t" << user->get_high_score() << endl;

	// intialize the friend list with a tab
	out << "\t";

	for (int i = 1, z = friends.size(); i < z; i++) {

		if (friends[i]) {
			out << i << "\t";
		}
	}

	out << endl;
}