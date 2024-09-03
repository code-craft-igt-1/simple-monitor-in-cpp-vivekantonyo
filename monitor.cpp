#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std::this_thread;
using namespace std;
using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

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
    return temperature > 102 || temperature < 95;
}

bool isPulseRateOutOfRange(float pulseRate) {
    return pulseRate < 60 || pulseRate > 100;
}

bool isSpo2OutOfRange(float spo2) {
    return spo2 < 90;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureCritical(temperature)) {
        displayMessage("Temperature is critical!");
        return 0;
    }
    else if (isPulseRateOutOfRange(pulseRate)) {
        displayMessage("Pulse Rate is out of range!");
        return 0;
    }
    else if (isSpo2OutOfRange(spo2)) {
        displayMessage("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}
