ZCM_HEADERS=/usr/local/include/zcm
ZCM_LIBRARY=/usr/local/lib

TEST_INCLUDE_DIR=include
TEST_SOURCE_DIR=src
TEST_BUILD_DIR=build
TEST_CONFIG_DIR=config

all:
	mkdir -p $(TEST_BUILD_DIR)
	cp -r $(TEST_CONFIG_DIR)/* $(TEST_BUILD_DIR)/.
	g++ -fPIC -shared $(TEST_SOURCE_DIR)/sensor_1.cpp -o $(TEST_BUILD_DIR)/sensor_1.so -I$(TEST_INCLUDE_DIR) -std=c++11 -pthread -I$(ZCM_HEADERS) -L$(ZCM_LIBRARY) -lzcm -lzmq -lboost_filesystem -lcpprest
	g++ -fPIC -shared $(TEST_SOURCE_DIR)/sensor_2.cpp -o $(TEST_BUILD_DIR)/sensor_2.so -I$(TEST_INCLUDE_DIR) -std=c++11 -pthread -I$(ZCM_HEADERS) -L$(ZCM_LIBRARY) -lzcm -lzmq -lboost_filesystem -lcpprest
	g++ -fPIC -shared $(TEST_SOURCE_DIR)/aggregator.cpp -o $(TEST_BUILD_DIR)/aggregator.so -I$(TEST_INCLUDE_DIR) -std=c++11 -pthread -I$(ZCM_HEADERS) -L$(ZCM_LIBRARY) -lzcm -lzmq -lboost_filesystem
	g++ -fPIC -shared $(TEST_SOURCE_DIR)/predictor.cpp -o $(TEST_BUILD_DIR)/predictor.so -I$(TEST_INCLUDE_DIR) -std=c++11 -pthread -I$(ZCM_HEADERS) -L$(ZCM_LIBRARY) -lzcm -lzmq -lboost_filesystem
	g++ $(TEST_SOURCE_DIR)/main.cpp -o $(TEST_BUILD_DIR)/actor -I$(TEST_INCLUDE_DIR) -std=c++11 -ldl -pthread -I$(ZCM_HEADERS) -L$(ZCM_LIBRARY) -lzcm -lzmq
run:
	cd $(TEST_BUILD_DIR) && export LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) && ./actor
clean:
	rm -rf $(TEST_BUILD_DIR)
