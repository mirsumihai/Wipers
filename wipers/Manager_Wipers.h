#pragma once
#include "Button.h"
#include "Sensor_Rain.h"
#include "Sensor_WasherFluid.h"
#include<tuple>
class Manager_Wipers
{
	Button button;
	Sensor_Rain rain;
	Sensor_WasherFluid level;
public:
	void SetButton(const ButtonState buttonState) {
		button.SetState(buttonState);
	}

	void Set
};

