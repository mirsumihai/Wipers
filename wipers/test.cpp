#include "pch.h"
#include "gtest/gtest.h"
#include "Manager_Actuators.h"

TEST(ButtonUnitTest, GivenValue_ExpectedSameValue) {

    Button bt{};

    bt.SetState({ ButtonState::Off });
    EXPECT_EQ(bt.GetState(), ButtonState::Off);

    bt.SetState({ ButtonState::Low });
    EXPECT_EQ(bt.GetState(), ButtonState::Low);

    bt.SetState({ ButtonState::High });
    EXPECT_EQ(bt.GetState(), ButtonState::High);

    bt.SetState({ ButtonState::Mist });
    EXPECT_EQ(bt.GetState(), ButtonState::Mist);

    bt.SetState({ ButtonState::Automatic });
    EXPECT_EQ(bt.GetState(), ButtonState::Automatic);
}

TEST(WipersUnitTest, GivenValue_ExpectedSameValue) {

    WipersMotor wp{};

    wp.SetLevel({ WipersState::WipOff });
    EXPECT_EQ(wp.GetWiper(), WipersState::WipOff);

    wp.SetLevel({ WipersState::LowWip });
    EXPECT_EQ(wp.GetWiper(), WipersState::LowWip);

    wp.SetLevel({ WipersState::HighWip });
    EXPECT_EQ(wp.GetWiper(), WipersState::HighWip);

    wp.SetLevel({ WipersState::MistWip });
    EXPECT_EQ(wp.GetWiper(), WipersState::MistWip);

    wp.SetLevel({ WipersState::AutomaticWip });
    EXPECT_EQ(wp.GetWiper(), WipersState::AutomaticWip);
}

TEST(ManagerActuatorsTest, SetWipersTest) {
    // Create a Manager_Wipers object with initial state
    Manager_Wipers wipersResult;
    wipersResult.SetButton(ButtonState::Automatic);
    wipersResult.SetRain(2.6f);
    wipersResult.SetLevel(0.3f);
   
    // Create a Manager_Actuators object and set wipers state
    Manager_Actuators actuators(wipersResult);
    actuators.SetWipers();
    actuators.SetDisplay();
    actuators.SetPump();

    // Check if the wipers state is set correctly
    EXPECT_EQ(actuators.GetWipersMotor().GetWiper(), WipersState::HighWip);
    EXPECT_EQ(actuators.GetDisplay().GetLedColor(), DisplayState::Yellow);

}