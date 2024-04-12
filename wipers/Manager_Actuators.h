#pragma once
#include "Display.h"
#include"Manager_Wipers.h"
#include"WipersMotor.h"
#include"FluidPump.h"
class Manager_Actuators
{
	Display display;
	WipersMotor wipers;
	FluidPump pump;
	Manager_Wipers wipers_result;
public:
	Manager_Actuators(Manager_Wipers wipersResult) :wipers_result(wipersResult) {}
	
	void ReadManagerWipers(Manager_Wipers wipersResult) {
		wipers_result = wipersResult;
	}
	void SetDisplay() {
		display.SetLedColor(std::get<0>(wipers_result.CalculateWipersState()));
	}
	void SetPump() {
		pump.SetState(std::get<1>(wipers_result.CalculateWipersState()));
	}
	void SetWipers() {
		wipers.SetLevel(std::get<2>(wipers_result.CalculateWipersState()));
	}
	Display GetDisplay() const {
		return display;
	}
	WipersMotor GetWipersMotor()const {
		return wipers;
	}
	FluidPump GetFluidPump()const {
		return pump;
	}
};

