
#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

Robot::Robot() : TimedRobot()
{
}
void Robot::RobotInit()
{
  std::cout << "Robot is online" << std::endl;
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{

  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit(){
  container.autocommand = container.chassis.getRamsetteCommand(
    frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
    {
      frc::Translation2d(1_m,-2_m),
      frc::Translation2d(2_m, 0_m),
      frc::Translation2d(3_m,-1_m),
      frc::Translation2d(4_m,0_m),
      frc::Translation2d(5_m,-2_m),
      frc::Translation2d(6_m,0_m),
      frc::Translation2d(7_m,-1_m),

    },
    frc::Pose2d(0.8_m, -1_m, frc::Rotation2d(180_deg))
  );
  container.autocommand->Schedule();
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{

}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic(){

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif

