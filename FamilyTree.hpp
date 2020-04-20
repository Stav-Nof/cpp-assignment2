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
    ~person();
    };

    class Tree{
        private:
        const person* _head;
        public:
        Tree(string name);
        person* Tree::search(string name);
        Tree addFather(string child, string father);
        Tree addMother(string child, string mother);
        string relation(string name);
        string find(string name);
        void display();
        void remove(string name);
        ~Tree();
    };
};
