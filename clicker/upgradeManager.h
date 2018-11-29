#ifndef UPGRADEMANAGER_H
#define UPGRADEMANAGER_H

#include <rt2d/entity.h>

#include "ooievaarPlatformUpgrade.h"
#include "productionlineUpgrade.h"
#include "spermBoostUpgrade.h"
#include "conceptieCampagneUpgrade.h"
#include "cursorUpgrade.h"
#include "babyBoomUpgrade.h"

#include <vector>

class UpgradeManager : public Entity{
public:
	UpgradeManager();
	virtual ~UpgradeManager();
	virtual void update(float deltatime);

private:

	OoievaarPlatformUpgrade* ooievaar = new OoievaarPlatformUpgrade();
	ProductionlineUpgrade* productionLine = new ProductionlineUpgrade();
	SpermBoostUpgrade* spermBoost = new SpermBoostUpgrade();
	CursorUpgrade* cursorUp = new CursorUpgrade();
	ConceptieCampagneUpgrade* conceptieCampagne = new ConceptieCampagneUpgrade();
	BabyBoomUpgrade* babyBoom = new BabyBoomUpgrade();
	

};

#endif //UPGRADEMANAGER_H