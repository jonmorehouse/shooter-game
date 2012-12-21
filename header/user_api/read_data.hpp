#ifndef READ_DATA_HPP
#define READ_DATA_HPP

// project libraries
#include "user.hpp"

// qt libraries
#include <QFile>
#include <QTextStream>
#include <QStringList>

//c++ libraries
#include <iostream>
#include <vector>


class Read_data {

	public:
		Read_data(std::vector<User *> * users, QString file_name = "default_database.qtxt");
		~Read_data();

	private:
		void read_users();//
		void read_user(std::vector<QString> current);
		void bad_file_handler();//handler for bad files -- we can extend this later and include our own handler system

	private:
		std::vector<User *> * users;
		QString file_name;
		QFile * file;
		std::vector<QString> lines;

};

#endif
