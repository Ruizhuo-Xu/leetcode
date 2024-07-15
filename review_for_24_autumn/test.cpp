#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand((unsigned) time(NULL));
    int loop = 10;
    while (loop--) {
        int x = (float) rand() / RAND_MAX * 9 + 1 + 0.5; // [1,10]
        cout << x << endl;
    }
    return 0;
}