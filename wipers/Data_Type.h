#pragma once
typedef enum ButtonState {
	Off = 0,
	Low,
	High,
	Mist,
	int1,
	int2,
	int3,
	int4,
	int5
};
typedef enum WipersState {
	WipOff=0,
	LowWip,
	HighWip,
	MistWip,
	Int1Wip,
	Int2Wip,
	Int3Wip,
	Int4Wip,
	Int5Wip
};
typedef enum DisplayState {
	None=0,
	Yellow,
	Red
};
constexpr float LowRainThreshold{ 1.0 };
constexpr float HighRainThreshold{ 0.5 };