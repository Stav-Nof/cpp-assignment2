#include <iostream>
#include "FamilyTree.hpp"

//person
family::person::person(string name, string type){
    this->_name = name;
    this->_type = type;
    this->_father = NULL;
    this->_mother = NULL;
}

void family::person::addParent(string name, string type){
    family::person *parent = new family::person(name, type);
    if (type == "father"){
        this->_father = parent;
    }
    if (type == "mother"){
        this->_mother = parent;
    }
    else{
        throw "type not father nor mother";
    }
}

string family::person::get_type(){
    return this->_type;
}
family::person::~person(){
    delete this;
}


//Tree
family::Tree::Tree(string name){

}

family::Tree family::Tree::addFather(string child, string father){
    return *this;
}

family::Tree family::Tree::addMother(string child, string mother){
    return *this;

}

string family::Tree::relation(string name){
    return "ans";
}

string family::Tree::find(string name){
    return "ans";
}

void family::Tree::display(){

}
void family::Tree::remove(string name){

}

family::Tree::~Tree(){

}