#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

// project libraries
#include "utilities.hpp"
#include "user_api/user.hpp"
#include "user_api/user_api.hpp"
#include "game_objects/timer.hpp"

// QT LIBRARIES -- these include any that are not included in the project libraries
#include <QtGui>
#include <QGraphicsScene>


/** Class Responsibilities
	
	1.) This class is responsible for holding the game state of the entire game
	2.) This class will be responsible for holding score, color, speed, varaibles, points, lives and state
	3.) Contains a hash table of data and setters / getters
	4.) Contains a hash table of menu options! 
	5.) Will hold the currently logged in user if it exists / id etc

*/
/**

	1.) IMPLEMENTATION -- THIS SHOULD BE A SINGLETON
	2.) Dictionary -- this will hold the game menus
		-	game_state_changed - boolean
	3.) Hold reference to the scene / viewport / max_height / width
		-	getter functions for all of these as well

	4.)	Game data dictionary -- score, level points etc
	5.) Current user data -- includes the user etc / friends etc
*/

class Game_state {

	public:
		Game_state(QGraphicsScene * scene, User_api * user_api, QApplication * application, int height, int width);//
		~Game_state();//

	public://basic application elements

		QGraphicsScene * get_scene() const;//returns the scene that is currently being used
		User_api * get_user_api() const;//returns the user_management
		User * get_user() const;//returns a point to the user
		QString get_application() const;//returns the current state -- game, add_user etc
		QApplication * get_window() const;//returns access to the main window
		int get_width() const;//returns width of the entire screen
		int get_height() const;//returns height of the screen
		bool is_logged_in() const;

	public:	//game only elements
		game::Timer * get_timer() const;//returns the timer
		unsigned int get_update_interval() const;
		unsigned int get_lives() const;
		unsigned int get_score() const;
		unsigned int get_level() const;


	public://setter functions
		void set_timer(game::Timer * timer);//input the timer
		void set_timer_interval(int interval);//change the application speed
		void set_application(QString state);//will set the state to the given element and update the game_state_changed class
		void set_user(User * user);

	private://variable section

		QGraphicsScene * scene;//this is the scene that everything gets drawn on
		User_api * user_api;//this is the user api to be used throughout the application
		QApplication * application;//
		int height, width;//size / width of the screen 

		QString current_application;//current
		bool game_state_changed;
		bool logged_in;//whether or not the user is logged in currently
		User * user;//currently logged in users

	private://game application elements
		game::Timer * timer;
		unsigned int update_interval;//this is going to be how fast the base update occurs
		unsigned int level;//current level
		unsigned int score;//this is the score element
		unsigned int lives;//number of lives available


};

#endif

