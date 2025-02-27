#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> numbers; // Вектор для хранения введённых чисел
    int num; 

    cout << "Введите числа. Для завершения ввода введите 'stop':" << endl;

    
    while (true) {
        string input;
        cin >> input; // Считываем ввод пользователя
        
        if (input == "stop") { // Проверяем, введено ли слово "stop"
            break; 
        }

        try {
            num = stoi(input);  // Преобразуем строку в число
            numbers.push_back(num); // Добавляем число в вектор
        } catch (const invalid_argument&) { // Обрабатываем ошибку, если введено не число
            cout << "Ошибка ввода. Пожалуйста, введите число или 'stop' для завершения." << endl;
        }
    }

    // Проверяем, были ли введены корректные числа
    if (numbers.empty()) {
        cout << "Введены некорректные данные или нет чисел для вычисления среднего." << endl;
        return 0; 
    }

    // Используем итераторы для вычисления суммы чисел
    int sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        sum += *it;  
    }

    // Вычисление среднего арифметического
    double average = static_cast<double>(sum) / numbers.size(); // Преобразуем в double для точности

    cout << "Среднее арифметическое: " << average << endl;

    return 0;
}
