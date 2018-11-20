#include "TestScene.h"


TestScene::TestScene() {
	b = new Button("assets/square.tga", std::bind(&TestScene::printHello, this));

	this->addChild(b);
}

void TestScene::update(float deltatime) {
	if (input()->getKeyDown(Escape)) this->stop();
}

TestScene::~TestScene() {

}

void TestScene::printHello() {
	std::cout << "Hello" << std::endl;
}