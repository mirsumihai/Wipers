#pragma once
#include"Data_Type.h"
class WipersMotor
{
public:
	WipersMotor() {}
	void SetLevel(WipersState level) { wipersState = level; }
	WipersState GetWiper() const { return wipersState; } 
protected:
	WipersState wipersState;
};

