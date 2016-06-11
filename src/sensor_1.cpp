/** @file    sensor_1.cpp 
 *  @author  William Emfinger
 *  @date    2016.06.10
 *  @brief   This file contains definitions of the sensor_1 class
 */

#include "sensor_1.hpp"

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

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
    int spaces = 0;

    http_client client(U("http://129.59.105.153:9000"));
    uri_builder builder(U("/api/devices/ch1/AvailableParkingSpaces"));
    //builder.set_port(9000);
    //builder.append_query(U("q"), U("Casablanca CodePlex"));
    pplx::task<void> requestTask = client.request(methods::GET, builder.to_string())
      .then([=](http_response response)
	    {
	      std::cout << "Received response status code: " << response.status_code() << std::endl;
	    });
     try 
      {
	requestTask.wait();
      }
    catch (const std::exception &e)
      {
	std::cout << "Error: " << e.what();
      }
      
     publisher("publisher_port")->send(std::to_string(spaces));
  }
}

