#ifndef ENTITY_H
#define ENTITY_H

/**
* Base class for the all game objects.		
*/

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void start();
	virtual void update();
};

#endif