#pragma once

#include "Scheduler.h"

/**
 * @file ScheduleRR.h
 * @brief Round Robin (RR) CPU scheduling algorithm.
 *
 * Each task is given a fixed time slice (quantum) on the CPU. If a task
 * does not complete within its quantum, it is moved to the back of the
 * queue and waits for the next cycle. This continues until all tasks finish.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class RR
 * @brief Implements the Round Robin CPU scheduling algorithm.
 *
 * Inherits from Scheduler and overrides schedule() to cycle through
 * tasks in order, giving each a fixed time quantum per iteration.
 */
class RR : public Scheduler {
private:
    // Time slice allocated to each task per cycle
    int timeQuantum;

public:
    /**
     * @brief Constructs a Round Robin scheduler with the given time quantum.
     * @param timeQuantum Number of time units each task runs per cycle (ms).
     */
    RR(int timeQuantum);

    // Each task gets an equal share of CPU time per cycle
    /**
     * @brief Schedules tasks using the Round Robin algorithm.
     *
     * Cycles through all tasks repeatedly, running each for up to
     * timeQuantum units at a time until all tasks are complete.
     *
     * @param cpu Reference to the CPU used to execute each task.
     */
    void schedule(CPU& cpu) override;
};
