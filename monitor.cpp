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

bool isTemperatureCritical(float temperature) {
    if(temperature > 102 || temperature < 95) {
        displayMessage("Temperature is critical!");
    return 0;
    }
return 1;
}


bool isPulseRateOutOfRange(float pulseRate) {
    if(pulseRate < 60 || pulseRate > 100) {
        displayMessage("Pulse Rate is out of range!"); 
        return 0;
    }
    return 1;
}

bool isSpo2OutOfRange(float spo2) {
    if (spo2 < 90) {
        displayMessage("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    return (isTemperatureCritical(temperature) && isPulseRateOutOfRange(pulseRate) && isSpo2OutOfRange(spo2));
}

