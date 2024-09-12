#pragma once

const double TEMPERATURE_LOWER_LIMIT = 95.0;
const double TEMPERATURE_UPPER_LIMIT = 102.0;
const double PULSE_RATE_LOWER_LIMIT = 60.0;
const double PULSE_RATE_UPPER_LIMIT = 100.0;
const double SPO2_LOWER_LIMIT = 90.0;
const double SPO2_UPPER_LIMIT = 100.0;

int areVitalsNormal(float temperature, float pulseRate, float spo2);
