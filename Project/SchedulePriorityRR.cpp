/**
 * @file SchedulePriorityRR.cpp
 * @brief Implementation of the Priority with Round Robin scheduling algorithm.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "SchedulePriorityRR.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>

/**
 * @brief Constructs a PriorityRR scheduler with the specified time quantum.
 * @param timeQuantum Number of time units each task runs per RR cycle (ms).
 */
PriorityRR::PriorityRR(int timeQuantum) : timeQuantum(timeQuantum) {}

/**
 * @brief Schedules tasks using the Priority with Round Robin algorithm.
 *
 * Groups tasks into priority buckets using a std::map, then processes
 * each group from highest to lowest priority. Within each group, Round
 * Robin scheduling is applied using the configured time quantum.
 * Calculates and prints average waiting time after all tasks complete.
 *
 * @param cpu Reference to the CPU used to execute each task.
 */
void PriorityRR::schedule(CPU& cpu) {
    // Group tasks by priority level
    std::map<int, std::queue<Task*>> priorityGroups;
    for (Task* task : taskList) {
        priorityGroups[task->getPriority()].push(task);
    }

    int totalWaiting = 0;
    int currentTime  = 0;
    int count        = taskList.size();

    // Process highest priority group first using reverse iteration
    for (auto it = priorityGroups.rbegin(); it != priorityGroups.rend(); ++it) {
        // Each priority level gets its own Round Robin cycle
        std::queue<Task*>& group = it->second;

        // Apply Round Robin within this priority group
        while (!group.empty()) {
            Task* task = group.front();
            group.pop();

            if (task->getRemainingBurst() > timeQuantum) {
                // Preempt task and re-enqueue within the same priority group
                cpu.run(task, timeQuantum);
                task->setRemainingBurst(task->getRemainingBurst() - timeQuantum);
                group.push(task);
                currentTime += timeQuantum;
            } else {
                // Task completes in this cycle
                totalWaiting += currentTime;
                cpu.run(task, task->getRemainingBurst());
                currentTime += task->getRemainingBurst();
            }
        }
    }

    std::cout << "Average waiting time: "
              << (double)totalWaiting / count
              << " time units." << std::endl;
}
