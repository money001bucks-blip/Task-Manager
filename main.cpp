#include "TaskManager.hpp"
#include <iostream>

int main()
{
  Task_Manager manager{};

  int option{};
  while (true)
  {
    std::cout << "----Menu----\n"
              << "1.Add task\n"
              << "2.Show tasks\n"
              << "3.Delete task\n"
              << "4.Change Completed/Incompleted\n"
              << "5.Change the name\n"
              << "6.Exit\n"
              << "Choose an operation: ";

    if (!(std::cin >> option))
    {
      std::cout << "Invalid operation! Try again!\n";
    }

    switch (option)
    {
    case 1:
    {
      std::string title;
      std::string category;
      int priority;

      std::cin.ignore();

      std::cout << "Enter title: ";
      std::getline(std::cin, title);

      while (!title.empty() && title.front() == ' ')
      {
        title.erase(0, 1);
      }
      while (!title.empty() && title.back() == ' ')
      {
        title.pop_back();
      }

      std::cout << "Enter category: ";
      std::getline(std::cin, category);

      while (!category.empty() && category.front() == ' ')
      {
        category.erase(0, 1);
      }
      while (!category.empty() && category.back() == ' ')
      {
        category.pop_back();
      }

      std::cout << "Enter priority: ";
      std::cin >> priority;

      manager.add_task(title, category, priority);

      break;
    }

    case 2:
    {
      manager.show_tasks();

      break;
    }

    case 3:
    {
      std::cout << "Enter ID to delete(): ";
      int delID{};
      if (!(std::cin >> delID))
      {
        std::cout << "Invalid type!\n";
        break;
      }

      manager.delete_task(delID);
      break;
    }

    case 4:
    {
      int idTask{};
      bool iscomp;
      std::cout << "Enter ID of the task and completed/not(1/0): ";
      if (!(std::cin >> idTask >> iscomp))
      {
        std::cout << "Invalid type!\n";
        break;
      }

      manager.completed_incompleted(idTask, iscomp);
      break;
    }

    case 5:
    {
      int idTask{};
      std::string newname{};
      std::cout << "Enter ID: ";
      std::cin >> idTask;

      std::cout << "Enter new name: ";
      std::getline(std::cin >> std::ws, newname);

      manager.change_name(idTask, newname);
      break;
    }

    default:
    {
      std::cout << "Thank for using!\n";

      return 0;
    }
    }
  }
}