#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> scores = {80, 70, 90, 60, 100};

    double max_score = *max_element(scores.begin(), scores.end(), [](int a, int b) {
        return a * 0.5 < b * 0.5;
    }) * 0.5;

    cout << "Максимальный конечный балл: " << max_score << endl;

    return 0;
}
