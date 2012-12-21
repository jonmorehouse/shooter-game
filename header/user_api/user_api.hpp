#ifndef USER_API_HPP
#define USER_API_HPP

// cpp libraries



// project libraries
#include "utilities.hpp"
#include "user_display.hpp" // does not extend anything
#include "user_management.hpp" // does not extend anything


class User_api {

	public:
		User_api(char * file_name = "database.qtxt");//responsible for adding the correct elements together
		~User_api();

	public://interfaces to the other classes that compose this
		User_management * user_management;//setter functions
		User_display * user_display;//getter functions
		
	public://the only 
		
		std::vector<User *> * users;//vector of all friends accessible around the application
		std::vector<std::vector<bool> > * friend_network;//network of friends 

};	

#endif