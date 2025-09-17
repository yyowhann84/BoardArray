#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../boardarray.h"
#include <sstream>

std::string capture_output(std::function<void()> func) {
    std::ostringstream oss;
    std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
    func();
    std::cout.rdbuf(old);
    return oss.str();
}

TEST_CASE("Empty board prints nothing", "[scoreboard]") {
    std::string output = capture_output([]() {
        BoardArray* sb = new BoardArray();
        sb->print();
        delete sb;
    });
    REQUIRE(output == "");
}

TEST_CASE("Score too low to be added", "[scoreboard]") {
    std::string output = capture_output([]() {
        BoardArray* sb = new BoardArray();
        sb->add(new Entry{"Lance", "CCS", 91});
        sb->add(new Entry{"Chow", "CCS", 88});
        sb->add(new Entry{"Joanna", "CASE", 92});
        sb->add(new Entry{"Cathy", "CMBA", 88});
        sb->add(new Entry{"Von", "CNAHS", 90});
        sb->add(new Entry{"Therese", "CEA", 76});
        sb->print();
        delete sb;
    });
    REQUIRE(output == "Therese's score is too low to be added!\n1. Joanna (CASE): 92\n2. Lance (CCS): 91\n3. Von (CNAHS): 90\n4. Chow (CCS): 88\n5. Cathy (CMBA): 88\n");
}

TEST_CASE("Replace lowest score and stay sorted", "[scoreboard]") {
    std::string output = capture_output([]() {
        BoardArray* sb = new BoardArray();
        sb->add(new Entry{"Lance", "CCS", 95});
        sb->add(new Entry{"Chow", "CCS", 85});
        sb->add(new Entry{"Joanna", "CASE", 90});
        sb->add(new Entry{"Cathy", "CMBA", 88});
        sb->add(new Entry{"Von", "CNAHS", 92});
        sb->add(new Entry{"Natz", "CCJ", 87});
        sb->add(new Entry{"Therese", "CEA", 99});
        sb->print();
        delete sb;
    });
    REQUIRE(output == "1. Therese (CEA): 99\n2. Lance (CCS): 95\n3. Von (CNAHS): 92\n4. Joanna (CASE): 90\n5. Cathy (CMBA): 88\n");
}