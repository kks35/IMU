
#include <imu/imu.h>

#include <lpsensor/ImuData.h>

#define DEFAULT_ADDRESS  "00:04:3E:9B:A3:7E"

int main() {
	IMU imu(DEFAULT_ADDRESS);

	while(true) {
		auto output = imu.getData();
		if(output.first) {

			// See ImuData.h in LpSensor/include/ for more details.
			ImuData d = output.second;

			// Accelerometer Data
			std::cout << "Acc(" << d.a[0] << ", " << d.a[1] << ", " << d.a[2] << "), ";

			// Quaternion orientation data
			std::cout << "Q(" << d.q[0] << ", " << d.q[1] << ", " << d.q[2] << ", " << d.q[3] << ")" << std::endl;
		}
	}
}
