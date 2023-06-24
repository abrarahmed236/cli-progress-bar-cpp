#include <iostream>

#include "progressBar.h"

int main() {
    const int totalIterations = 123457;  // iterations
    const int duration = 100;            // microseconds
    progressBar progressLog(0, totalIterations);

    std::cout << "Simple Progress Bar:" << std::endl;
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.simple();
    }
    progressLog.finish();

    std::cout << "Fancy Progress Bar:" << std::endl;
    progressLog.reset();
    progressLog.init(0, totalIterations);
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(duration));
        progressLog.increment();
        progressLog.fancy();
    }
    progressLog.finish();

    return 0;
}