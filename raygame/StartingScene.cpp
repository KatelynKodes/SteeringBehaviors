#include "StartingScene.h"
#include "Player.h"
#include "Enemy.h"
#include "SpriteComponent.h"

void StartingScene::start()
{
	Player* playerChar = new Player(500, 500, "player", MathLibrary::Vector2(30, 30));
	playerChar->getTransform()->setScale({50,50});

	Enemy* enemyChaser = new Enemy(200, 200, "chaserEnemy", 200, 200, playerChar);
	enemyChaser->getTransform()->setScale({ 50,50 });

	addActor(playerChar);
	addActor(enemyChaser);
}
