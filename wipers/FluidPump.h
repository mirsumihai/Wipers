#pragma once
#include "Data_Type.h"
class FluidPump
{

public:
	FluidPump() {}
	void SetState(FluidPumpState state) { pump = state; }
	FluidPumpState GetPump() const { return pump; }
protected:
	FluidPumpState pump;
};

