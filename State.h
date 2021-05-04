#pragma once
class State
{
protected:

	bool quit;

public:

	State() {}
	~State() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Change() = 0;

	bool getQuit() { return quit; }
	void setQuit(bool b) { quit = b; }
};