#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Введите количество птенцов: ";
    cin >> N;

    vector<string> colors(N); // Массив цветов птенцов
    vector<int> sizes(N);     // Массив размеров птенцов
    vector<int> numbers(N, 0); // Массив номеров птенцов (изначально 0)

    cout << "Введите цвет и размер каждого птенца (цвет размер):" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> colors[i] >> sizes[i];
    }

    // Создаем массив индексов для сортировки
    vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    // Сортировка индексов по размеру (убывание), затем по цвету (возрастание)
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        if (sizes[a] != sizes[b]) return sizes[a] > sizes[b]; // Убывание по размеру
        return colors[a] < colors[b];                        // Возрастание по цвету
    });

    // Присваивание номеров
    int currentNumber = 1;
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];

        // Если это не первый птенец и размер совпадает с предыдущим
        if (i > 0 && sizes[indices[i]] == sizes[indices[i - 1]]) {
            numbers[idx] = numbers[indices[i - 1]]; // Одинаковый номер
        } else {
            numbers[idx] = currentNumber; // Новый номер
        }
        ++currentNumber;

        // Учитываем условие для красного птенца
        if (colors[idx] == "red" && numbers[idx] < 3) {
            numbers[idx] = 3; // Красный птенец не может иметь номер менее 3
        }
    }

    // Корректировка для птенца с номером 4 (разный цвет)
    for (size_t i = 0; i < N; ++i) {
        if (numbers[indices[i]] == 4) {
            bool hasSameColor = false;
            for (size_t j = 0; j < N; ++j) {
                if (i != j && numbers[indices[j]] == 4 && colors[indices[j]] == colors[indices[i]]) {
                    hasSameColor = true;
                    break;
                }
            }
            if (hasSameColor) {
                numbers[indices[i]]++; // Увеличиваем номер
            }
        }
    }

    // Вывод результата
    cout << "Птенцы с номерами:" << endl;
    for (size_t i = 0; i < N; ++i) {
        cout << "Цвет: " << colors[i] << ", Размер: " << sizes[i] << ", Номер: " << numbers[i] << endl;
    }

    return 0;
}
