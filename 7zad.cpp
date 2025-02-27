#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Исправлена ошибка "usnig" -> "using"

// Функция для поиска всех простых чисел до n (Решето Эратосфена)
void sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true); // Массив булевых значений для отметки простых чисел
    is_prime[0] = is_prime[1] = false;  // 0 и 1 не являются простыми числами

    // Алгоритм решета Эратосфена
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) { // Если p - простое число
            for (int i = p * p; i <= n; i += p) // Помечаем все его кратные как составные
                is_prime[i] = false;
        }
    }

    // Выводим все простые числа
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            cout << i << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Введите число N: ";
    cin >> n;
    
    sieve_of_eratosthenes(n); // Вызываем функцию
    return 0;
}
