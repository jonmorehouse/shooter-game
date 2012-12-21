#ifndef SAVE_DATA_HPP
#define SAVE_DATA_HPP

// project dependencies
#include "user.hpp"

// c++ libraries
#include <vector>
#include <iostream>

// qt libraries
#include <QFile>
#include <QTextStream>


/**

	This class relies on QT for file input and output
	This is hardcoded to store the database file from the assignment directions
*/

class Save_data {

	public:
		Save_data(std::vector<User *> * users, QString file_name = "default_database.qtxt");//responsible for opening file
		~Save_data();//

	private:
		void save_users();//loops through all users
		void save_user(User * user, QTextStream & out);//writes an individual user to the file

	private:
		std::vector<User *> * users;
		QString file_name;
		QFile * file;

};

#endif