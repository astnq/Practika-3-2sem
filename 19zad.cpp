#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    system ("chcp 65001");
    vector<int> numbers = { 10, 10, 10, 10, 10, 10, 10};

    // Найдем сумму всех чисел в векторе
    int sum = 0;
    sum = accumulate(numbers.begin(), numbers.end(), 0);

    // Вывод сумму на экран
    cout << "Сумма за все задания " << sum << endl;
    // Баллы практика
    double pr = sum * 0.3;
    // Сумма за весь предмет
    double ves_predmet = sum + pr;
    cout << "Сумма за весь предмет " << ves_predmet << endl;
    return 0;
}
