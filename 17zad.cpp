#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    cout << "Введите числа. Для завершения ввода введите 'stop':" << endl;

    // Ввод чисел
    while (true) {
        string input;
        cin >> input;
        
        if (input == "stop") {
            break;
        }

        try {
            num = stoi(input);  // Преобразуем строку в число
            numbers.push_back(num);
        } catch (const invalid_argument&) {
            cout << "Ошибка ввода. Пожалуйста, введите число или 'stop' для завершения." << endl;
        }
    }

    if (numbers.empty()) {
        cout << "Введены некорректные данные или нет чисел для вычисления среднего." << endl;
        return 0;
    }

    // Используем итераторы для вычисления суммы чисел
    int sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        sum += *it;  // Суммируем числа
    }

    // Вычисление среднего арифметического
    double average = static_cast<double>(sum) / numbers.size();

    cout << "Среднее арифметическое: " << average << endl;

    return 0;
}
