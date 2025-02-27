#include <iostream>
#include <numeric> // Для функции gcd()

using namespace std;

// Функция проверяет, можно ли поровну разделить торт
bool can_cut_cake(int people, int slices) {
    return gcd(people, slices) == people; // Проверяем, делится ли общее число кусков на количество людей
}

int main() {
    int people, slices;
    cout << "Введите количество людей и кусочков: ";
    cin >> people >> slices;

    cout << (can_cut_cake(people, slices) ? "Можно разделить поровну!" : "Нельзя.") << endl;
    return 0;
}
