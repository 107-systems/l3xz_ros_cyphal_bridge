/**
 * Copyright (c) 2022 LXRobotics GmbH.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/l3xz/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <Robot.h>

#include <state/InitState.h>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Robot::Robot()
: _robot_state{new InitState()}
{
  _robot_state->onEnter();
}

Robot::~Robot()
{
  delete _robot_state;
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void Robot::update(RobotStateInput const & input, RobotStateOutput & output)
{
  RobotState * next_robot_state = _robot_state->update(input, output);
    
  if (next_robot_state->name() != _robot_state->name())
  {
    _robot_state->onExit();

    delete _robot_state;
    _robot_state = next_robot_state;
    
    _robot_state->onEnter();
  }
}
