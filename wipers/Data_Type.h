#pragma once
typedef enum ButtonState {
	Off = 0,
	Low,
	High,
	Mist,
	Automatic
};
typedef enum WipersState {
	WipOff=0,
	LowWip,
	HighWip,
	MistWip,
	AutomaticWip
};
typedef enum DisplayState {
	None=0,
	Yellow,
	Red
};
typedef enum FluidPumpState {
	On=1,
	OffPump=0
};
constexpr float LowRainThreshold{ 0.5 };
constexpr float HighRainThreshold{ 1.0 };
constexpr float WaterLevelLow{ 0.5 };
constexpr float WaterLevel0{ 0.0 };