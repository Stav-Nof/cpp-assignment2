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
    CHECK_THROWS_AS(y.relation("Litul"), std::exception);
    CHECK_THROWS_AS(y.relation("Stuv"), std::exception);
    CHECK_THROWS_AS(y.relation("Stav"), std::exception);
    CHECK_THROWS_AS(y.relation("Jordan"), std::exception);
    CHECK_THROWS_AS(y.find("great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-grandmother"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-grandmother"), std::exception);
    y.addMother("Adi", "greatM");
    y.addFather("Adi", "greatF");
    CHECK(y.relation("greatF")=="great-grandfather");
    CHECK(y.relation("greatM")=="great-grandmother");
    CHECK(y.find("great-grandfather")=="greatF");
    CHECK(y.find("great-grandmother")=="greatM");
    CHECK_THROWS_AS(y.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-grandmother"), std::exception);
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
    CHECK_THROWS_AS(y.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-great-grandmother"), std::exception);
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
    CHECK_THROWS_AS(s.relation("Litul"), std::exception);
    CHECK_THROWS_AS(s.relation("Stuv"), std::exception);
    CHECK_THROWS_AS(s.relation("Yuval"), std::exception);
    CHECK_THROWS_AS(s.relation("Shaked"), std::exception);
    CHECK_THROWS_AS(s.relation("Lital"), std::exception);
    CHECK_THROWS_AS(s.relation("Shani"), std::exception);
    CHECK_THROWS_AS(s.relation("Yinon"), std::exception);
    CHECK_THROWS_AS(s.find("great-grandfather"), std::exception);
    CHECK_THROWS_AS(s.find("great- grandmother"), std::exception);
    CHECK_THROWS_AS(s.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(s.find("great-great- grandmother"), std::exception);
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
    CHECK_THROWS_AS(s.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(s.find("great-great- grandmother"), std::exception);
    CHECK_THROWS_AS(s.find("great-great-great- grandmother"), std::exception);
    s.addFather("Shimon", "Moris");
    s.addMother("Shimon", "Shontal");
    CHECK(s.relation("Moris")=="great-grandfather");
    CHECK(s.relation("Shontal")=="great-grandmother");
    CHECK_THROWS_AS(s.relation("Naama"), std::exception);
    CHECK_THROWS_AS(s.relation("Or"), std::exception);
    CHECK_THROWS_AS(s.relation("Eran"), std::exception);
    CHECK_THROWS_AS(s.relation("Yoav"), std::exception);
}


TEST_CASE("Test case 3") {
    

    family::Tree j ("Jordan");
    j.addFather("Jordan", "Samy");
	j.addMother("Jordan", "Rachel");
    j.addFather("Samy", "Yosi");
    j.addMother("Samy", "Esther");
    j.addFather("Rachel", "Marcel");
    j.addMother("Rachel", "Melody");
    j.addFather("Marcel","Avraham");
    j.addMother("Marcel","Sarah");
    j.addFather("Melody","Joshua");
    j.addMother("Melody","Rivka");

    CHECK(j.relation("Samy")=="father");
    CHECK(j.relation("Rachel")=="mother");
    CHECK(j.relation("Yosi")=="grandfather");
    CHECK(j.relation("Esther")=="grandmother");
    CHECK(j.relation("Marcel")=="grandfather");
    CHECK(j.relation("Esther")=="grandmother");
    CHECK(j.relation("Avraham")== "great-grandfather");
    CHECK(j.relation("Sarah")== "great-grandmother");
    CHECK(j.relation("Joshua")=="great-grandfather");
    CHECK(j.relation("Rivkah")=="great-grandmother");
    CHECK(j.find("father")=="Samy");
    CHECK(j.find("mother")=="Rachel");
    CHECK_THROWS_AS(j.relation("Litul"), std::exception);
    CHECK_THROWS_AS(j.relation("Stuv"), std::exception);
    CHECK_THROWS_AS(j.relation("jurin"), std::exception);
    CHECK_THROWS_AS(j.relation("kswuh"), std::exception);
    CHECK_THROWS_AS(j.relation("Yarin"), std::exception);
    CHECK_THROWS_AS(j.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(j.find("great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(j.find("great-great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(j.find("great-great-great-grandmother"), std::exception);
    j.addMother("Joshua", "greatM");
    j.addFather("Joshua", "greatF");
    CHECK(j.relation("greatF")=="great-great-grandfather");
    CHECK(j.relation("greatM")=="great-great-grandmother");
    CHECK(j.find("great-great-grandfather")=="greatF");
    CHECK(j.find("great-great-grandmother")=="greatM");
    j.addMother("Avraham", "greatM1");
    j.addFather("Avraham", "greatF1");
    CHECK(j.relation("greatM1")=="great-great-grandmother");
    CHECK(j.relation("greatF1")=="great-great-grandfather");
    j.addMother("Sarah", "greatM2");
    j.addFather("Sarah", "greatF2");
    CHECK(j.relation("greatF2")=="great-great-grandfather");
    CHECK(j.relation("greatM2")=="great-great-grandmother");
    j.addMother("Rivka", "greatM3");
    j.addFather("Rivka", "greatF3");
    CHECK(j.relation("greatF3")=="great-great-grandfather");
    CHECK(j.relation("greatM3")=="great-great-grandmother");
    CHECK_THROWS_AS(j.relation("John"), std::exception);
    CHECK_THROWS_AS(j.relation("Pikachu"), std::exception);
}