#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    system ("chcp 65001");
    vector<pair<int, int>> students = {{75, 11}, {85, 25}, {75, 30}, {90, 18}, {85, 6}};

    sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });

    for (const auto& student : students) {
        cout << "Баллы: " << student.first << ", Билет: " << student.second << endl;
    }

    return 0;
}
