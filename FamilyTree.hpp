#pragma once

#include <iostream>
#include <string>
using namespace std;


namespace family{

    class Node{

        string name;
        Node* father;
        Node* mother;
        string type;
    }

    public:

    Node(string name,string type){
        this->name = name;
        father = NULL;
        mother = NULL;
        this->type=type;
    }

    string getName(){
        return this->name;
    }

    Node* getMother(){
        return this->mother;
    }
    Node* getFather(){
        return this->father;
    }

}
class family{ 
    class Tree{
        private:
        const Node* root;
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
