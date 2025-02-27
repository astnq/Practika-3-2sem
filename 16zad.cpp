#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Введите количество птенцов: ";
    cin >> N;

    // Векторы для хранения данных о птенцах: цвет, размер, номер
    vector<string> colors(N);
    vector<int> sizes(N);
    vector<int> numbers(N, 0); // Изначально у всех номер 0

    // Ввод данных о каждом птенце
    cout << "Введите цвет и размер каждого птенца (цвет размер):" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> colors[i] >> sizes[i];
    }

    // Вектор индексов для сортировки
    vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    // Сортируем птенцов: сначала по убыванию размера, затем по алфавиту цвета
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        if (sizes[a] != sizes[b]) return sizes[a] > sizes[b]; // Сначала сортируем по размеру (по убыванию)
        return colors[a] < colors[b]; // Если размеры одинаковые, сортируем по цвету (по алфавиту)
    });

    // Присваивание номеров
    int currentNumber = 1;
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];

        // Если текущий птенец имеет такой же размер, как предыдущий, то номер тот же
        if (i > 0 && sizes[indices[i]] == sizes[indices[i - 1]]) {
            numbers[idx] = numbers[indices[i - 1]];
        } else {
            numbers[idx] = currentNumber;
        }
        ++currentNumber;

        // Если птенец красный, его номер не может быть меньше 3
        if (colors[idx] == "red" && numbers[idx] < 3) {
            numbers[idx] = 3;
        }
    }

    // Дополнительная корректировка: если у двух птенцов с номером 4 одинаковый цвет, увеличиваем номер
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
                numbers[indices[i]]++;
            }
        }
    }
    cout << "Птенцы с номерами:" << endl;
    for (size_t i = 0; i < N; ++i) {
        cout << "Цвет: " << colors[i] << ", Размер: " << sizes[i] << ", Номер: " << numbers[i] << endl;
    }

    return 0;
}
