#ifndef GAME_TIMER_HPP
#define GAME_TIMER_HPP

// project libraries

// qt libraries
#include <QTimer>
#include <QObject>


// c++ libraries
#include <iostream>
/*

	The purpose of this class is to have a single timer which controls other elements based on a fifth / third, half-time timer
*/

/*
QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(1000);

*/

namespace game {

	class Timer : public QTimer {

		Q_OBJECT
		public:	
			Timer(int interval, QObject * parent = 0);
			Timer(QObject * parent = 0);
			~Timer();


		private slots:
			void controller();//this will emit the signals we need

		signals:
			void _single();//single interval
			void _double();//double interval -- emitted from controller
			void _triple();//triple interval -- emitted from controller
			void _quadruple();//4 times as long

		private:
			int counter;//this is the counter element
	};//end class definitoin

}


#endif