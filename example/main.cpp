
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

			// Euler Angle data
			std::cout << "Eur(" << d.r[0] << ", " << d.r[1] << ", " << d.r[2] << ")" << std::endl;
		}
	}
}
