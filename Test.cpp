#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;




TEST_CASE("Test case 1") {
   	family::Tree y ("Yarin");
    y.addFather("Yarin", "Ran");
	y.addMother("Yarin", "Angela");
    y.addFather("Ran", "Yosi");
    y.addMother("Ran", "Adi");
    y.addFather("Angela", "michel");
    y.addMother("Angela", "meri");
    CHECK(y.relation("Ran")=="father");
    CHECK(y.relation("Angela")=="mother");
    CHECK(y.relation("Yosi")=="grandfather");
    CHECK(y.relation("Adi")=="grandmother");
    CHECK(y.relation("michel")=="grandfather");
    CHECK(y.relation("meri")=="grandmother");
    CHECK(y.find("father")=="Ran");
    CHECK(y.find("mother")=="Angela");
    CHECK(y.find("grandmother")=="Yosi" || y.find("grandmother")=="michel");
    CHECK(y.find("grandmother")=="Adi" || y.find("grandmother")=="meri");
    
}

TEST_CASE("Test case 2") {
    
}