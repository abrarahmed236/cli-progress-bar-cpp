#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <sys/ioctl.h>
#include <unistd.h>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <sstream>

namespace MyProgressBar {
class progressBar {
    long long progress;
    long long total;

    uint8_t get_width(long long num);
    int getTerminalWidth();

   public:
    progressBar(long long progress_input, long long total_input);

    void reset();
    void init(long long progress_input, long long total_input);
    void increment();
    void increment(long long val);

    void simple();
    void fancy();
    void finish();
    void finish(std::string message);
};
}  // namespace MyProgressBar

#endif