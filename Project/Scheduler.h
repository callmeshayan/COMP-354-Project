#pragma once

#include "Task.h"
#include "CPU.h"
#include <list>

/**
 * @file Scheduler.h
 * @brief Abstract base class for all CPU scheduling algorithms.
 *
 * All concrete scheduling algorithms (FCFS, SJF, Round Robin, Priority,
 * Priority with Round Robin) must inherit from this class and implement
 * the schedule() method.
 *
 * @author Shayan NaghashpourShoushtari
 * @course COMP-354 — Operating Systems
 */

/**
 * @class Scheduler
 * @brief Defines the interface for all CPU scheduling algorithm implementations.
 */
class Scheduler {
protected:
    // Holds all tasks waiting to be scheduled
    std::list<Task*> taskList;

public:
    /**
     * @brief Adds a task to the scheduler's task list.
     * @param task Pointer to the Task to be added.
     */
    void addTask(Task* task);

    /**
     * @brief Schedules and executes all tasks using the implemented algorithm.
     *
     * Must be overridden by each concrete scheduling class.
     *
     * @param cpu Reference to the CPU used to execute tasks.
     */
    virtual void schedule(CPU& cpu) = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes.
     */
    virtual ~Scheduler();
};
