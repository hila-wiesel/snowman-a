#include "doctest.h"
#include "snowman.hpp"
#include <algorithm>
#include <stdexcept>
using namespace ariel;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces(" ___ \n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("  _  \n /_\\\n(O_O)\n/(> <)\\\n___"));
    CHECK(nospaces(snowman(44444444)) == nospaces(" ___ \n(_*_)\n(- -)\n\n\n"));
    CHECK(nospaces(snowman(11334431)) == nospaces("_===_\n(O,O)\n(> <)\n( : )"));
}


TEST_CASE("Bad snowman code - short input"){
    for(int i=1; i<=4; ++i){    //too short
        for (int j=1; j<=1000000; j= j*10 +1){
            CHECK_THROWS_AS(snowman(i*j), string);
        }
    }
}

TEST_CASE("Bad snowman code - long input"){
    for(int i=100000000; i<=4; i=i*10){    //too short
        CHECK_THROWS(snowman(11111111+i));
    }
}

TEST_CASE("Bad snowman code - unveiled digits"){
    for(int i=5; i<=9; ++i){    //unveiled digits
        for (int j=1; j<=10000000; j=j*10){
            long check = (11111111-j)+(i*j);
            CHECK_THROWS(snowman(check));
        }
    }
}

        // int ceck1 = 11111110+i;
        // int ceck2 = 11111101+i*10;
        // int ceck3 = 11111011+i*100;
        // int ceck4 = 11110111+i*1000;
        // int ceck5 = 11101111+i*10000;
        // int ceck6 = 11011111+i*100000;
        // int ceck7 = 10111111+i*1000000;
        // int ceck8 = 1111111 +i*10000000;