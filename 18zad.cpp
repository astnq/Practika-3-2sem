#include <iostream>
#include <vector>

using namespace std;

double averageEvenPositions(const vector<int>& arr) {
    int sum = 0;
    int count = 0;

    // Перебираем массив с шагом 2, чтобы получить только элементы на четных позициях
    for (size_t i = 1; i < arr.size(); i += 2) {
        sum += arr[i];
        count++;
    }

    // Возвращаем среднее арифметическое, если есть элементы на четных позициях
    if (count > 0) {
        return (double)sum / count;
    } else {
        return 0; // Возвращаем 0, если элементов на четных позициях нет
    }
}

int main() {
    system ("chcp 65001");
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    double average = averageEvenPositions(numbers);

    cout << "Среднее арифметическое чисел на четных позициях: " << average << endl;

    return 0;
}
