#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
#include <iostream>
using namespace ariel;
#include<algorithm>
#include <string>
#include <math.h>
using namespace std;


    
TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : )\n"));
    CHECK(snowman(12344434)==string(" _===_\n (O.-) \n (> <) \n (   )\n"));
    CHECK(snowman(33232124)==string("  _ \n /_\\n \\(o_O)\n (] [)>\n (   )\n"));
    CHECK(snowman(22222222)==string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \")\n"));
    CHECK(snowman(44444444)==string("  ---\n (_*_)\n (- -) \n (   ) \n (   )\n"));
    CHECK(snowman(33333333)==string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___)\n"));
    CHECK(snowman(12341234)==string(" _===_\n (O.-)/\n<(> <) \n (   )\n"));
    }

TEST_CASE("Bad snowman") {
    CHECK(snowman(41114411).compare(string("_===_\n(.,.)\n( : )\n( : )")) == 0);
    CHECK(snowman(44444444).compare(string(" ___ \n(_*_)\n(--)\n(   )\n(  )")) == 0);
    CHECK(snowman(11111111).compare(string("_===_\n<(.,.)>\n( : )\n( : )")) == 0);
    CHECK(snowman(33333333).compare(string("  _  \n  /_\\  \n/(0_0)\\n(> <)\n(___)")) == 0);
    CHECK(snowman(22222222).compare(string(" ___ \n.....\n(o.o)\n\\(] [)/\n(" ")")) == 0);
    //doesnt exsit 
    CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(235411112));
	CHECK_THROWS(snowman(11111844));
    }

TEST_CASE("input too short"){
  for (int i = 1; i < 5; ++i) {
        int num = 0;
            num = num*10+i;
            CHECK_THROWS(snowman(num));
  }
}
TEST_CASE("Input too long"){
    for (int i = 1; i < 10; ++i) {
        int num = 111111111;
        CHECK_THROWS(snowman(num*i));
    }
}   
TEST_CASE("check invalid parts"){
    // hat check
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(61111111));
    CHECK_THROWS(snowman(71111111));
    //nose check
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(16111111));
    CHECK_THROWS(snowman(17111111));
    CHECK_THROWS(snowman(18111111));

    // left eye check
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(11611111));
    CHECK_THROWS(snowman(11711111));

    // right eye check
    CHECK_THROWS(snowman(11101111));
    CHECK_THROWS(snowman(11161111));
    CHECK_THROWS(snowman(11171111));

    // left arm check
    CHECK_THROWS(snowman(11117111));
    CHECK_THROWS(snowman(11119111));

    // right arm check
    CHECK_THROWS(snowman(11111911));
    CHECK_THROWS(snowman(11111011));

    // torso check
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111181));

    // base check
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(11111116));
    CHECK_THROWS(snowman(11111118));
    CHECK_THROWS(snowman(11111110));
}
