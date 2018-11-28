#ifndef BUTTON_H
#define BUTTON_H

#include <RT2D/entity.h>
#include <functional>


class Button : public Entity {
public:

	Button();
	Button(std::string sprite, std::function<void()> task);
	virtual ~Button();

	virtual void update(float deltatime);

	bool onMouseOver();
	bool onClick();
	void setTask(std::function<void()> _task);

private:

	std::function<void()> task;
	void animateClickDown();
	void animateClickUp();
};

#endif //BUTTON_H
