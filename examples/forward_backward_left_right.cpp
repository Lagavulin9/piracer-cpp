#include "../PiRacer/PiRacer.hpp"

int main()
{
	// Create PiRacer Instance
	PiRacer racer;

	// Forward
	racer.setThrottlePercent(0.2);
	sleep(2);

	// Brake
	racer.setThrottlePercent(-1);
	sleep(0.5);
	racer.setThrottlePercent(0.0);
	sleep(0.1);

	// Backward
	racer.setThrottlePercent(-0.2);
	sleep(2);

	// Stop
	racer.setThrottlePercent(0.0);

	// Steering Left
	racer.setSteeringPercent(1.0);
	sleep(1);

	// Steering Right
	racer.setSteeringPercent(-1.0);
	sleep(1);

	// Steering Neutral
	racer.setSteeringPercent(0.0);

	return 0;
}