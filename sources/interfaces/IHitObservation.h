#pragma once

class HitSubject;

class IHitObserver{
public:
	virtual void onHitRegistered() = 0;
	~IHitObserver() {}
};

class IHitSubject {
public:
	virtual void registerObserver(IHitObserver* observer) = 0;
	~IHitSubject() {}
};
