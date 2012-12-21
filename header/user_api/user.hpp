#ifndef USER_HPP
#define USER_HPP

//project dependencies / libraries
#include "list_templates/list_templates"

//c++ dependencies
#include <iostream>
#include <vector>

// QT Libraries
#include <QString>

class User {

	public:
		User(unsigned int id);
		~User();

	public://setter functions
		void set_id(unsigned int id);
		void set_username(QString username);//assumes that this is a valid username
		void set_year(unsigned int year);//assumes that this is a valid year
		void set_high_score(unsigned long high_score);//will check if the high score is greater than the current
		void set_password(QString password);//assumes that the password is hashed / encrypted
		void add_friend(unsigned int id);//assumes that the friend id is legitimate
		void remove_friend(unsigned int id);//removes the id of the friend in this location

	public://getter functions
		void print_friends() const;
		unsigned int get_id() const;
		QString get_username() const;
		unsigned int get_year() const;
		unsigned int get_high_score() const;
		QString get_password() const;
		bool is_friend(unsigned int id) const;//returns whether or not the friend is a member of the list		
		vector<bool> & get_friends();//returns a pointer to the linked list of friends contained here

	private:
		unsigned int id;
		QString username;
		unsigned int year;
		unsigned long high_score;
		QString password;
		vector<bool> friends;

};


#endif
