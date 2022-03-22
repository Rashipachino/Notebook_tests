#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

ariel:: Notebook notebook4;

TEST_CASE("Good input") {
    ariel:: Notebook notebook1;
    notebook1.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");
	CHECK(notebook1.read(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/4) == "abcd");
    CHECK(notebook1.read(11,14,14, Direction::Horizontal, 3) == "___");
    notebook1.write(/*page=*/1000, /*row=*/60, /*column=*/5, Direction::Horizontal, "Hello my name is Rashi!");
    CHECK(notebook1.read(/*page=*/1000, /*row=*/60, /*column=*/5, Direction::Horizontal, /*length=*/23) == "Hello my name is Rashi!");
    notebook1.write(/*page=*/5, /*row=*/33, /*column=*/900, Direction::Vertical, "Shopping List: apples, eggs, tomato sauce, cheese, batteries");
    CHECK(notebook1.read(/*page=*/5, /*row=*/33, /*column=*/900, Direction::Vertical, /*length=*/60) == "Shopping List: apples, eggs, tomato sauce, cheese, batteries");
    notebook1.write(/*page=*/22, /*row=*/700, /*column=*/447, Direction::Vertical, "Dear Diary, Today I founded my own start up and made 1 billion $$$$!!!!");
    CHECK(notebook1.read(/*page=*/22, /*row=*/700, /*column=*/447, Direction::Vertical, /*length=*/147) == "Dear Diary, Today I founded my own start up and made 1 billion $$$$!!!!");
    notebook1.erase(/*page=*/22, /*row=*/700, /*column=*/447, Direction::Vertical, 71);
    CHECK(notebook1.read(/*page=*/22, /*row=*/700, /*column=*/447, Direction::Vertical, /*length=*/147) == "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    notebook1.write(0,0,1, Direction:: Vertical, "hi!");
    CHECK(notebook1.read(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/5) == "~hi!~");
    notebook1.erase(/*page=*/2, /*row=*/2, /*column=*/10, Direction::Vertical, 5);
    CHECK(notebook1.read(/*page=*/2, /*row=*/2, /*column=*/10, Direction::Vertical, 5) == "~~~~~");
    CHECK(notebook1.read(/*page=*/12, /*row=*/2, /*column=*/10, Direction::Vertical, 5) == "_____");    
}

TEST_CASE("Bad input - message larger than 100 characters") {
    ariel:: Notebook notebook3;
    CHECK_THROWS(notebook3.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Vertical, "I am just writing meaningless words until I get to over 100 characters because that is an issue and should be dealt with"));
    CHECK_THROWS(notebook3.write(/*page=*/101, /*row=*/100, /*column=*/12, Direction::Horizontal, "Another long message to be written in my diary...this should throw an error because the message is longer than the number of space in a row!"));
    CHECK_THROWS(notebook3.write(/*page=*/2, /*row=*/101, /*column=*/90, Direction::Horizontal, "Shabbat shopping list: chicken, eggs, chocolate chips, balsamic vinegar, rice, potatoes, veggies, lots of dessert, challah, and wine!"));
    CHECK_THROWS(notebook3.write(/*page=*/0, /*row=*/100, /*column=*/0, Direction::Vertical, "We the people of the united states in order to for a more perfect union, establish justice, infure domestic tranquility..."));
}

TEST_CASE("Bad input - writing on line already written"){
    notebook4.write(10,0,0, Direction::Vertical, "Something is written here! Get out!");
    CHECK_THROWS(notebook4.write(10,0,1,Direction::Vertical, "Trying to write on something already written"));
    notebook4.write(11,1,0, Direction::Horizontal, "Something is written here! Get out!");
    CHECK_THROWS(notebook4.write(11,1,0,Direction::Horizontal, "Trying to write on something already written"));
    notebook4.write(1,0,0, Direction:: Vertical, "Secret message written here");
    CHECK_THROWS(notebook4.write(1,0,4,Direction::Horizontal, "Trying to write on something already written"));    
}

TEST_CASE("Bad input - writing on erased line"){
    notebook4.erase(10,0,0, Direction::Vertical, 35);
    CHECK_THROWS(notebook4.write(10,0,0, Direction::Vertical, "Something was erased here! Get out!"));
    notebook4.erase(11, 1, 0, Direction::Horizontal, 35);
    CHECK_THROWS(notebook4.write(11,1,0, Direction::Horizontal, "Something was erased here! Get out!"));
    notebook4.erase(0, 0, 0, Direction::Horizontal, 3);
    CHECK_THROWS(notebook4.write(0,0,1, Direction::Horizontal, "Something was erased here! Get out!"));  
    notebook4.write(7,0,1,Direction::Vertical, "bbb");
    notebook4.erase(7,0,2,Direction::Vertical, 10);
    CHECK_THROWS(notebook4.write(7,0,3, Direction::Vertical, "Something was erased here! Get out!"));  
}
    


