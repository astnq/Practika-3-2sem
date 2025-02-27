#include <iostream>
#include <algorithm>

using namespace std;

bool is_anagram(std::string s1, std::string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1, s2;
    cout << "Введите две строки: ";
    cin >> s1 >> s2;

    cout << (is_anagram(s1, s2) ? "Анаграмма!" : "Не анаграмма.") << endl;
    return 0;
}
