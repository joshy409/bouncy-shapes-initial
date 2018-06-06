#include "GameObject.h"

GameObject::GameObject(std::shared_ptr<IRenderer> renderer, MPoint2F location, Start2F start)
	: _rendererPtr(renderer), _location(location), _start(start)
{
}

const IRenderer & GameObject::getRenderer()
{
	return *_rendererPtr;
}

const MPoint2F & GameObject::getLocation()
{
	return _location;
}

const Start2F & GameObject::getStart()
{
	return _start;
}

//added
void GameObject::setLocation(MPoint2F newLoc)
{
	_location = newLoc;
}

void GameObject::setStartX(float X)
{
	_start.x = X;
}

void GameObject::setStartY(float Y)
{
	_start.y = Y;
}


