#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZбвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";

    int vowel_count = count_if(text.begin(), text.end(), [&](char c) {
        return vowels.find(c) != string::npos;
    });

    int consonant_count = count_if(text.begin(), text.end(), [&](char c) {
        return consonants.find(c) != string::npos;
    });

    cout << "Гласных букв: " << vowel_count << endl;
    cout << "Согласных букв: " << consonant_count << endl;

    return 0;
}
