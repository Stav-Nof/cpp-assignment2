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
    y.addFather("Angela", "Michel");
    y.addMother("Angela", "Meri");
    CHECK(y.relation("Ran")=="father");
    CHECK(y.relation("Angela")=="mother");
    CHECK(y.relation("Yosi")=="grandfather");
    CHECK(y.relation("Adi")=="grandmother");
    CHECK(y.relation("Michel")=="grandfather");
    CHECK(y.relation("Meri")=="grandmother");
    CHECK(y.find("father")=="Ran");
    CHECK(y.find("mother")=="Angela");
    CHECK(y.find("grandfather")=="Yosi" || y.find("grandfather")=="Michel");
    CHECK(y.find("grandmother")=="Adi" || y.find("grandmother")=="Meri");
    CHECK_THROWS_AS(relation("Stav"), std::exception);
    CHECK_THROWS_AS(relation("Jordan"), std::exception);
    CHECK_THROWS_AS(find("great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-grandmother"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandmother"), std::exception);
    y.addMother("Adi", "greatM");
    y.addFather("Adi", "greatF");
    CHECK(y.relation("greatM")=="great-grandfather");
    CHECK(y.relation("greatF")=="great-grandmother");
    CHECK(y.find("great-grandfather")=="greatM");
    CHECK(y.find("great-grandmother")=="greatF");
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandmother"), std::exception);
    y.addMother("Yosi", "greatM1");
    y.addFather("Yosi", "greatF1");
    CHECK(y.relation("greatM1")=="great-grandfather");
    CHECK(y.relation("greatF1")=="great-grandmother");
    y.addMother("Michel", "greatM2");
    y.addFather("Michel", "greatF2");
    CHECK(y.relation("greatM2")=="great-grandfather");
    CHECK(y.relation("greatF2")=="great-grandmother");
    y.addMother("Meri", "greatM3");
    y.addFather("Meri", "greatF3");
    CHECK(y.relation("greatM3")=="great-grandfather");
    CHECK(y.relation("greatF3")=="great-grandmother");//28
}

TEST_CASE("Test case 2") {
    
}