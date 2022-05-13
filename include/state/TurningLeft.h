/**
 * Copyright (c) 2022 LXRobotics GmbH.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/l3xz/graphs/contributors.
 */

#ifndef TURNING_LEFT_H_
#define TURNING_LEFT_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "GaitControllerState.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class TurningLeft : public GaitControllerState
{
public:
  virtual ~TurningLeft() { }
  virtual void onEnter() override;
  virtual void onExit() override;
  virtual GaitControllerState * update(GaitControllerStateInput const & input, GaitControllerStateOutput & output) override;
};

#endif /* TURNING_LEFT_H_ */
