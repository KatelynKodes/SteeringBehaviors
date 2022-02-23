#include "StartingScene.h"
#include "Player.h"
#include "ChaseEnemy.h"

void StartingScene::start()
{
	Player* playerChar = new Player(500, 500, "p", MathLibrary::Vector2(30, 30));
	playerChar->getTransform()->setScale({50,50});

	ChaseEnemy* enemy = new ChaseEnemy(200, 200, "enemy", playerChar, 300);
	enemy->getTransform()->setScale({ 50,50 });

	addActor(playerChar);
	addActor(enemy);
}
