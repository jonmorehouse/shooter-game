#include "game_objects/base_animated_object.hpp"

using namespace std;

game::Base_animated_object::Base_animated_object(Game_state * game_state) : Base_object(game_state) {

	this->images = new Linked_list<QImage>();
	
	
}

game::Base_animated_object::~Base_animated_object() {

	// responsible for removing images

}

void game::Base_animated_object::animation_update() {

	// this is set to a timer in the actual implementation of the objet etc
	this->images->next();//move the images linked_list to the next element

	// validate that we are not working with an empty node
	if (this->images->get_current_node() == NULL) this->images->reset();

	// reset the image
	this->image = this->images->get_current();//.scaled(this->rect.x(), this->rect.y(), Qt::KeepAspectRatio);//returns the current image
	this->rect = this->image.rect();//gets the image rectangle!

	this->update();

}