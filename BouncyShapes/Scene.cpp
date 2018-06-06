#include "Scene.h"

void Scene::insertGameObject(std::unique_ptr<GameObject>& object)
{
	_gameObjects.push_back(std::move(object));
}

void Scene::Update(double deltaTime)
{

	for (auto& object : _gameObjects)
	{
		object->setLocation(MPoint2F{ object->getLocation().x + object->getStart().x, object->getLocation().y + object->getStart().y });
	}
}

void Scene::Draw(ID2D1HwndRenderTarget & target)
{
	for (auto& object : _gameObjects)
	{
		auto size = target.GetSize();// width = 1424, height = 720

		// if the object hits the edge, change the direction
		if (object->getLocation().x >= size.width) {
			object->setStartX(-1 * (object->getStart().x));
		}
		if (object->getLocation().x <= 0) {
			object->setStartX(-1 * (object->getStart().x));
		}
		if (object->getLocation().y >= size.height) {
			object->setStartY(-1 * (object->getStart().y));
		}
		if (object->getLocation().y <= 0) {
			object->setStartY(-1 * (object->getStart().y));
		}

		const auto& renderer = object->getRenderer();
		renderer.Render(target, object->getLocation());
	}
	

}



