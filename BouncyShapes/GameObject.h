#pragma once

#include <memory>
#include "GeometryPrimitives.h"
#include "IRenderer.h"

class GameObject {
public:
	GameObject(std::shared_ptr<IRenderer> renderer, MPoint2F location, Start2F start);

	const IRenderer& getRenderer();
	const MPoint2F& getLocation();
	
	//added
	const Start2F& getStart();
	void setLocation(MPoint2F);
	void setStartX(float);
	void setStartY(float);

	


private:
	std::shared_ptr<IRenderer> _rendererPtr;
	MPoint2F _location;

	// this is a struct with 2 floats x,y. x,y determines their start direction and speed
	Start2F _start;
	
};