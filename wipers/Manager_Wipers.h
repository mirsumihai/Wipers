#pragma once
#include "Button.h"
#include "Sensor_Rain.h"
#include "Sensor_FluidPump.h"
#include<tuple>
class Manager_Wipers
{
	Button button;
	Sensor_Rain rain;
	Sensor_FluidPump level;
public:
	void SetButton(const ButtonState buttonState) {
		button.SetState(buttonState);
	}

	void SetRain(const float value) {
		rain.SetValue(value);
	}

	void SetLevel(const float value) {
		level.SetValue(value);
	}
    std::tuple<DisplayState,FluidPumpState, WipersState> CalculateWipersState() {
        auto wipersState = std::make_tuple(DisplayState::None, FluidPumpState::OffPump, WipersState::WipOff);
        DisplayState displayState = DisplayState::None;
        
        // Check fluid sensor value
        if (level.GetValue() <= WaterLevel0) {
            displayState = DisplayState::Red; 
        }
        else if (level.GetValue() <= WaterLevelLow) {
            displayState = DisplayState::Yellow;
        }

        // Check button state and rain sensor value
        switch (button.GetState()) {
        case ButtonState::Low: {
            wipersState = std::make_tuple(displayState,FluidPumpState::OffPump, WipersState::LowWip);
            break;
        }
        case ButtonState::High: {
            wipersState = std::make_tuple(displayState, FluidPumpState::OffPump, WipersState::HighWip);
            break;
        }
        case ButtonState::Automatic:{
            if (rain.GetValue() > HighRainThreshold) {
                wipersState = std::make_tuple(displayState, FluidPumpState::OffPump, WipersState::HighWip);
            }
            else if ((rain.GetValue() > LowRainThreshold)&&(rain.GetValue() < HighRainThreshold)) {
                wipersState = std::make_tuple(displayState, FluidPumpState::OffPump, WipersState::LowWip);
            }
            else {
                wipersState = std::make_tuple(displayState, FluidPumpState::OffPump, WipersState::WipOff);
            }
            break;
        }
        case ButtonState::Mist: {
            if (level.GetValue() <= WaterLevel0) {
                wipersState = std::make_tuple(displayState, FluidPumpState::OffPump, WipersState::MistWip);
            }
            else {
                wipersState = std::make_tuple(displayState, FluidPumpState::On, WipersState::MistWip);
            }
            break;
        }
        default: {
            wipersState = std::make_tuple(DisplayState::None, FluidPumpState::OffPump, WipersState::WipOff);
            break;
        }
        }
        return wipersState;
    }

};

