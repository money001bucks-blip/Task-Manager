#pragma once
#include "Task.hpp"
#include <string>
#include <vector>

class Task_Manager
{
private:
  std::string m_fileName{"Text.txt"};
  std::vector<Task> m_tasks{};

  bool load_from_file();
  void save_to_file();

public:
  void add_task(std::string title, std::string category, int priority);
  void show_tasks();
  bool delete_task(int delID);
  void change_name(int id,std::string name);
  bool completed_incompleted(int idTask, bool iscomp);
};