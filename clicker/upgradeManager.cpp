#include "upgradeManager.h"

UpgradeManager::UpgradeManager(){
	ooievaar->addSprite("assets/Upgrade_Button.tga");
	productionLine->addSprite("assets/Upgrade_Button.tga");
	spermBoost->addSprite("assets/Upgrade_Button.tga");
	cursorUp->addSprite("assets/Upgrade_Button.tga");
	conceptieCampagne->addSprite("assets/Upgrade_Button.tga");
	babyBoom->addSprite("assets/Upgrade_Button.tga");
	
	ooievaar->position = Point(0,0);
	productionLine->position = Point(128,0);
	spermBoost->position = Point(256,0);
	cursorUp->position = Point(384,0);
	conceptieCampagne->position = Point(512,0);
	babyBoom->position = Point(640,0);

	this->addChild(ooievaar);
	this->addChild(productionLine);
	this->addChild(spermBoost);
	this->addChild(cursorUp);
	this->addChild(conceptieCampagne);
	this->addChild(babyBoom);
}

UpgradeManager::~UpgradeManager(){
	delete ooievaar;
	delete productionLine;
	delete spermBoost;
	delete cursorUp;
	delete conceptieCampagne;
	delete babyBoom;

}

void UpgradeManager::update(float deltatime) {

}