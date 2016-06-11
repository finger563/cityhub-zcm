/** @file    sensor_1.cpp 
 *  @author  William Emfinger
 *  @date    2016.06.10
 *  @brief   This file contains definitions of the sensor_2 class
 */

#include "sensor_2.hpp"

namespace zcm {

  /**
   * @brief Function required to dynamically load sensor_2.so
   */   
  extern "C" {
    Component* create_component() {
      return new sensor_2();
    }
  }

  /**
   * @brief Construct sensor_2
   * Register all operations exposed by this component
   */    
  sensor_2::sensor_2() {
    register_timer_operation("timer_function",
			     std::bind(&sensor_2::timer_function, this));
  }

  /**
   * @brief A timer operation
   * This operation can be triggered by a periodic timer
   * Bind this operation to a periodic timer in the JSON configuration
   */     
  void sensor_2::timer_function() {
    int spaces = 0;
    publisher("sensor_2_pub")->send(std::to_string(spaces));
  }
}

