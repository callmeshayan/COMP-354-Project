#pragma once

#include "Scheduler.h"

/**
 * @file SchedulePriority.h
 * @brief Priority-based CPU scheduling algorithm.
 *
 * Tasks are sorted by priority and executed in order from highest to lowest.
 * This is a non-preemptive implementation — once a task starts, it runs
 * to completion before the next task begins.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class Priority
 * @brief Implements the non-preemptive Priority scheduling algorithm.
 *
 * Inherits from Scheduler and overrides schedule() to process tasks
 * in descending order of priority value.
 */
class Priority : public Scheduler {
public:
    // Higher priority number means higher importance
    // Non-preemptive: highest priority task runs to completion first
    /**
     * @brief Schedules tasks in descending order of priority.
     *
     * Sorts the taskList by priority (highest first), then runs each
     * task on the CPU for its full burst time without preemption.
     *
     * @param cpu Reference to the CPU used to execute each task.
     */
    void schedule(CPU& cpu) override;
};
