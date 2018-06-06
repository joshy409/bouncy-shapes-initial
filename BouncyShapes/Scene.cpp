#include "Scene.h"

void Scene::insertGameObject(std::unique_ptr<GameObject>& object)
{
	_gameObjects.push_back(std::move(object));
}

void Scene::Update(double deltaTime)
{
	//TODO
	for (auto& object : _gameObjects)
	{
		
		auto currentx = object->getLocation().x;
		auto currenty = object->getLocation().y;
		auto startx = object->getStart().x;
		auto starty = object->getStart().y;

		if (currentx >= 1424) {
			object->setStartX(-1*(startx));
		}
		if (currentx <= 0) {
			object->setStartX(-1*(startx));
		}
		if (currenty >= 720) {
			object->setStartY(-1*(starty));
		}
		if (currenty <= 0) {
			object->setStartY(-1*(starty));
		}
		startx = object->getStart().x;
		starty = object->getStart().y;

		object->setLocation(MPoint2F{ currentx + startx, currenty + starty });		
	}
}

void Scene::Draw(ID2D1HwndRenderTarget & target)
{
	for (auto& object : _gameObjects)
	{
		const auto& renderer = object->getRenderer();
		renderer.Render(target, object->getLocation());
	}
	//auto a = target.GetSize();// width = 1424, height = 720
}



