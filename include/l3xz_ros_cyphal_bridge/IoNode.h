/**
 * Copyright (c) 2022 LXRobotics GmbH.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/l3xz_ros_cyphal_bridge/graphs/contributors.
 */

#ifndef ROS_ROS_BRIDGE_NODE_H_
#define ROS_ROS_BRIDGE_NODE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <rclcpp/rclcpp.hpp>

#include <l3xz_ros_cyphal_bridge/types/LegJointKey.h>

#include <l3xz_ros_cyphal_bridge/phy/opencyphal/Node.hpp>
#include <l3xz_ros_cyphal_bridge/phy/opencyphal/SocketCAN.h>
#include <l3xz_ros_cyphal_bridge/phy/opencyphal/NodeMonitor.h>

#include <l3xz_ros_cyphal_bridge/control/opencyphal/LegController.h>
#include <l3xz_ros_cyphal_bridge/control/opencyphal/PumpController.h>

#include <l3xz_gait_ctrl/msg/leg_angle.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace l3xz
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class IoNode : public rclcpp::Node
{
public:
  IoNode();


private:
  enum class State
  {
    Init_NodeMonitor,
    Calibrate,
    Active
  };
  State _state;

  phy::opencyphal::SocketCAN _open_cyphal_can_if;
  phy::opencyphal::Node _open_cyphal_node;

  phy::opencyphal::NodeMonitor _open_cyphal_node_monitor;
  control::PumpController _pump_ctrl;
  control::LegController _leg_ctrl;

  rclcpp::TimerBase::SharedPtr _timer;

  rclcpp::Publisher<l3xz_gait_ctrl::msg::LegAngle>::SharedPtr _leg_angle_pub;
  rclcpp::Subscription<l3xz_gait_ctrl::msg::LegAngle>::SharedPtr _leg_angle_sub;
  l3xz_gait_ctrl::msg::LegAngle _leg_angle_target_msg;

  void timerCallback();

  State handle_Init_NodeMonitor();
  State handle_Calibrate();
  State handle_Active();

  static float get_angle_deg(l3xz_gait_ctrl::msg::LegAngle const & msg, Leg const leg, Joint const joint);
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* l3xz */

#endif /* ROS_ROS_BRIDGE_NODE_H_ */
