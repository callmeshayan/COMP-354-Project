#pragma once

#include "Scheduler.h"

/**
 * @file ScheduleSJF.h
 * @brief Shortest Job First (SJF) CPU scheduling algorithm.
 *
 * Tasks are sorted by burst time before execution. The task with the
 * shortest burst time runs first, minimizing average waiting time.
 * This implementation is non-preemptive.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class SJF
 * @brief Implements the non-preemptive Shortest Job First scheduling algorithm.
 *
 * Inherits from Scheduler and overrides schedule() to process tasks
 * in ascending order of CPU burst time.
 */
class SJF : public Scheduler {
public:
    // Shorter burst times are prioritized to minimize average waiting time
    /**
     * @brief Schedules tasks in order of shortest burst time first.
     *
     * Sorts the taskList by burst time in ascending order, then runs
     * each task on the CPU for its full burst time without preemption.
     *
     * @param cpu Reference to the CPU used to execute each task.
     */
    void schedule(CPU& cpu) override;
};
