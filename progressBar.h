#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

namespace MyProgressBar {
class progressBar {
    long long progress;
    long long total;

   public:
    progressBar(long long progress_input, long long total_input);
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
}  // namespace MyProgressBar

#endif