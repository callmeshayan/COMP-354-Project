/**
 * @file ScheduleRR.cpp
 * @brief Implementation of the Round Robin (RR) scheduling algorithm.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "ScheduleRR.h"
#include <iostream>
#include <queue>

/**
 * @brief Constructs a Round Robin scheduler with the specified time quantum.
 * @param timeQuantum Number of time units each task is allowed to run per cycle.
 */
RR::RR(int timeQuantum) : timeQuantum(timeQuantum) {}

/**
 * @brief Schedules tasks using the Round Robin algorithm.
 *
 * Loads all tasks into a ready queue and cycles through them, giving each
 * task up to timeQuantum units of CPU time per iteration. Tasks that are
 * not finished are re-enqueued at the back of the queue.
 * Calculates and prints average waiting time after all tasks complete.
 *
 * @param cpu Reference to the CPU used to execute each task.
 */
void RR::schedule(CPU& cpu) {
    std::queue<Task*> readyQueue;

    // Load all tasks into the ready queue
    for (Task* task : taskList) {
        readyQueue.push(task);
    }

    int totalWaiting = 0;
    int currentTime  = 0;
    int count        = taskList.size();

    while (!readyQueue.empty()) {
        Task* task = readyQueue.front();
        readyQueue.pop();

        // Preempt task if burst remaining exceeds the time quantum
        if (task->getRemainingBurst() > timeQuantum) {
            // Task not finished — run for quantum and re-enqueue
            cpu.run(task, timeQuantum);
            task->setRemainingBurst(task->getRemainingBurst() - timeQuantum);
            readyQueue.push(task);
            currentTime += timeQuantum;
        } else {
            // Task will complete in this cycle
            totalWaiting += currentTime;
            cpu.run(task, task->getRemainingBurst());
            currentTime += task->getRemainingBurst();
        }
    }

    std::cout << "Average waiting time: "
              << (double)totalWaiting / count
              << " time units." << std::endl;
}
