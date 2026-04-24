#include "ScheduleFCFS.h"
#include "Task.h"
#include "CPU.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Main entry point for the CPU scheduling simulator
 * @author Shayan NaghashpourShoushtari
 * @return 0 on success, 1 on file error
 */
int main() {
    std::ifstream file("tasks.txt");
    if (!file.is_open()) {
        std::cerr << "Error: could not open tasks.txt" << std::endl;
        return 1;
    }

    FCFS fcfsScheduler;
    CPU cpu;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string name, priorityStr, burstStr;
        std::getline(ss, name, ',');
        std::getline(ss, priorityStr, ',');
        std::getline(ss, burstStr);
        // Trim leading whitespace
        auto trim = [](const std::string& s) {
            size_t start = s.find_first_not_of(" \t");
            return (start == std::string::npos) ? "" : s.substr(start);
        };
        name = trim(name);
        int priority = std::stoi(trim(priorityStr));
        int burst    = std::stoi(trim(burstStr));
        fcfsScheduler.addTask(new Task(name, priority, burst));
    }
    file.close();

    std::cout << "\n--- FCFS Scheduling ---" << std::endl;
    fcfsScheduler.schedule(cpu);

    return 0;
}
