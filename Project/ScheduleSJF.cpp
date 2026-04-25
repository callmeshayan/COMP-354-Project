/**
 * @file ScheduleSJF.cpp
 * @brief Implementation of the Shortest Job First (SJF) scheduling algorithm.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "ScheduleSJF.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Schedules tasks using the Shortest Job First (non-preemptive) algorithm.
 *
 * Sorts all tasks in the taskList by burst time in ascending order,
 * then executes each task on the CPU for its full burst time.
 * Calculates and prints the average waiting time after all tasks complete.
 *
 * @param cpu Reference to the CPU used to execute each task.
 */
void SJF::schedule(CPU& cpu) {
    // Sort tasks by burst time — shortest first
    taskList.sort([](Task* a, Task* b) {
        return a->getBurst() < b->getBurst();
    });

    // Sorting ensures the task with the least burst runs first

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
