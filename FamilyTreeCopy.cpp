#include <iostream>
#include "FamilyTree.hpp"

//person
family::person::person(string name, string type){
    
}

void family::person::addParent(string name, string type, string fOrM){
 
}

string family::person::get_type(){
 
}
string family::person::get_name(){
 
}
family::person* family::person::get_father(){
    
}
family::person* family::person::get_mother(){
    
}
family::person::~person(){
    
}
family::person* family::person::search(string name){
 
}

family::person* family::person::find(string type){
    
}

void family::person::remove(){

}


//Tree
family::Tree::Tree(string name){
   
}

family::Tree family::Tree::addFather(string child, string fatherName){
   
}

family::Tree family::Tree::addMother(string child, string motherName){
  
    
}

string family::Tree::relation(string name){
   
}

string family::Tree::find(string type){
  
}

void family::Tree::display(){

}
void family::Tree::remove(string name){
  
}

family::Tree::~Tree(){
 
}

//static
static string family::typeDefM(string type){
    
}

static string family::typeDefF(string type){
   
}