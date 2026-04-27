#pragma once

#include "Scheduler.h"

/**
 * @file SchedulePriorityRR.h
 * @brief Priority with Round Robin CPU scheduling algorithm.
 *
 * Tasks are grouped by priority level. Higher priority groups are scheduled
 * before lower ones. Within each group, Round Robin scheduling is applied
 * using a fixed time quantum, ensuring fairness among tasks of equal priority.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class PriorityRR
 * @brief Implements the Priority with Round Robin scheduling algorithm.
 *
 * Inherits from Scheduler and overrides schedule() to first group tasks
 * by priority, then apply Round Robin within each group.
 */
class PriorityRR : public Scheduler {
private:
    // Time slice allocated to each task within its priority group
    int timeQuantum;

public:
    /**
     * @brief Constructs a PriorityRR scheduler with the given time quantum.
     * @param timeQuantum Number of time units each task runs per RR cycle (ms).
     */
    PriorityRR(int timeQuantum);

    // Higher priority groups are scheduled before lower ones
    // Within each group Round Robin is applied
    // Combines fairness of RR within each priority group
    /**
     * @brief Schedules tasks using Priority with Round Robin algorithm.
     *
     * Groups tasks by priority in descending order, then applies Round Robin
     * with the configured time quantum within each priority group.
     *
     * @param cpu Reference to the CPU used to execute each task.
     */
    void schedule(CPU& cpu) override;
};
