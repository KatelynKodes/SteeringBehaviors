#include "StartingScene.h"
#include "Player.h"
#include "ChaseEnemy.h"

void StartingScene::start()
{
	Player* playerChar = new Player(500, 500, MathLibrary::Vector2(30, 30));
	playerChar->getTransform()->setScale({50,50});

	addActor(playerChar);
}
