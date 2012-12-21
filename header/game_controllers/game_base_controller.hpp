#ifndef GAME_BASE_CONTROLLER_HPP
#define GAME_BASE_CONTROLLER_HPP

/*

	Class Responsibilities
		1.) extends qgraphicsview
		2.) initializes a timer  that all elements can use
		3.) gives application state signal -- level up, life down 
		4.) 
		
*/

// project libraries
#include "game_state.hpp"
#include "list_templates/list_templates.hpp"
#include "utilities.hpp"

// QT Libraries
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>
#include <QRect>
#include <QImage>

// c libraries
#include <vector>

namespace game {

	class Game_base_controller : public QGraphicsView {

		Q_OBJECT

		public:
			Game_base_controller(Game_state * game_state);
			~Game_base_controller();//responsible for disconnecting and deleting all elements at this point			

		public slots:
			// virtual void collision_response(QString message) = 0;//this is sent by any child when there is a collision
			// virtual void update() = 0;//used to update -- this is a slot so that it can be called by other siblings
			virtual void keyPressEvent(QKeyEvent * event);//used to recieve key presses

		signals:
			void keyPress(QKeyEvent *);
			void level_up();//used to level up the game_controller
			void lose_life();//signal to lose a life

		protected://data structures

			// master structure elements
			Game_state * game_state;//global game state etc -- may not be necessary
			QGraphicsScene * scene;//this is the global scene that all objects are put on!			
			QTimer * timer;//this is the universal timer -- will be connected to different objects as we go

			// customization of object variables
			int timer_interval;//this is how often the timer signals			

			// positional variables
			QRect boundaries;//these are the coordinates that the object can live in
			QPoint position;//x / y of the current_position

			// object variables
			QRect rect;

			// 

	};
}


#endif