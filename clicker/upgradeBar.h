#ifndef UPGRADEBAR_H
#define UPGRADEBAR_H

#include <rt2d/entity.h>
#include "upgradeMini.h"

class UpgradeBar : public Entity{
public:
	UpgradeBar();
	virtual ~UpgradeBar();
	virtual void update(float deltatime);
private:

};

#endif //UPGRADEBAR_H