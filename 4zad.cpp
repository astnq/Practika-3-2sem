#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Функция для поиска наиболее часто встречающегося числа
void most_frequent_number() {
    vector<int> nums;
    int n, x;

    cout << "Введите количество чисел: ";
    cin >> n;
    
    cout << "Введите числа: ";
    while (n--) {  // Вводим n чисел и добавляем в вектор
        cin >> x;
        nums.push_back(x);
    }

    unordered_map<int, int> freq; // Хеш-таблица для подсчёта частоты чисел
    for_each(nums.begin(), nums.end(), [&freq](int x) { freq[x]++; });

    // Поиск числа с максимальной частотой
    auto max_elem = max_element(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    cout << "Число " << max_elem->first << " встречается " << max_elem->second << " раз." << endl;
}

int main() {
    most_frequent_number();
    return 0;
}
