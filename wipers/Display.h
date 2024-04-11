#pragma once
#include "Data_Type.h"

class Display
{
public:
	DisplayState GetLedColor() const { return state; }
	void SetLedColor(const DisplayState dis_state) { state = dis_state; }

protected:
	DisplayState state;
};