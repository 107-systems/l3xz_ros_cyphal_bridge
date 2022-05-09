/**
 * Copyright (c) 2022 LXRobotics GmbH.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/l3xz/graphs/contributors.
 */

#ifndef GLUE_L3XZ_ELROB2022_DYNAMIXEL_ANGLE_POSITION_ACTUATOR_H_
#define GLUE_L3XZ_ELROB2022_DYNAMIXEL_ANGLE_POSITION_ACTUATOR_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <common/actuator/interface/AnglePositionActuator.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace glue::l3xz::ELROB2022
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DynamixelAnglePositionActuator : public common::actuator::interface::AnglePositionActuator
{
public:
  DynamixelAnglePositionActuator(std::string const & name, float const initial_value)
  : AnglePositionActuator(name)
  , _val{std::nullopt}
  {
    set(initial_value);
  }

  virtual void set(float const & val) override {
    _val = val;
  }

  float getAngleDeg() const {
    return get().value();
  }

protected:
  virtual std::optional<float> get() const override {
    return _val;
  }

private:
  std::optional<float> _val;
};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::shared_ptr<DynamixelAnglePositionActuator> SharedDynamixelAnglePositionActuator;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* glue::l3xz::ELROB2022 */

#endif /* GLUE_L3XZ_ELROB2022_DYNAMIXEL_ANGLE_POSITION_ACTUATOR_H_ */
