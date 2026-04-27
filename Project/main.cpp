#include "ScheduleFCFS.h"
#include "ScheduleSJF.h"
#include "ScheduleRR.h"
#include "SchedulePriority.h"
#include "SchedulePriorityRR.h"
#include "Task.h"
#include "CPU.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Main entry point for the CPU scheduling simulator.
 *
 * Loads tasks from tasks.txt and runs all five scheduling algorithms,
 * printing results and average waiting time for each.
 *
 * @author Shayan NaghashpourShoushtari
 * @return 0 on success, 1 on file error
 */
int main() {
    const std::string SEP = "================================";

    std::cout << SEP << std::endl;
    std::cout << "CPU Scheduling Simulator - Shayan NaghashpourShoushtari" << std::endl;
    std::cout << SEP << std::endl;

    CPU cpu;

    // Reusable lambda: loads all tasks from tasks.txt into a given scheduler
    auto loadTasks = [](Scheduler& scheduler) {
        std::ifstream file("tasks.txt");
        if (!file.is_open()) {
            std::cerr << "Error: could not open tasks.txt" << std::endl;
            return;
        }
        auto trim = [](const std::string& s) {
            size_t start = s.find_first_not_of(" \t");
            return (start == std::string::npos) ? "" : s.substr(start);
        };
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::istringstream ss(line);
            std::string name, priorityStr, burstStr;
            std::getline(ss, name, ',');
            std::getline(ss, priorityStr, ',');
            std::getline(ss, burstStr);
            name = trim(name);
            int priority = std::stoi(trim(priorityStr));
            int burst    = std::stoi(trim(burstStr));
            scheduler.addTask(new Task(name, priority, burst));
        }
        file.close();
    };

    FCFS fcfsScheduler;
    loadTasks(fcfsScheduler);
    std::cout << "\n--- FCFS Scheduling ---" << std::endl;
    fcfsScheduler.schedule(cpu);
    std::cout << SEP << std::endl;

    SJF sjfScheduler;
    loadTasks(sjfScheduler);
    std::cout << "\n--- SJF Scheduling ---" << std::endl;
    sjfScheduler.schedule(cpu);
    std::cout << SEP << std::endl;

    RR rrScheduler(10);
    loadTasks(rrScheduler);
    std::cout << "\n--- Round Robin Scheduling (Quantum = 10) ---" << std::endl;
    rrScheduler.schedule(cpu);
    std::cout << SEP << std::endl;

    Priority priorityScheduler;
    loadTasks(priorityScheduler);
    std::cout << "\n--- Priority Scheduling ---" << std::endl;
    priorityScheduler.schedule(cpu);
    std::cout << SEP << std::endl;

    PriorityRR priorityRRScheduler(10);
    loadTasks(priorityRRScheduler);
    std::cout << "\n--- Priority with Round Robin Scheduling (Quantum = 10) ---" << std::endl;
    priorityRRScheduler.schedule(cpu);
    std::cout << SEP << std::endl;

    std::cout << "\nSimulation complete." << std::endl;

    return 0;
}
