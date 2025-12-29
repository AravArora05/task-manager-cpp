# C++ CLI Task Manager

A simple command-line tool to manage your daily tasks. I built this to practice file handling, vectors, and separating code into multiple files in C++.

## Features
* **Add Tasks:** Quickly add new items to your to-do list.
* **View List:** See all current tasks with their status (Completed/Not Completed).
* **Mark as Done:** Update the status of tasks when you finish them.
* **Auto-Save:** Tasks are automatically saved to `tasks.txt` upon exit and loaded when you start the program.


### 1. Compile
Since the project is split into multiple files, compile it using:

```bash
g++ main.cpp tasks.cpp -o todo
```
