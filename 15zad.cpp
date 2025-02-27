#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, capacity;
    cout << "Введите количество предметов и вместимость рюкзака: ";
    cin >> N >> capacity;

    vector<int> weights(N), values(N);

    cout << "Введите веса и стоимости предметов:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
    }

    // Таблица для динамического программирования
    vector<int> dp(capacity + 1, 0);

    // Лямбда-функция для обновления таблицы dp
    auto knapsack = [&](int weight, int value) {
        for (int w = capacity; w >= weight; --w) {
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    };

    // Применение лямбда-функции ко всем предметам
    for (int i = 0; i < N; ++i) {
        knapsack(weights[i], values[i]);
    }

    cout << "Максимальная стоимость: " << dp[capacity] << endl;

    return 0;
}
