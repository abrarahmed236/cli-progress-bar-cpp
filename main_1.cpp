#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

class progressLogger {
    long long progress;
    long long total;

   public:
    progressLogger(long long progress_input, long long total_input);
    void reset();
    void init(long long progress_input, long long total_input);
    void simple();
    void fancy();
    void increment();
    void increment(long long val);
    void finish();
    void finish(std::string message);
    uint8_t get_width(long long num);
};

progressLogger::progressLogger(long long progress_input,
                               long long total_input) {
    progress = progress_input;
    total = total_input;
}

void progressLogger::reset() { progress = 0; }

void progressLogger::init(long long progress_input, long long total_input) {
    progress = progress_input;
    total = total_input;
}

void progressLogger::simple() {
    std::cout << "\r" << std::setw(get_width(total));
    std::cout << progress << " / " << total << "  ";
    std::cout.flush();
}

void progressLogger::fancy() {
    int barWidth = 50;
    float fraction = static_cast<double>(progress) / total;
    int filledWidth = static_cast<int>(barWidth * fraction);

    std::cout << "\r"
              << "[" << std::string(filledWidth, '=')
              << std::string(barWidth - filledWidth, ' ') << "] "
              << std::setw(3) << static_cast<int>(fraction * 100) << "%  ";
    std::cout.flush();
}

void progressLogger::increment() { progressLogger::progress++; }

void progressLogger::increment(long long val) {
    progressLogger::progress += val;
}

void progressLogger::finish() {
    std::cout << std::endl << "Task completed!" << std::endl;
}

void progressLogger::finish(std::string message) {
    std::cout << std::endl << "Task completed! " << message << std::endl;
}

uint8_t progressLogger::get_width(long long num) {
    if (num == 0) return 1;
    uint8_t result = 0;
    if (num < 0) {
        result++;
        num *= -1;
    }
    while (num) {
        result++;
        num /= 10;
    }
    return result;
}

int main() {
    const int totalIterations = 234;

    progressLogger progressLog(0, totalIterations);
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        progressLog.increment();
        progressLog.simple();
    }
    progressLog.finish();

    progressLog.reset();
    progressLog.init(0, totalIterations);
    for (int i = 0; i < totalIterations; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        progressLog.increment();
        progressLog.fancy();
    }
    progressLog.finish();

    return 0;
}