#include <iostream>
#include <algorithm>

using namespace std;

// Функция проверки анаграмм (слова, составленные из одних и тех же букв)
bool is_anagram(string s1, string s2) {
    sort(s1.begin(), s1.end()); // Сорт-ка первой строки
    sort(s2.begin(), s2.end()); // Сорт-ка второй строки
    return s1 == s2; // Если отсортированные строки совпадают — это анаграмма
}

int main() {
    string s1, s2;
    cout << "Введите две строки: ";
    cin >> s1 >> s2;

    cout << (is_anagram(s1, s2) ? "Анаграмма!" : "Не анаграмма.") << endl;
    return 0;
}
