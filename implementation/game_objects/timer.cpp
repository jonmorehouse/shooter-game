#include "game_objects/timer.hpp"

using namespace std;//

namespace game {


	Timer::Timer(int interval, QObject * parent) : QTimer(parent) {

		// this needs to connect 
		this->setInterval(interval);//set the parent interval
		connect(this, SIGNAL(timeout()), this, SLOT(controller()));
		this->start();//starts the elements

	}

	Timer::Timer(QObject * parent) : QTimer(parent) {

		this->setInterval(1000);
		connect(this, SIGNAL(timeout()), this, SLOT(controller()));

	}

	Timer::~Timer() {



	}

	void Timer::controller() {//connected to the timeout element

		counter++;

		emit _single();

		if (counter % 2 == 0) emit _double();//emits when counter = 2 or 4

		if (counter % 3 == 0) emit _triple();//emits when it is equal 3

		if (counter == 4) emit _quadruple();

		counter = (counter == 4) ? (0) : (counter);

	}
}