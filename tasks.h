#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

// function declarations
void printMenu();
void loadTasks(vector<Task>& tasks, const string& filename);
void saveTasks(const vector<Task>& tasks, const string& filename);
void viewTasks(const vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void completeTask(vector<Task>& tasks);

#endif
