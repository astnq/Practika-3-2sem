#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, capacity;
    cout << "Введите количество предметов и вместимость рюкзака: ";
    cin >> N >> capacity; // Вводим количество предметов и максимальный вес рюкзака

    vector<int> weights(N), values(N); // Веса и стоимости предметов

    cout << "Введите веса и стоимости предметов:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i]; 
    }

    // Таблица для динамического программирования (dp[w] - максимальная стоимость для веса w)
    vector<int> dp(capacity + 1, 0);

    // Лямбда-функция для обновления таблицы dp
    auto knapsack = [&](int weight, int value) {
        for (int w = capacity; w >= weight; --w) { // Перебор рюкзаков от большего к меньшему
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    };
    
    for (int i = 0; i < N; ++i) {
        knapsack(weights[i], values[i]); // Добавляем предмет в рюкзак
    }

    cout << "Максимальная стоимость: " << dp[capacity] << endl; 

    return 0;
}
