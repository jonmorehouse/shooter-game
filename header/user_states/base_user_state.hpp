#ifndef USER_STATE_BASE_HPP
#define USER_STATE_BASE_HPP

// project libraries
#include "user_api/user.hpp"
#include "user_api/user_api.hpp"
#include "game_state.hpp"

// elements
#include "elements/button.hpp"

// c++ libraries
#include <iostream>

// qt libraries
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsLinearLayout>//layout for holding all elements
#include <QGraphicsWidget>//widget that is put on the screen -- can be positioned and move etc
#include <QFormLayout>
#include <QGroupBox>


class Base_user_state : public QGraphicsView {

	Q_OBJECT
	
	public://constructors
		Base_user_state(Game_state * game_state);
		~Base_user_state();

	protected://
		virtual QRect get_position();//can be overridden in any base element
		virtual void create_body();//responsible for creating the correct elements and adding them to the correct places
		virtual void create_layout();//this is responsible for adding the proper elements etc to the qformlayout and setting the body etc

	public slots:
		virtual void process(QString message);//responsible for processing the elements

	signals:
		void generate_state_change();//this is emitted by the current class to signal user_controller to change to the correct elementa

	protected:
		// state wide
		Game_state * game_state;//game state place holder
		QGraphicsScene * scene;//scene which everything is drawn on for this 
		User_api * user_api;//

		// element containers
		std::vector<Button *>buttons;//holds the buttons -- buttons are elements that generate signals / slots
		std::vector<QWidget *>elements;//these are the elements that go inside form -- not necessarily responsible for signalling unless specified later

		// body elements
		QGroupBox * body;//body element that is the parent of the form layout (remember form->setLayout())
		QFormLayout * layout;//this is layout for the form -- good for adding rows etc		
};

#endif

