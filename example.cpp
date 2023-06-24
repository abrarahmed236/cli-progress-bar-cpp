#include <chrono>
#include <iostream>
#include <thread>

#include "progressBar.h"

void runSimpleProgressBar(const int totalIterations, const int duration) {
    MyProgressBar::progressBar progressLog(0, totalIterations);
    std::cout << "Simple Progress Bar:" << std::endl;
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.simple();
    }
    progressLog.finish();
}

void runFancyProgressBar(const int totalIterations, const int duration) {
    MyProgressBar::progressBar progressLog(0, totalIterations);
    std::cout << "Fancy Progress Bar:" << std::endl;
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.fancy();
    }
    progressLog.finish();
}

int main() {
    const int totalIterations =
        123457;                // prime number of iterations for good luck
    const int duration = 100;  // microseconds

    runSimpleProgressBar(totalIterations, duration);
    std::cout << std::endl;
    runFancyProgressBar(totalIterations, duration);

    return 0;
}