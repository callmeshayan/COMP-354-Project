/**
 * @file Scheduler.cpp
 * @brief Implementation of the Scheduler base class for the CPU Scheduling Simulator.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "Scheduler.h"

/**
 * @brief Adds a task to the back of the scheduling queue.
 *
 * Appends the given Task pointer to the end of taskList,
 * making it available for the scheduling algorithm to process.
 *
 * @param task Pointer to the Task to be scheduled.
 */
void Scheduler::addTask(Task* task) {
    taskList.push_back(task);
}

/**
 * @brief Destructor — releases all dynamically allocated Task objects.
 *
 * Iterates through taskList, deletes each Task pointer to free
 * heap memory, then clears the list to leave it in a clean state.
 */
Scheduler::~Scheduler() {
    for (Task* task : taskList) {
        delete task;
    }
    taskList.clear();
}
