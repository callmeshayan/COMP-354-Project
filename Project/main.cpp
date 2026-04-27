#include "ScheduleFCFS.h"
#include "ScheduleSJF.h"
#include "ScheduleRR.h"
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

    // Re-open file for SJF
    std::ifstream file2("tasks.txt");
    SJF sjfScheduler;
    while (std::getline(file2, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string name, priorityStr, burstStr;
        std::getline(ss, name, ',');
        std::getline(ss, priorityStr, ',');
        std::getline(ss, burstStr);
        auto trim = [](const std::string& s) {
            size_t start = s.find_first_not_of(" \t");
            return (start == std::string::npos) ? "" : s.substr(start);
        };
        name = trim(name);
        int priority = std::stoi(trim(priorityStr));
        int burst    = std::stoi(trim(burstStr));
        sjfScheduler.addTask(new Task(name, priority, burst));
    }
    file2.close();

    std::cout << "\n--- SJF Scheduling ---" << std::endl;
    sjfScheduler.schedule(cpu);

    // Re-open file for RR
    std::ifstream file3("tasks.txt");
    RR rrScheduler(10);
    while (std::getline(file3, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string name, priorityStr, burstStr;
        std::getline(ss, name, ',');
        std::getline(ss, priorityStr, ',');
        std::getline(ss, burstStr);
        auto trim = [](const std::string& s) {
            size_t start = s.find_first_not_of(" \t");
            return (start == std::string::npos) ? "" : s.substr(start);
        };
        name = trim(name);
        int priority = std::stoi(trim(priorityStr));
        int burst    = std::stoi(trim(burstStr));
        rrScheduler.addTask(new Task(name, priority, burst));
    }
    file3.close();

    std::cout << "\n--- Round Robin Scheduling (Quantum = 10) ---" << std::endl;
    rrScheduler.schedule(cpu);

    return 0;
}
