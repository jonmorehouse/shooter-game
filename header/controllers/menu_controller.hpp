#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

// C++ dependencies
#include <vector>


// project dependencies
#include "base_controller.hpp"

/*

	This menu controller is useful for initializing all of the controller functions 
		1.) check if user is logged on / off and generate the correct menu
		2.) When a user clicks, this application is responsible for calling the application controller to update the entire application
		3.) Updates the game state method
*/

class Menu_controller : public Base_controller {

	Q_OBJECT
	
	public:
		Menu_controller(Game_state * game_state);
		~Menu_controller();

	protected slots://slots that will be responsible for click events
		void set_menu_option(QString option);//this is the slot that is responsible for handling button clicks on the menu

	private:
		void logged_in();//creates the proper menu for logged in person
		void not_logged_in();//creates the menu for this element
		void position();
		
	private://variables
		std::vector<Button *>buttons;//buttons are owned by both the layout and scene
		QGraphicsLinearLayout * layout;//layout is the form layout that owns the buttons
		QGraphicsWidget * menu;// this is the menu widget that owns the layout
};

#endif