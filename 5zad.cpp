#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;
    std::cout << (is_palindrome(word) ? "Палиндром!" : "Не палиндром.") << std::endl;
    return 0;
}
//(Мадам, Казак, Шалаш)
