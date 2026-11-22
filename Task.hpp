#pragma once
#include <string>

struct Task
{
    int id{};
    std::string title{};
    std::string category{};
    int priority{};
    bool isComplited{};
};