#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> scores = {80, 70, 90, 60, 100}; // Исходные баллы студентов

    // Находим максимальный балл, но сравниваем их, уменьшая в 2 раза
    double max_score = *max_element(scores.begin(), scores.end(), [](int a, int b) {
        return a * 0.5 < b * 0.5; // Сравнение половинных значений
    }) * 0.5; // Финальный результат тоже уменьшаем в 2 раза

    cout << "Максимальный конечный балл: " << max_score << endl;

    return 0;
}
