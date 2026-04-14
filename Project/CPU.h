#pragma once

#include "Task.h"

/**
 * @brief Represents a CPU unit that executes scheduled tasks.
 *
 * The CPU class is responsible for running a given task for a
 * specified number of time units (a time slice), simulating
 * CPU execution in a scheduling environment.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */
class CPU {
public:
    /**
     * @brief Executes a task for a given number of time units.
     *
     * Simulates the CPU running the provided task for exactly
     * @p slice time units. Used by all scheduling algorithms to
     * model CPU execution in a consistent way.
     *
     * @param slice Number of time units to run the task for.
     * @param task  Pointer to the Task object to be executed.
     */
    void run(Task* task, int slice);
};
