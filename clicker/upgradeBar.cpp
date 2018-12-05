#include "upgradeBar.h"

UpgradeBar::UpgradeBar(std::string sprite){
	this->_sprite = sprite;
}

UpgradeBar::~UpgradeBar(){
	for (int i = 0; i < minis.size(); i++) {
		removeChild(minis[i]);
		delete minis[i];
		minis[i] = nullptr;
	}
	minis.clear();

}
void UpgradeBar::update(float deltatime) {

}
void UpgradeBar::addMini() {
	if (minis.empty()) {
		UpgradeMini* m = new UpgradeMini();
		m->addSprite(_sprite);
		m->position = Point(-96, 0);
		this->addChild(m);
		minis.push_back(m);
	}
	else if(minis.size() < 7) {
		UpgradeMini* m = new UpgradeMini();
		m->addSprite(_sprite);
		m->position = Point(minis.back()->position.x + 32, 0);
		this->addChild(m);
		minis.push_back(m);
	}
}
