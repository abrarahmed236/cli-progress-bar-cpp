#include <iostream>

#include "progressBar.h"

void simpleProgressExample(const int totalIterations, const int duration) {
    MyProgressBar::progressBar progressLog(0, totalIterations);
    std::cout << "Simple Progress Bar:" << std::endl;
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.simple();
    }
    progressLog.finish();
}

void fancyProgressExample(const int totalIterations, const int duration) {
    MyProgressBar::progressBar progressLog(0, totalIterations);
    std::cout << "Fancy Progress Bar:" << std::endl;
    progressLog.reset();
    progressLog.init(0, totalIterations);
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.fancy();
    }
    progressLog.finish();
}

int main() {
    const int totalIterations =
        123457;               // prime number of iterations for good luck
    const int duration = 100;  // microseconds

    simpleProgressExample(totalIterations, duration);
    std::cout << std::endl;
    fancyProgressExample(totalIterations, duration);

    return 0;
}