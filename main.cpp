#include <iostream>
#include "Adafruit_INA219/Adafruit_INA219.hpp"

int main() 
{
	if (gpioInitialise() < 0)
	{
		std::cerr << "pigpio initialization failed" << std::endl;
		return 1;
	}

	INA219 ina219(1, 0x41); // I2C bus 1

	float busVoltage = ina219.getBusVoltage();
	float shuntVoltage = ina219.getShuntVoltage();
	float current = ina219.getCurrent();
	float power = ina219.getPower();

	std::cout << "Bus Voltage: " << busVoltage << " V" << std::endl;
	std::cout << "Shunt Voltage: " << shuntVoltage << " V" << std::endl;
	std::cout << "Current: " << current << " mA" << std::endl;
	std::cout << "Power: " << power << " W" << std::endl;

	gpioTerminate();
	return 0;
}