#include <iostream>
using namespace std;

struct Entry {
    string name;
    string college;
    int score;

    bool compare(Entry* other) {
        return this->score > other->score;
    }

    void print() {
        cout << name << " (" << college << "): " << score << endl;
    }
};