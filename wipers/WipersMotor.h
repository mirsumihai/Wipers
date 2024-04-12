#pragma once
#include"Data_Type.h"
class WipersMotor
{
public:
	WipersMotor() {}
	void SetLevel(WipersState level) { wipers = level; }
	WipersState GetWiper() const { return wipers; } 
protected:
	WipersState wipers;
};

