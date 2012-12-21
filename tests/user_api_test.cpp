#include <iostream>
#include <vector>

#include "user_api/user_api.hpp"
#include <QString>

using namespace std;

void all_user_test(User_api * user_api) {

	vector<User *> users = user_api->user_display->get_all_users();
	vector<User *> all_scores = user_api->user_display->get_all_scores();
	
	for (int i = 0, z = users.size(); i < z; i++)
		cout << users[i]->get_username().toUtf8().constData() << endl;

}

void individual_user_test(User_api * user_api) {

	user_api->user_management->add_friend(5, 14);
	user_api->user_management->add_friend(14, 500);//seems to be working okay right now

}


int main(int argc, char ** argv) {

	User_api * user_api = new User_api();

	// all_user_test(user_api);

	individual_user_test(user_api);//




	delete user_api;

}