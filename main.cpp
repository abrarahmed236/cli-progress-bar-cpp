#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

void updateProgress(int progress, int total) {
    const int barWidth = 50;
    float percentage = static_cast<float>(progress) / total;
    int filledWidth = static_cast<int>(barWidth * percentage);

    std::cout << "\r"
              << "[";
    for (int i = 0; i < filledWidth; ++i) {
        std::cout << "=";
    }
    for (int i = filledWidth; i < barWidth; ++i) {
        std::cout << " ";
    }
    std::cout << "] " << std::setw(3) << static_cast<int>(percentage * 100)
              << "%  ";
    std::cout.flush();
}

int main() {
    const int totalIterations = 100;

    for (int i = 0; i <= totalIterations; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // fancy progress bar
        // updateProgress(i, totalIterations);

        // simple progress bar
        std::cout << "\r" << std::setw(3) << i << " / " << totalIterations
                  << "  ";
        std::cout.flush();
    }

    std::cout << std::endl;
    std::cout << "Task completed!" << std::endl;

    return 0;
}
