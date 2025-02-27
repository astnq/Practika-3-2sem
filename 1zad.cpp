#include <iostream>
#include <vector>
#include <cmath>
#include <numeric> 

using namespace std;

// Функция для проверки, является ли число числом Армстронга
bool is_armstrong(int num) {
    vector<int> digits;

    // Разбиваем число на отдельные цифры
    for (int n = num; n > 0; n /= 10)
        digits.push_back(n % 10);

    // Вычисляем сумму степеней цифр (степень = количество цифр)
    int sum = accumulate(digits.begin(), digits.end(), 0, [p = digits.size()](int acc, int d) {
        return acc + pow(d, p);
    });

    // Если сумма степеней цифр равна исходному числу — это число Армстронга
    return sum == num;
}

int main() {
    int num;
    cout << "Введите число: ";
    cin >> num;

    // Вывод результата
    cout << (is_armstrong(num) ? "Счастливое число!" : "Обычное число.") << endl;
    return 0;
}
