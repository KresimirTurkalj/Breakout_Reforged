#pragma once
#include <SDL.h>

class Presenter {
public:
	virtual void sceneOver() = 0;
	virtual ~Presenter() {}
};

class IPresentable {
public:
	virtual void startCycle(Presenter* presenter, int logicInterval, int screenInterval) = 0;
	static Uint32 logicCallback(Uint32 interval, void* param) {
		IPresentable* instance = static_cast<IPresentable*>(param);
		return instance->updateForInterval(interval);
	}
	static Uint32 screenCallback(Uint32 interval, void* param) {
		IPresentable* instance = static_cast<IPresentable*>(param);
		return instance->updateScreen(interval);
	}
	virtual ~IPresentable() {}
private:
	virtual void onSceneOver() = 0;
	/*Cyclic change for logic*/
	virtual Uint32 updateForInterval(Uint32 interval) = 0;
	/*Cyclic change for screen for given interval in millis.*/
	virtual Uint32 updateScreen(Uint32 interval) = 0;
};

