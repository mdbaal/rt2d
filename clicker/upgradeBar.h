#ifndef UPGRADEBAR_H
#define UPGRADEBAR_H

#include <rt2d/entity.h>
#include "upgradeMini.h"

class UpgradeBar : public Entity{
public:
	UpgradeBar();
	virtual ~UpgradeBar();
	virtual void update(float deltatime);

	void addMini();
private:

};

#endif //UPGRADEBAR_H