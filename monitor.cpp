#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
using namespace std;

string valueIsWithinRange = "NORMAL";
string upperLimitWarning = "TEMP_HYPER_WARNING";
string lowerLimitWarning = "TEMP_HYPO_WARNING";
string temperatureCritical = "TEMP_CRITICAL";
string pulseRateCritical = "PULSERATE_CRITICAL";
string spo2Critical = "SPO2_CRITICAL";

void displayMessage(std::string message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool isParamsNotInRange(double value, double lowerLimit, double upperLimit) {
    return (value < lowerLimit) || (value > upperLimit);
}

void checkEarlyWarning(float currentvalue, float upperLimit, float lowerLimit) {
    float tolerance = 0.015f;
    std::string message;
    float upperWarningLimit = upperLimit - (upperLimit * tolerance);
    float lowerWarningLimit = lowerLimit + (lowerLimit * tolerance);
    if (currentvalue > upperWarningLimit)
        message = upperLimitWarning;
    else if (currentvalue < lowerWarningLimit)
        message = lowerLimitWarning;
    else
        message = valueIsWithinRange;
    displayMessage(message);
}

int checkTemperatureValue(float temperature) {
    bool checkTemperatureNotInRange = isParamsNotInRange(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT);
    if (checkTemperatureNotInRange) {
        displayMessage("TEMP_CRITICAL");
        return 0;
    }
    else {
        checkEarlyWarning(temperature, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_LOWER_LIMIT);
        return 1;
    }
}

int checkPulseRateValue(float pulseRate) {
    bool checkPulseRateNotInRange = isParamsNotInRange(pulseRate, PULSE_RATE_LOWER_LIMIT, PULSE_RATE_UPPER_LIMIT);
    if (checkPulseRateNotInRange) {
        displayMessage(pulseRateCritical);
        return 0;
    }
    else {
        checkEarlyWarning(pulseRate, PULSE_RATE_UPPER_LIMIT, PULSE_RATE_LOWER_LIMIT);
        return 1;
    }
}

int checkSpo2Value(float spo2) {
    bool checkSpo2NotInRange = isParamsNotInRange(spo2, SPO2_LOWER_LIMIT, SPO2_UPPER_LIMIT);
    if (checkSpo2NotInRange) {
        displayMessage(spo2Critical);
        return 0;
    }
    else {
        checkEarlyWarning(spo2, SPO2_UPPER_LIMIT, SPO2_LOWER_LIMIT);
        return 1;
    }
}

int areVitalsNormal(float temp, float pulse, float spo2) {
    return (checkTemperatureValue(temp) && checkPulseRateValue(pulse) && checkSpo2Value(spo2));
}

