#include "StartingScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h";
#include "CircleCollider.h"
#include "AABBCollider.h"

void StartingScene::start()
{
	m_playerChar = new Player(500, 500, "p", MathLibrary::Vector2(30, 30));
	m_playerChar->getTransform()->setScale({50,50});
	CircleCollider* playerCollider = new CircleCollider(25, m_playerChar);
	m_playerChar->setCollider(playerCollider);
	addActor(m_playerChar);
}
