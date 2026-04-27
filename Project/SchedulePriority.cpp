/**
 * @file SchedulePriority.cpp
 * @brief Implementation of the Priority scheduling algorithm.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "SchedulePriority.h"
#include <iostream>

/**
 * @brief Schedules tasks using the non-preemptive Priority algorithm.
 *
 * Sorts all tasks in the taskList by priority in descending order
 * (higher number = higher importance), then executes each task on
 * the CPU for its full burst time. Calculates and prints the average
 * waiting time after all tasks complete.
 *
 * @param cpu Reference to the CPU used to execute each task.
 */
void Priority::schedule(CPU& cpu) {
    // Sort tasks by priority — highest priority runs first
    taskList.sort([](Task* a, Task* b) {
        return a->getPriority() > b->getPriority();
    });

    // Tasks with equal priority maintain their original order

    int waitingTime  = 0;
    int totalWaiting = 0;
    int count        = 0;

    for (Task* task : taskList) {
        // Each task waits for all higher priority tasks to finish
        totalWaiting += waitingTime;
        cpu.run(task, task->getBurst());
        waitingTime += task->getBurst();
        count++;
    }

    std::cout << "Average waiting time: "
              << (double)totalWaiting / count
              << " time units." << std::endl;
}
