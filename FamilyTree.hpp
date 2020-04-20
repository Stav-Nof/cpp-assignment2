#pragma once

#include <iostream>
using namespace std;


class family{
    public:
    class person{
    private:
    string _name;
    string _type;
    person* _father;
    person* _mother;
    public:
    person(string name, string type);
    void addParent(string name, string type);
    string get_type();
    string get_name();
    person* get_father();
    person* get_mother();
    person* search(string name);
    ~person();
    };

    class Tree{
        private:
        const person* _head;
        public:
        Tree(string name);
        Tree addFather(string child, string father);
        Tree addMother(string child, string mother);
        string relation(string name);
        string find(string name);
        void display();
        void remove(string name);
        ~Tree();
    };
};
