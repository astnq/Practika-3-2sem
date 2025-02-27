#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Функция для проверки, является ли строка палиндромом
bool is_palindrome(const string& s) {
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); // Сравниваем первую половину с обратной второй
}

int main() {
    string word;
    cout << "Введите слово: ";
    cin >> word;

    cout << (is_palindrome(word) ? "Палиндром!" : "Не палиндром.") << endl;
    return 0;
}
//Примеры(Мадам, Казак, Шалаш)
