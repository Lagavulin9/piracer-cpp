#pragma once
#ifndef __PIRACER_HPP__
# define __PIRACER_HPP__

#include "Adafruit_INA219.hpp"
#include "Adafruit_PCA9685.hpp"

class PiRacer {
private:
	int		PWM_RESOLUTION = 12;
	int		PWM_MAX_RAW_VALUE = std::pow(2, PWM_RESOLUTION) - 1;
	float	PWM_FREQ_50HZ = 50.0;
	float	PWM_WAVELENGTH_50HZ = 1.0 / PWM_FREQ_50HZ;
	int		PWM_STEERING_CHANNEL = 0;
	int		PWM_THROTTLE_CHANNEL_LEFT_MOTOR_IN_1 = 5;
	int		PWM_THROTTLE_CHANNEL_LEFT_MOTOR_IN_2 = 6;
	int		PWM_THROTTLE_CHANNEL_LEFT_MOTOR_IN_PWM = 7;
	int		PWM_THROTTLE_CHANNEL_RIGHT_MOTOR_IN_1 = 1;
	int		PWM_THROTTLE_CHANNEL_RIGHT_MOTOR_IN_2 = 2;
	int		PWM_THROTTLE_CHANNEL_RIGHT_MOTOR_IN_PWM = 0;

	PCA9685	_steeringController(PCA9685(1, 0x40));
	PCA9685	_throttleController(PCA9685(1, 0x60));
	INA219	_batteryMonitor(INA219(1, 0x41));

	float	_get50HzDutyCycleFromPercent(float value);
public:
	PiRacer();
	~PiRacer();

	float		getBatteryVoltage();
	float		getBatteryCurrent();
	float		getPowerConsumption();
	void		setSteeringPercent();
	void		setThrottlePercent();
}

#endif
