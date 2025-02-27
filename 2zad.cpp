#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string sentence;
    cout << "Введите предложение: ";
    getline(cin, sentence);  // Считываем всю строку

    istringstream iss(sentence);  // Создаём поток для разделения строки
    vector<string> words{istream_iterator<string>{iss}, {}};  // Разбиваем на слова

    reverse(words.begin(), words.end());  // Разворачиваем порядок слов
    
    // Выводим слова в обратном порядке
    for (const auto& w : words) cout << w << " ";
    return 0;
}
