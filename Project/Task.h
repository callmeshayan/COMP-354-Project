#pragma once

#include <string>

class Task {
protected:
    std::string name;
    int priority;
    int burst;
    int remaining_burst;

public:
    // Constructor
    Task(const std::string& name, int priority, int burst);

    // Accessors
    std::string getName() const;
    int getPriority() const;
    int getBurst() const;
    int getRemainingBurst() const;

    // Modifier
    void setRemainingBurst(int remaining);

    // Virtual function
    virtual void execute();
};
