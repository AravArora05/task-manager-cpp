#include <iostream>
#include <fstream>
#include "tasks.h"

using namespace std;

void printMenu() {
    // simple menu
    cout << "\n--- TODO LIST MANAGER ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Done" << endl;
    cout << "4. Save & Exit" << endl;
    cout << "Enter choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    
    // ignore enter key from previous input
    cin.ignore(); 
    
    // get the full line text
    getline(cin, newTask.description); 
    
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:" << endl;
    cout << "--------------------------------" << endl;
    
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    // loop through all tasks to print them
    for (size_t i = 0; i < tasks.size(); ++i) {
        string status = tasks[i].isCompleted ? "[X]" : "[ ]";
        cout << i + 1 << ". " << status << " " << tasks[i].description << endl;
    }
    cout << "--------------------------------" << endl;
}

void completeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter number to mark done: ";
    int index;
    cin >> index;

    // check if the number is valid
    if (index > 0 && index <= (int)tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "Done!" << endl;
    } else {
        cout << "Invalid number." << endl;
    }
}

void saveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        // write bool then desc
        for (const auto& task : tasks) {
            outFile << task.isCompleted << endl;
            outFile << task.description << endl;
        }
        outFile.close();
        cout << "Saved." << endl;
    } else {
        cout << "Error saving file." << endl;
    }
}

void loadTasks(vector<Task>& tasks, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        Task tempTask;
        // keep reading until end of file
        while (inFile >> tempTask.isCompleted) {
            inFile.ignore(); // skip newline
            getline(inFile, tempTask.description);
            tasks.push_back(tempTask);
        }
        inFile.close();
    }
}
