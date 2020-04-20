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
string family::person::get_name(){
    return this->_name;
}
family::person* family::person::get_father(){
    return this->_father;
}
family::person* family::person::get_mother(){
    return this->_mother;
}
family::person::~person(){
    delete this;
}
family::person* family::person::search(string name){
    if (this->_name == name){
        return this;
    }
    else{
        family::person* ansF = NULL;
        family::person* ansM = NULL;
        if (this->_father != NULL) ansF = (this->_father)->search;
        if (this->_mother != NULL) ansM = (this->get_mother)->search;
        if (ansF == NULL && ansM != NULL){
            return ansM; 
        }
        if (ansF != NULL && ansM == NULL){
            return ansF; 
        }
    }
    return NULL;
}


//Tree
family::Tree::Tree(string name){
    family::person *person = new family::person(name, "me");
    this->_head = person;
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