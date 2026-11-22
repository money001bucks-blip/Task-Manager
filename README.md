# C++ Task Manager 🚀

A robust, object-oriented console-based Task Management application written in modern C++. Designed with clean separation of concerns, persistent file storage, and bulletproof input parsing.

---

## ✨ Features

- **Object-Oriented Architecture:** Built around a clean `Task_Manager` class implementing proper encapsulation and state management.
- **Persistent Storage:** Automatically saves and loads tasks from a local text file, ensuring no data loss between sessions.
- **Smart ID Re-indexing:** Automatically reorganizes task IDs sequentially when a task is deleted to keep the list clean.
- **Robust Parsing:** Safely handles file records, delimiters, and string spacing to prevent parsing errors.
- **Status & Priority Tracking:** Manage task priorities and toggle completion status effortlessly.

---

## 🛠️ Tech Stack

- **Language:** C++ (C++20 standards)
- **Concepts:** Object-Oriented Programming (OOP), File I/O (`<fstream>`), Vectors, String Manipulation.
- **Environment:** MSYS2 / GCC / VS Code.

---

## 🚀 Getting Started

### Prerequisites
Make sure you have a modern C++ compiler supporting C++20 installed (e.g., `g++` via MSYS2 or MinGW).

### Compilation
Compile the project using your terminal or VS Code build task:
```bash
g++ -std=c++20 main.cpp -o main.exe
