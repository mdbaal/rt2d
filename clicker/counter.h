#ifndef COUNTER_H
#define COUNTER_H

#include <rt2d/entity.h>
#include <rt2d/text.h>


class Counter : public Entity{
public:
	Counter();
	virtual ~Counter();
	virtual void update(float deltatime);
	void upCookies(int i);
private:
	int cookies = 0;
	Text* counterText = nullptr;


};

#endif //COUNTER_H