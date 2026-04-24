/**
 * @file Task.cpp
 * @brief Implementation of the Task class for the CPU Scheduling Simulator.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

#include "Task.h"

/**
 * @brief Constructs a Task with the given name, priority, and burst time.
 *
 * Initializes all member variables. Sets remaining_burst equal to burst,
 * representing a task that has not yet been scheduled.
 *
 * @param name     The unique identifier for the task (e.g., "T1").
 * @param priority The scheduling priority of the task (1 = lowest, 10 = highest).
 * @param burst    The total CPU burst time required by the task (ms).
 */
Task::Task(const std::string& name, int priority, int burst)
    : name(name), priority(priority), burst(burst), remaining_burst(burst) {}

/**
 * @brief Returns the name of the task.
 * @return The task name as a std::string.
 */
std::string Task::getName() const {
    return name;
}

/**
 * @brief Returns the scheduling priority of the task.
 * @return Integer priority value (1–10).
 */
int Task::getPriority() const {
    return priority;
}

/**
 * @brief Returns the original CPU burst time of the task.
 * @return Total burst time in milliseconds.
 */
int Task::getBurst() const {
    return burst;
}

/**
 * @brief Returns the remaining CPU burst time of the task.
 *
 * This value decreases as the task is executed by preemptive schedulers.
 *
 * @return Remaining burst time in milliseconds.
 */
int Task::getRemainingBurst() const {
    return remaining_burst;
}

/**
 * @brief Sets the remaining CPU burst time.
 *
 * Called by preemptive scheduling algorithms (e.g., Round Robin,
 * Priority with Round Robin) after each time slice.
 *
 * @param remaining New remaining burst time (should be >= 0).
 */
void Task::setRemainingBurst(int remaining) {
    remaining_burst = remaining;
}

/**
 * @brief Default execute implementation (no-op).
 *
 * Subclasses may override this for task-specific behaviour.
 * FCFS and other schedulers drive execution via CPU::run().
 */
void Task::execute() {
    // Default: execution is driven by the scheduler via CPU::run()
}
