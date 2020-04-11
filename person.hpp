#pragma once

#include <iostream>


class person{
private:
    std::string _name;
    std::string _type;
    person* _father;
    person* _mother;
public:
    person(std::string name, std::string type);
    void addParent(std::string name, std::string type);
    std::string get_type();
    ~person();
};
