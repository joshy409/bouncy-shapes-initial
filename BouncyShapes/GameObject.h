#pragma once

#include <memory>
#include "GeometryPrimitives.h"
#include "IRenderer.h"

class GameObject {
public:
	GameObject(std::shared_ptr<IRenderer> renderer, MPoint2F location, Start2F start);

	const IRenderer& getRenderer();
	const MPoint2F& getLocation();
	const Start2F& getStart();

	
	//added
	void setLocation(MPoint2F);
	void setStartX(float);
	void setStartY(float);

	


private:
	std::shared_ptr<IRenderer> _rendererPtr;
	MPoint2F _location;
	Start2F _start;
	
};