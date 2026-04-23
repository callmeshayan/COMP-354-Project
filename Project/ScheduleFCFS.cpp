#include "ScheduleFCFS.h"
#include <iostream>

/**
 * @brief Schedules tasks using First Come First Served algorithm
 * @author Shayan NaghashpourShoushtari
 * @param cpu Reference to the CPU to execute tasks on
 */
void FCFS::schedule(CPU& cpu) {
    // Tasks are executed in arrival order, no reordering needed
    int waitingTime = 0;
    int totalWaiting = 0;
    int count = 0;

    for (Task* task : taskList) {
        cpu.run(task, task->getBurst());
        totalWaiting += waitingTime;
        waitingTime += task->getBurst();
        count++;
    }

    std::cout << "Average waiting time: "
              << (double)totalWaiting / count
              << " time units." << std::endl;
}
