#pragma once
#include<string>
const double TEMP_LOWERLIMIT = 95.0;
const double TEMP_UPPERLIMIT = 102.0;
const double PULSE_LOWERLIMIT = 60.0;
const double PULSE_UPPERLIMIT = 100.0;
const double SPO2_LOWERLIMIT = 90.0;
const double SPO2_UPPERLIMIT = 100.0;
int areVitalsNormal(float temperature, float pulseRate, float spo2);
