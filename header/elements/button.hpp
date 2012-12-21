#ifndef BUTTON_HPP
#define BUTTON_HPP

// C++ LIBRARIES / C LIBRARIES
#include <iostream>

// project libraries
#include "game_state.hpp"//used for game state elements -- will be responsible for changing the game elements when a button is clicked

// qt libraries
#include <QPushButton> //used for all buttons
#include <QString>

/*
	This is the parent class for button implementations in this project
	Will be responsible for just a button -- different buttons = different classes so that we can update the proper game_state with different clicks
	These will be pushed into layouts later -- can be layouts from the menu etc
*/

class Button : public QPushButton {

	Q_OBJECT

	public://public constructors / destructors

		Button(QString title, QString message, QWidget *parent = 0);//message corresponds to what this button will send to the calling view
		~Button();

	public slots://slots responsible for calling the game_controller update method to change the state of the application
		void response();//responsible for grabbing the button

	signals:
		void menu_selection(QString selection);//this is the signal that is called when a menu button is selected

	private:
		QString title,//title that the user will see
			message;//message the application understands -- this goes back to the game_state application
		
};


#endif