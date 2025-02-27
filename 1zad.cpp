#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_armstrong(int num) {
    vector<int> digits;
    for (int n = num; n > 0; n /= 10)
        digits.push_back(n % 10);

    int sum = accumulate(digits.begin(), digits.end(), 0, [p = digits.size()](int acc, int d) {
        return acc + pow(d, p);
    });

    return sum == num;
}

int main() {
    int num;
    cout << "Введите число: ";
    cin >> num;
    cout << (is_armstrong(num) ? "Счастливое число!" : "Обычное число.") << endl;
    return 0;
}
