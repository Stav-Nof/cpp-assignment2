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
    CHECK(y.relation("greatF")=="great-grandfather");
    CHECK(y.relation("greatM")=="great-grandmother");
    CHECK(y.find("great-grandfather")=="greatF");
    CHECK(y.find("great-grandmother")=="greatM");
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandmother"), std::exception);
    y.addMother("Yosi", "greatM1");
    y.addFather("Yosi", "greatF1");
    CHECK(y.relation("greatF1")=="great-grandfather");
    CHECK(y.relation("greatM1")=="great-grandmother");
    y.addMother("Michel", "greatM2");
    y.addFather("Michel", "greatF2");
    CHECK(y.relation("greatF2")=="great-grandfather");
    CHECK(y.relation("greatM2")=="great-grandmother");
    y.addMother("Meri", "greatM3");
    y.addFather("Meri", "greatF3");
    CHECK(y.relation("greatF3")=="great-grandfather");
    CHECK(y.relation("greatM3")=="great-grandmother");
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(find("great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(find("great-great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great-great-great-grandmother"), std::exception);
}

TEST_CASE("Test case 2") {
   	family::Tree s ("Stav");
    s.addFather("Stav", "Eli");
    s.addMother("Stav", "Tali");
    s.addFather("Eli", "Eliezer");
    s.addMother("Eli", "Noga");
    s.addFather("Tali", "Shimon");
    s.addMother("Tali", "Miriam");
    CHECK(s.relation("Eli")=="father");
    CHECK(s.relation("Tali")=="mother");
    CHECK(s.relation("Eliezer")=="grandfather");
    CHECK(s.relation("Noga")=="grandmother");
    CHECK(s.relation("Shimon")=="grandfather");
    CHECK(s.relation("Miriam")=="grandmother");
    CHECK(s.find("father")=="Eli");
    CHECK(s.find("mother")=="Tali");
    CHECK(s.find("grandfather")=="Eliezer" || s.find("grandfather")=="Shimon");
    CHECK(s.find("grandmother")=="Noga" || s.find("grandmother")=="Miriam");
    CHECK_THROWS_AS(relation("Yuval"), std::exception);
    CHECK_THROWS_AS(relation("Shaked"), std::exception);
    CHECK_THROWS_AS(relation("Lital"), std::exception);
    CHECK_THROWS_AS(relation("Shani"), std::exception);
    CHECK_THROWS_AS(relation("Yinon"), std::exception);
    CHECK_THROWS_AS(find("great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great- grandmother"), std::exception);
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great- grandmother"), std::exception);
    s.addFather("Eliezer", "Baba");
    s.addMother("Eliezer", "Tata");
    s.addFather("Noga", "Papa");
    s.addMother("Noga", "Nana");
    s.addFather("Miriam", "David");
    s.addMother("Miriam", "Mama");
    CHECK(s.relation("Papa")=="great-grandfather");
    CHECK(s.relation("Nana")=="great-grandmother");
    CHECK(s.relation("David")=="great-grandfather");
    CHECK(s.relation("Mama")=="great-grandmother");
    CHECK(s.relation("Baba")=="great-grandfather");
    CHECK(s.relation("Tata")=="great-grandmother");
    CHECK_THROWS_AS(find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(find("great-great- grandmother"), std::exception);
    CHECK_THROWS_AS(find("great-great-great- grandmother"), std::exception);
    s.addFather("Shimon", "Moris");
    s.addMother("Shimon", "Shontal");
    CHECK(s.relation("Moris")=="great-grandfather");
    CHECK(s.relation("Shontal")=="great-grandmother");
    CHECK_THROWS_AS(relation("Naama"), std::exception);
    CHECK_THROWS_AS(relation("Or"), std::exception);
    CHECK_THROWS_AS(relation("Eran"), std::exception);
    CHECK_THROWS_AS(relation("Yoav"), std::exception);