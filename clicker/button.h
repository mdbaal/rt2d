#ifndef BUTTON_H
#define BUTTON_H

#include <RT2D/entity.h>
#include <functional>


class Button : public Entity {
public:

	Button();
	virtual ~Button();

	virtual void update(float deltatime);

	bool onMouseOver();
	bool onClick();
	void setTask(std::function<void()> _task);
	void setTaskI(std::function<void(int)> _taskI,int id);

private:

	std::function<void()> task;
	std::function<void(int)> taskI;
	void animateClickDown();
	void animateClickUp();
	int id = 0;
};

#endif //BUTTON_H
