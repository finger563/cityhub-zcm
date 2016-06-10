/** @file    sensor_1.cpp 
 *  @author  William Emfinger
 *  @date    2016.06.10
 *  @brief   This file contains definitions of the sensor_1 class
 */

#include "sensor_1.hpp"

namespace zcm {

  /**
   * @brief Function required to dynamically load sensor_1.so
   */   
  extern "C" {
    Component* create_component() {
      return new sensor_1();
    }
  }

  /**
   * @brief Construct sensor_1
   * Register all operations exposed by this component
   */    
  sensor_1::sensor_1() {
    register_timer_operation("timer_function",
			     std::bind(&sensor_1::timer_function, this));
  }

  /**
   * @brief A timer operation
   * This operation can be triggered by a periodic timer
   * Bind this operation to a periodic timer in the JSON configuration
   */     
  void sensor_1::timer_function() {
    publisher("publisher_port")->send("sensor_1");
  }
}

