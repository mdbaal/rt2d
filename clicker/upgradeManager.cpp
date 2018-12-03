#include "upgradeManager.h"

UpgradeManager::UpgradeManager(std::vector<UpgradeBar*> upgradeBars, std::vector<Upgrade*> upgrades) {
	this->upgradeBars = upgradeBars;
	this->upgrades = upgrades;
}

UpgradeManager::~UpgradeManager(){

}

void UpgradeManager::update(float deltatime) {

}