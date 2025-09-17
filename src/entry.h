#include <iostream>
using namespace std;

struct Entry {
    string name;
    string college;
    int score;

    // TODO: Implement bool compare(Entry* other)
    // Returns true if this entry's score is greater than the other entry's score
    // Otherwise, returns false

    void print() {
        cout << name << " (" << college << "): " << score << endl;
    }
};