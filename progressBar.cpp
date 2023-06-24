#include "progressBar.h"

namespace MyProgressBar {
progressBar::progressBar(long long progress_input, long long total_input) {
    progress = progress_input;
    total = total_input;
}

int progressBar::getTerminalWidth() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
}


void progressBar::reset() { progress = 0; }

void progressBar::init(long long progress_input, long long total_input) {
    progress = progress_input;
    total = total_input;
}

void progressBar::simple() {
    std::cout << "\r" << std::setw(get_width(total));
    std::cout << progress << " / " << total << "  ";
    std::cout.flush();
}

void progressBar::fancy() {
    int barWidth = 50;
    barWidth = getTerminalWidth() - 10;
    if(barWidth <= 0) barWidth = 10;
    if(barWidth > 100) barWidth = 100;
    
    float fraction = static_cast<double>(progress) / total;
    int filledWidth = static_cast<int>(barWidth * fraction);

    std::cout << "\r"
              << "[" << std::string(filledWidth, '=')
              << std::string(barWidth - filledWidth, ' ') << "] "
              << std::setw(3) << static_cast<int>(fraction * 100) << "%  ";
    std::cout.flush();
}

void progressBar::increment() { progressBar::progress++; }

void progressBar::increment(long long val) { progressBar::progress += val; }

void progressBar::finish() {
    std::cout << std::endl << "Task completed!" << std::endl;
}

void progressBar::finish(std::string message) {
    std::cout << std::endl << "Task completed! " << message << std::endl;
}

unsigned short progressBar::get_width(long long num) {
    std::stringstream ss;
    ss << num;
    return ss.str().length();
}

}  // namespace MyProgressBar
