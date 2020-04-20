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
    if (this->_father != NULL) return this->_father;
    throw "father does not exist";
}
family::person* family::person::get_mother(){
    if (this->_mother != NULL) return this->_mother;
    throw "mother does not exist";
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
        if (this->_father != NULL) ansF = (this->get_father())->search(name);
        if (this->_mother != NULL) ansM = (this->get_mother())->search(name);
        if (ansF == NULL && ansM != NULL){
            return ansM; 
        }
        if (ansF != NULL && ansM == NULL){
            return ansF; 
        }
    }
    return NULL;
}

family::person* family::person::find(string type){
        if (this->_type == type){
        return this;
    }
    else{
        family::person* ansF = NULL;
        family::person* ansM = NULL;
        if (this->_father != NULL) ansF = (this->_father)->find(type);
        if (this->_mother != NULL) ansM = (this->_mother)->find(type);
        if (ansF == NULL && ansM != NULL){
            return ansM; 
        }
        if (ansF != NULL && ansM == NULL){
            return ansF; 
        }
    }
    return NULL;
}

void family::person::remove(){
    if (this->_father != NULL) this->_father->remove();
    if (this->_mother != NULL) this->_mother->remove();
    delete this;
}


//Tree
family::Tree::Tree(string name){
    family::person *person = new family::person(name, "me");
    this->_head = person;
}

family::Tree family::Tree::addFather(string child, string fatherName){
    family::person* toAdd = (this->_head)->family::person::search(child);          
    if (toAdd == NULL){
        throw "name not found";
    }
    string type = typeDefM(toAdd->get_type());
    toAdd->family::person::addParent(fatherName, type);
    return *this;
}

family::Tree family::Tree::addMother(string child, string motherName){
    family::person* toAdd = (this->_head)->family::person::search(child);          
    if (toAdd == NULL){
        throw "name not found";
    }
    string type = typeDefF(toAdd->get_type());
    toAdd->family::person::addParent(motherName, type);
    return *this;
}

string family::Tree::relation(string name){
    family::person* toReturn = (this->_head)->family::person::search(name);  
    return toReturn->get_type();
}

string family::Tree::find(string type){
    family::person* toReturn = (this->_head)->family::person::find(type);
    return toReturn->get_name();
}

void family::Tree::display(){

}
void family::Tree::remove(string name){
    family::person* toRemove = (this->_head)->family::person::search(name); 
    if (toRemove == NULL) throw "name not found";
    toRemove->remove();
}

family::Tree::~Tree(){
    this->_head->remove();
    delete this;
}

//static
static string family::typeDefM(string type){
    if (type == "me") return "father";
    if (type == "father") return "grandfather";
    return "great-" + type;
}

static string family::typeDefF(string type){
    if (type == "me") return "mother";
    if (type == "mother") return "grandmother";
    return "great-" + type;
}