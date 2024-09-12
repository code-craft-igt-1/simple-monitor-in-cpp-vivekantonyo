#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

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
        message = "TEMP_HYPER_WARNING";
    else if (currentvalue < lowerWarningLimit)
        message = "TEMP_HYPO_WARNING";
    else
        message = "NORMAL";
    displayMessage(message);
}

int checkTemperatureValue(float temp) {
    bool checkTempRange = isParamsNotInRange(temp, TEMP_LOWERLIMIT, TEMP_UPPERLIMIT);
    if (checkTempRange) {
        displayMessage("TEMP_CRITICAL");
        return 0;
    }else {
        checkEarlyWarning(temp, TEMP_UPPERLIMIT, TEMP_LOWERLIMIT);
        return 1;
    }
}

int checkPulseRateValue(float pulse) {
    bool checkPulseRange = isParamsNotInRange(pulse, PULSE_LOWERLIMIT, PULSE_UPPERLIMIT);
    if (checkPulseRange) {
        displayMessage("PULSERATE_CRITICAL");
        return 0;
    }else {
        checkEarlyWarning(pulse, PULSE_UPPERLIMIT, PULSE_LOWERLIMIT);
        return 1;
    }
}

int checkSpo2Value(float spo2) {
    bool checkSpo2Range = isParamsNotInRange(spo2, SPO2_LOWERLIMIT, SPO2_UPPERLIMIT);
    if (checkSpo2Range) {
        displayMessage("SPO2_CRITICAL");
        return 0;
    }else {
        checkEarlyWarning(spo2, SPO2_UPPERLIMIT, SPO2_LOWERLIMIT);
        return 1;
    }
}

int areVitalsNormal(float temp, float pulse, float spo2) {
    return (checkTemperatureValue(temp) && checkPulseRateValue(pulse) && checkSpo2Value(spo2));
}

