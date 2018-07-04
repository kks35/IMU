
#include "imu.h"

#include <lpsensor/LpmsSensorI.h>
#include <lpsensor/LpmsSensorManagerI.h>

#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include <utility>

IMU::~IMU() {
	disconnectDevice();
}

std::pair<bool, ImuData> IMU::getData() const {
	ImuData d;
	if(sensor->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED
			&& sensor->hasImuData()) {
		d = sensor->getCurrentData();

		return std::make_pair(true, d);
	}
	return std::make_pair(false, d);
}

void IMU::connectDevice() {
	manager = std::unique_ptr<LpmsSensorManagerI>(LpmsSensorManagerFactory());

	sensor = manager->addSensor(DEVICE_LPMS_B2, address.c_str());
}

void IMU::disconnectDevice() {
	if(sensor != nullptr) {
		manager->removeSensor(sensor);
	}
}
