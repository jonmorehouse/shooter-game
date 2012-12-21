#ifndef GAME_BASE_OBJECT_HPP
#define GAME_BASE_OBJECT_HPP

// project libraries
#include "game_state.hpp"

// c++ libraries
#include <iostream>

// qt libraries
#include <QWidget>
#include <QRect>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QPalette>

namespace game {

	class Base_object : public QWidget {

		Q_OBJECT //this will have signals

		public:
			Base_object(Game_state * game_state, QWidget * parent = 0) ;//want to take in 
			~Base_object();

		public slots://update is connected to timer events
			virtual void keyPressEvent(QKeyEvent *){};//used to pass the keyPressEvent upwards - connected in the game_controller class
			// virtual void update() = 0;//this is updated by the timer event -- responsible for automated movement etc

		signals:
			void collision();//this is emmitted anytime an update happens -- this contacts the controller slots connected

		protected slots://functions -- not slots because they are encapsulated and controlled with other elements 

			void paintEvent(QPaintEvent * event);

		protected:
			QGraphicsScene * scene;//scene for dropping elements on
			Game_state * game_state;//this is the 

			// positional elements
			QPoint position;//this is the current position of the element

			// global elements 
			QImage image;//used to hold an image if necessary for this object
			QRect rect;//rectangle shape -- used for shapes -- could make a QPolygon later?

			// stylistic elements
			QPalette palette;
	};
}


#endif