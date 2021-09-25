//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"
#include <iomanip>
#include <map>

TEST_CASE("Testing Tests", "[multiplication]") {
    REQUIRE((2 * 2) == 4);
    REQUIRE((1 * 5) == 5);
}

TEST_CASE("Testing DSVector") {

    DSVector<DSString> vectorString;
    DSString a = "a";
    DSString b = "b";
    vectorString.push_back(a);
    vectorString.push_back(a);
    vectorString.push_back(a);
    DSVector<int> vectorInt;
    for (int i = 0; i < 15; i++)
        vectorInt.push_back(i);
    DSVector<std::map <DSString, int>> vectorMap;
    std::map <DSString, int> map1;
    for (int i = 0; i < 5; i++)
        vectorMap.push_back(map1);
    DSVector<DSVector<DSString>> vectorInVector;
    vectorInVector.push_back(vectorString);
    DSVector<DSString> vectorString1;

    SECTION("Testing copy constructor"){
        DSVector<DSString> vector1 = vectorString;
        REQUIRE (vector1 == vectorString);
        DSVector<DSVector<DSString>> vector2 = vectorInVector;
        REQUIRE (vector2 == vectorInVector);
        DSVector<int> vector3 = vectorInt;
        REQUIRE (vector3 == vectorInt);
    }

    SECTION("Testing Copy Assignment"){

        DSVector<DSString> vector1;
        vector1.push_back(b);
        vector1 = vectorString;
        REQUIRE (vector1 == vectorString);

        DSVector<DSVector<DSString>> vector2;
        vector2.push_back(vector1);
        vector2.push_back(vector1);
        vector2 = vectorInVector;
        vectorInVector = vector2;
        REQUIRE (vector2 == vectorInVector);

        DSVector<std::map <DSString, int>> vector3;
        std::map <DSString, int> map2;
        vector3.push_back(map2);
        vector3 = vectorMap;
        REQUIRE (vector3 == vectorMap);

    }

    SECTION("Testing operator=="){
        DSVector <DSString> testVectorString = vectorString;
        REQUIRE (testVectorString == vectorString);
    }

    SECTION("Testing Operator[]"){
        REQUIRE(vectorString[1] == "a");
        REQUIRE(vectorInt[4] == 4);
        REQUIRE(vectorInVector[0] == vectorString);
    }

    SECTION("Testing push_back function"){
        DSString a = "Air";
        DSString b = "Water";
        DSString c = "Earth";
        DSString d = "Fire";
        vectorString1.push_back(a);
        REQUIRE(vectorString1[0] == a);
        vectorString1.push_back(b);
        REQUIRE(vectorString1[1] == b);
    }

}

TEST_CASE("Testing DSString") {
    DSString a = "1";
    DSString b = "Ten Char10";
    DSString c = "Multiple words/Actual Tweet";
    DSString d = "Ten Char10";
    DSString e = "UPPERCASE";
    DSString f = "uppercase";
    DSString g = "";
    DSString h = "\n";
    DSString i = "                    ";
    DSString j = "aaaa";
    DSString k = "bbbb";
    char char1 = 'y';
    char char2 = 'n';
    char char3 = ' ';
    char char4 = '\n';
    char char5 = e[0];
    char char6 = 'y';
    char char7 = 'Y';
    char char9 = '1';
    char char10 = '9';


    SECTION("Equality operators DSString"){
        REQUIRE(a == DSString("1"));
        REQUIRE(b == d);
        REQUIRE(c == "Multiple words/Actual Tweet");
        REQUIRE(!(e == f));
    }
    SECTION("Equality operators Char"){
        REQUIRE(char1 == 'y');
        REQUIRE(char1 == char6);
        REQUIRE(char2 == b[2]);
        REQUIRE(char3 == i[1]);
        REQUIRE(char4 == h[0]);
        REQUIRE(!(char5 == f[0]));
    }
    SECTION("Assignment operators DSString"){
        DSString str;
        str = "1";
        REQUIRE(str == a);
        str = DSString("Ten Char10");
        REQUIRE(str == b);
        str = "";
        REQUIRE(str == g);
        str = DSString("\n");
        REQUIRE(str == h);
    }
    SECTION("Assignment operators Char"){
        char char8;
        char8 = '1';
        REQUIRE(char8 == a[0]);
        char8 = char('a');
        REQUIRE(char8 == j[0]);
        char8 = ' ';
        REQUIRE(char8 == i[2]);
        char8 = 'a';
        REQUIRE(char8 == 'a');
        char8 = '\n';
        REQUIRE(char8 == char4);
    }
    SECTION("Addition operator DSString"){
        REQUIRE(DSString("1Ten Char10") == a + b);
        REQUIRE(g + g == "");
        REQUIRE(g + h == DSString("\n"));
        REQUIRE(a + b + c == "1Ten Char10Multiple words/Actual Tweet");
    }

    SECTION("Greater than operator DSString"){
        REQUIRE(b > a);
        REQUIRE(f > e);
        REQUIRE(k > j);
        REQUIRE(c > g);
        REQUIRE(b > g);
    }
    SECTION("Greater than operator DSString"){
        REQUIRE(a < b);
        REQUIRE(e < f);
        REQUIRE(j < k);
        REQUIRE(g < c);
        REQUIRE(g < b);
    }
    SECTION("Greater than operator Char"){
        REQUIRE(char1 > char2);
        REQUIRE(char6 > char7);
        REQUIRE(char2 > char7);
        REQUIRE(char10 > char9);
    }
    SECTION("[] Operator"){
        REQUIRE(b[1] == 'e');
        REQUIRE(c[8] == ' ');
        REQUIRE(g[0] == 0);
    }
    SECTION("getLength function"){
        REQUIRE(d.getLength() == 10);
        REQUIRE(g.getLength() == 0);
        REQUIRE(i.getLength() == 20);
        REQUIRE(e.getLength() == 9);
    }
    SECTION("Substring function") {
        REQUIRE(a.substring(0, 1) == "1");
        REQUIRE(f.substring(0, 5) == "upper");
        REQUIRE(f.substring(1, 6) == "pperca");
    }
    SECTION("c_str function"){
        REQUIRE(strcmp(b.c_str(), "Ten Char10") == 0);
        REQUIRE(strcmp(d.c_str(), b.c_str()) == 0);
        REQUIRE(strcmp(g.c_str(), "") == 0);
    }
}
