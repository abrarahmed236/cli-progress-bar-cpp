#include <iostream>
#include<thread>
#include<chrono>

void updateProgress(int progress, int total) {
  const int barWidth = 50;
  float percentage = static_cast<float>(progress) / total;
  int filledWidth = static_cast<int>(barWidth * percentage);

  std::cout << "[";
  for (int i = 0; i < filledWidth; ++i) {
    std::cout << "=";
  }
  for (int i = filledWidth; i < barWidth; ++i) {
    std::cout << " ";
  }
  std::cout << "] " << static_cast<int>(percentage * 100) << "%\r";
  std::cout.flush();
}

int main() {
  const int totalIterations = 100;

  for (int i = 0; i <= totalIterations; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // updateProgress(i, totalIterations);
    // Simulate some work
    // You can replace this with your actual code that performs the task
    // Sleep or delay can be used to simulate processing time
    std::cout << i << " / " << totalIterations << "\r";
    std::cout.flush();
  }

  std::cout << std::endl;
  std::cout << "Task completed!" << std::endl;

  return 0;
}
