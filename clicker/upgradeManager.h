#ifndef UPGRADEMANAGER_H
#define UPGRADEMANAGER_H

#include <rt2d/entity.h>

#include <vector>
#include "upgrade.h"
#include "upgradeBar.h"

class UpgradeManager{
public:
	UpgradeManager(std::vector<UpgradeBar*> upgradeBars,std::vector<Upgrade*> upgrades);
	virtual ~UpgradeManager();
	virtual void update(float deltatime);
private:
	std::vector<UpgradeBar*> upgradeBars = std::vector<UpgradeBar*>(6);
	std::vector<Upgrade*> upgrades = std::vector<Upgrade*>(6);
};

#endif //UPGRADEMANAGER_H