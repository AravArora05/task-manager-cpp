#include <iostream>
#include <vector>
#include "tasks.h"

using namespace std;

int main() {
    vector<Task> tasks;
    string filename = "tasks.txt";

    // load data at start
    loadTasks(tasks, filename);

    int choice = 0;
    // loop until they pick 4
    while (choice != 4) {
        printMenu();
        
        // check if input is a number
        if (!(cin >> choice)) { 
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        //using switch statment for choice
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                cout << "Ending tasks" << endl;
                saveTasks(tasks, filename);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
