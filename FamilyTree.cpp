#include <iostream>
#include "FamilyTree.hpp"

//person
family::person::person(string name, string type){
    this->_name = name;
    this->_type = type;
    this->_father = NULL;
    this->_mother = NULL;
}

void family::person::addParent(string name, string type, string fOrM){
    family::person *parent = new family::person(name, type);
    if (fOrM == "M"){
        this->_father = parent;
        return;
    }
    if (fOrM == "F"){
        this->_mother = parent;
        return;
    }
    else{
        throw "Type not defined";
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
void family::person::set_father(family::person* p){
    this->_father = p;
}
void family::person::set_mother(family::person* p){
this->_mother = p;
}
family::person::~person(){
}
family::person* family::person::search(string name){
    if (this->_name == name){
        return this;
    }
    family::person* ansF = NULL;
    family::person* ansM = NULL;
    if (this->_father != NULL) ansF = (this->get_father())->search(name);
    if (this->_mother != NULL) ansM = (this->get_mother())->search(name);
    if (ansM != NULL){
        return ansM; 
    }
    if (ansF != NULL){
        return ansF; 
    }
    return NULL;
}

family::person* family::person::searchSon(string name){
    if (this->_father->_name == name || this->_mother->_name == name){
        return this;
    }
    family::person* ansF = NULL;
    family::person* ansM = NULL;
    if (this->_father != NULL) ansF = (this->get_father())->searchSon(name);
    if (this->_mother != NULL) ansM = (this->get_mother())->searchSon(name);
    if (ansM != NULL){
        return ansM; 
    }
    if (ansF != NULL){
        return ansF; 
    }
    return NULL;
}

family::person* family::person::find(string type){
    if (this->_type == type){
        return this;
    }
    family::person* ansF = NULL;
    family::person* ansM = NULL;
    if (this->_father != NULL) ansF = (this->_father)->find(type);
    if (this->_mother != NULL) ansM = (this->_mother)->find(type);
    if (ansM != NULL){
        return ansM; 
    }
    if (ansF != NULL){
        return ansF; 
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

family::Tree& family::Tree::addFather(string childName, string fatherName){
    family::person* toAdd = (this->_head)->family::person::search(childName);          
    if (toAdd == NULL) throw "name not found";
    if (toAdd->get_father() != NULL) throw "Father already exists";
    string type = typeDefM(toAdd->get_type());
    toAdd->family::person::addParent(fatherName, type ,"M");
    return *this;
}

family::Tree& family::Tree::addMother(string childName, string motherName){
    family::person* toAdd = (this->_head)->family::person::search(childName);          
    if (toAdd == NULL) throw "name not found";
    if (toAdd->get_mother() != NULL) throw "Mother already exists";
    string type = typeDefF(toAdd->get_type());
    toAdd->family::person::addParent(motherName, type, "F");
    return *this;
}

string family::Tree::relation(string name){
    family::person* toReturn = (this->_head)->family::person::search(name);
    if (toReturn == NULL) return "unrelated";
    return toReturn->get_type();
}

string family::Tree::find(string type){
    family::person* toReturn = (this->_head)->family::person::find(type);
    if (toReturn == NULL) throw "find failed";
    return toReturn->get_name();
}

void family::Tree::display(){

}

void family::Tree::remove(string name){
    if (name == this->_head->get_name()) throw name + "is root";
    family::person* toRemove = (this->_head)->family::person::search(name); 
    if (toRemove == NULL) throw "name not found";
    family::person* son = (this->_head)->family::person::searchSon(name);
    if (toRemove == NULL) throw "son not found";
    if (son->get_father()->get_name() == name) son->set_father(NULL);
    if (son->get_mother()->get_name() == name) son->set_mother(NULL);
    toRemove->remove();
}

family::Tree::~Tree(){
    this->_head->remove();
}

//static
static string family::typeDefM(string type){
    if (type == "me") return "father";
    if (type == "father" || type == "mother") return "grandfather";
    type.replace(type.length()-6, 2 ,"fa");
    return "great-" + type;
}

static string family::typeDefF(string type){
    if (type == "me") return "mother";
    if (type == "mother" || type == "father") return "grandmother";
    type.replace(type.length()-6, 2 ,"mo");
    return "great-" + type;
}