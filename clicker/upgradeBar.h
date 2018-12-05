#ifndef UPGRADEBAR_H
#define UPGRADEBAR_H

#include <rt2d/entity.h>
#include <vector>
#include <string>
#include "upgradeMini.h"

class UpgradeBar : public Entity{
public:
	UpgradeBar(std::string sprite);
	virtual ~UpgradeBar();
	virtual void update(float deltatime);

	void addMini();
private:
	std::vector<UpgradeMini*> minis = std::vector<UpgradeMini*>();
	std::string _sprite = "";
};

#endif //UPGRADEBAR_H