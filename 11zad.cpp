#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    system ("chcp 65001");
    vector<string> fruits = {"абрикос", "персик", "абрикос", "персик", "абрикос", "абрикос"};

    int abricos = count(fruits.begin(), fruits.end(), "абрикос");
    int persiki = count(fruits.begin(), fruits.end(), "персик");
    int total_fruits = fruits.size();

    cout << "Всего фруктов: " << total_fruits << endl;
    cout << "Количество абрикосов: " << abricos << endl;
    cout << "Количество персиков: " << persiki << endl;

    return 0;
}
