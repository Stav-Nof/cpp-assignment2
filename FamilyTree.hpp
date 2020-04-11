#pragma once

#include <iostream>
#include "person.hpp"



namespace family{

class Tree{
private:
    const person* head;
public:
    Tree(std::string name);
    Tree addFather(std::string child, std::string father);
    Tree addMother(std::string child, std::string mother);
    std::string relation(std::string name);
    std::string find(std::string name);
    void display();
    void remove(std::string name);
    ~Tree();
};
}
