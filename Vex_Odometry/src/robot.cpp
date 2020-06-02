/*
*    "robot.cpp" - Defines a robot class for timed actions.
*    Copyright (C) 2020  Evan Hess
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along
*    with this program; if not, write to the Free Software Foundation, Inc.,
*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "robot.h"

Robot::Robot(vex::brain* brain, vex::motor &l, vex::motor &r, vex::inertial &g, double wheelTravel, double trackWidth, double wheelBase, vex::distanceUnits unit, double externalGearRatio) : smartdrive(l, r, g, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio)
{
  robotBrain = brain;
}

Robot::Robot(vex::brain* brain, vex::motor_group &l, vex::motor_group &r, vex::inertial &g, double wheelTravel, double trackWidth, double wheelBase, vex::distanceUnits unit, double externalGearRatio) : smartdrive(l, r, g, wheelTravel, trackWidth, wheelBase, unit, externalGearRatio)
{
  robotBrain = brain;
}

void Robot::driveForT(vex::directionType dir, double distance, vex::distanceUnits units, uint32_t timeout)
{
  driveFor(dir, distance, units, false);
  uint32_t start = robotBrain->Timer.time(vex::timeUnits::msec);
  uint32_t timer = start;

  while(isMoving() && (timer - start) < timeout)
  {
    vex::task::sleep(10);
    timer = robotBrain->Timer.time(vex::timeUnits::msec);
  }

  stop();
}

void Robot::turnForT(vex::turnType dir, double angle, vex::rotationUnits units, uint32_t timeout)
{
  turnFor(dir, angle, units, false);
  uint32_t start = robotBrain->Timer.time(vex::timeUnits::msec);
  uint32_t timer = start;

  while(isTurning() && (timer - start) < timeout)
  {
    vex::task::sleep(10);
    timer = robotBrain->Timer.time(vex::timeUnits::msec);
  }

  stop();
}

void Robot::turnToT(double angle, vex::rotationUnits units, uint32_t timeout)
{
  turnToHeading(angle, units, false);
  uint32_t start = robotBrain->Timer.time(vex::timeUnits::msec);
  uint32_t timer = start;

  while(isTurning() && (timer - start) < timeout)
  {
    vex::task::sleep(10);
    timer = robotBrain->Timer.time(vex::timeUnits::msec);
  }

  stop();
}
