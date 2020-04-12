#include <iostream>
#include "FamilyTree.hpp"

//person
family::person::person(string name, string type){

}

void family::person::addParent(string name, string type){

}

string family::person::get_type(){
    return "ans";
}
family::person::~person(){

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