#include <iostream>

#include "user_information/user.hpp"
#include "user_information/read_data.hpp"
#include "user_information/user_management.hpp"

using namespace std;

int main(int argc, char ** argv[]) {


	User_management * management = new User_management();

	User * new_user = new User(43);

	new_user->set_username("Jon");
	new_user->set_year(3200);
	new_user->set_high_score(4400);

	management->add_user(new_user);

	new_user = new User(33);

	new_user->set_username("Jon");
	new_user->set_year(3200);
	new_user->set_high_score(4400);

	management->add_user(new_user);

	new_user = new User(2);

	new_user->set_username("Jon");
	new_user->set_year(3200);
	new_user->set_high_score(4400);
	
	management->add_user(new_user);

	management->add_friend(2, 33);
	management->add_friend(33, 43);

	management->remove_user(44);

	management->load_file("test.qtxt");

	management->add_user(new_user);
	
	delete management;


}