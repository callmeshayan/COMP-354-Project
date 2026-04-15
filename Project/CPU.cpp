/**
 * @file CPU.cpp
 * @brief Implementation of the CPU class for the CPU Scheduling Simulator.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "CPU.h"
#include <iostream>

/**
 * @brief Executes a task for a given number of time units.
 *
 * Prints the task's name, priority, and burst time to the console,
 * along with how many time units it is being run for in this slice.
 *
 * @param task  Pointer to the Task object being executed.
 * @param slice Number of time units allocated for this execution.
 */
void CPU::run(Task* task, int slice) {
    std::cout << "Executing task = [" << task->getName()
              << "], priority = [" << task->getPriority()
              << "], burst = [" << task->getBurst()
              << "] for " << slice << " time unit(s)." << std::endl;
}
