#pragma once

class IBreakSubject;

class IBreakObserver {
public:
	virtual void onBreakObserved(IBreakSubject* brokenSubject) = 0;
	~IBreakObserver() {}
};

class IBreakSubject {
public:
	virtual void registerObserver(IBreakObserver* observer) = 0;
	~IBreakSubject() {}
};
