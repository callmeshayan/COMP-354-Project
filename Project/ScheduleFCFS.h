#pragma once

#include "Scheduler.h"

/**
 * @file ScheduleFCFS.h
 * @brief First Come First Served (FCFS) CPU scheduling algorithm.
 *
 * Tasks are executed in the exact order they were added to the scheduler,
 * with no preemption. The simplest of all scheduling algorithms.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class FCFS
 * @brief Implements the First Come First Served scheduling algorithm.
 *
 * Inherits from Scheduler and overrides schedule() to process tasks
 * sequentially in arrival order.
 */
class FCFS : public Scheduler {
public:
    /**
     * @brief Schedules and executes all tasks in arrival order.
     *
     * Iterates through the taskList from front to back and runs
     * each task on the CPU for its full burst time.
     *
     * @param cpu Reference to the CPU used to execute each task.
     */
    void schedule(CPU& cpu) override;
};
