/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  chassis.SetDefaultCommand(frc2::RunCommand (
    [this] {
    chassis.TankDrive(
    xbox.GetY(frc::XboxController::kLeftHand), 
    xbox.GetY(frc::XboxController::kRightHand));}
    ,&chassis));
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
   this->ramseteBind.WhileActiveOnce(RamseteExample(&chassis),true); //interruptible 
}
