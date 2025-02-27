#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Функция для генерации случайного пароля
string generate_password(int length) {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*"; 
    string password(length, ' '); 
    
    generate(password.begin(), password.end(), [&chars]() { // Заполняем случайными символами
        static random_device rd; // Источник случайности
        static mt19937 gen(rd()); // Генератор случайных чисел
        static uniform_int_distribution<> dis(0, chars.size() - 1); // Распределение индексов по chars
        return chars[dis(gen)]; 
    });

    return password;
}

int main() {
    int len;
    cout << "Введите длину пароля: ";
    cin >> len;
    
    cout << "Сгенерированный пароль: " << generate_password(len) << endl;
    return 0;
}
