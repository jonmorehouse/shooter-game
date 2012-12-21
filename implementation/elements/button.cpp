#include "elements/button.hpp"

using namespace std;

/********* BASE CONSTRUCTOR / DESTRUCTORS *********/
Button::Button(QString title, QString message, QWidget * parent) : title(title), message(message), QPushButton(parent){

	this->setText(this->title);

	connect(this, SIGNAL(clicked()), this, SLOT(response()));

}

Button::~Button() {

	disconnect(this);

}

/* SLOTS */
void Button::response() {

	emit this->menu_selection(this->message);
}

