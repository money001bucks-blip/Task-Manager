#include "TaskManager.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>

bool Task_Manager::load_from_file()
{
  std::ifstream inFile(m_fileName);
  if (!inFile.is_open())
  {
    return false;
  }

  m_tasks.clear();

  int id{};
  std::string title{};
  std::string category{};
  int priority{};
  bool isComplited{};
  char delimiter{};

  while (inFile >> id >> delimiter)
  {
    inFile.get();

    std::getline(inFile, title, '|');
    if (!title.empty() && title.back() == ' ')
    {
      title.pop_back();
    }

    std::getline(inFile, category, '|');
    if (!category.empty() && category.back() == ' ')
    {
      category.pop_back();
    }

    char second_delimiter{};
    inFile >> priority >> second_delimiter >> isComplited;

    std::string dummy;
    std::getline(inFile, dummy);

    m_tasks.push_back({id, title, category, priority, isComplited});
  }
  inFile.close();

  return true;
}

void Task_Manager::change_name(int id, std::string name)
{
  load_from_file();
  bool isfind{false};

  if (!isfind)
  {
    for (int i{0}; i < m_tasks.size(); i++)
    {
      if (id == m_tasks[i].id)
      {
        std::cout << "Successfully renamed from " << m_tasks[i].title << " to " << name << '\n';
        m_tasks[i].title = name;
        save_to_file();
        isfind = true;
        break;
      }
    }
  }
  if (!isfind)
  {
    std::cout << "Task with ID " << id << " not found" << '\n';
  }
}

void Task_Manager::save_to_file()
{
  std::ofstream outFile(m_fileName);
  if (!outFile.is_open())
  {
    std::cout << "Error opening file to save\n";
    return;
  }

  for (const auto &task : m_tasks)
  {
    outFile << task.id << " | " << task.title << " |" << task.category << "| " << task.priority << " | "
            << task.isComplited << '\n';
  }
  outFile.close();
}

void Task_Manager::add_task(std::string title, std::string category, int priority)
{
  load_from_file();

  int newId{m_tasks.empty() ? 1 : m_tasks.back().id + 1};
  m_tasks.push_back({newId, title, category, priority, false});

  save_to_file();
  std::cout << "Task added successfully! ID: " << newId << '\n';
}

void Task_Manager::show_tasks()
{
  load_from_file();

  if (m_tasks.empty())
  {
    std::cout << "No tasks found.\n";
    return;
  }

  std::cout << "\n--- Your Tasks ---\n";
  for (const auto &task : m_tasks)
  {
    std::cout << "[" << task.id << "] " << task.title << " | " << task.category << " | Priority: " << task.priority
              << " | Status: " << (task.isComplited ? "Done" : "Pending") << '\n';
  }
  std::cout << "------------------" << std::endl;

  std::cout << "Press Enter to continue..." << std::endl;

  std::cin.ignore(1000, '\n');

  std::cin.get();
}

bool Task_Manager::delete_task(int delID)
{
  load_from_file();

  bool was_deleted = false;

  for (int i{0}; i < m_tasks.size(); i++)
  {
    if (m_tasks[i].id == delID)
    {
      m_tasks.erase(m_tasks.begin() + i);
      was_deleted = true;
      break;
    }
  }

  if (was_deleted)
  {
    for (size_t i{0}; i < m_tasks.size(); ++i)
    {
      m_tasks[i].id = i + 1;
    }
    save_to_file();
    std::cout << "Task with ID " << delID << " successfully deleted.\n";
    return true;
  }
  else
  {
    std::cout << "Task with ID " << delID << " not found!\n";
    return false;
  }
}

bool Task_Manager::completed_incompleted(int idTask, bool iscomp)
{
  load_from_file();

  for (int i{0}; i < m_tasks.size(); i++)
  {
    if (m_tasks[i].id == idTask)
    {
      m_tasks[i].isComplited = iscomp;
      break;
    }
  }

  save_to_file();
  return false;
}