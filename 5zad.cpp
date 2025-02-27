#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const std::string& s) {
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main() {
    string word;
    cout << "Введите слово: ";
    cin >> word;
    cout << (is_palindrome(word) ? "Палиндром!" : "Не палиндром.") << endl;
    return 0;
}
//Примеры(Мадам, Казак, Шалаш)
