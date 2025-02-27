#include <iostream>
#include <numeric>

using namespace std;

bool can_cut_cake(int people, int slices) {
    return gcd(people, slices) == people;
}

int main() {
    int people, slices;
    cout << "Введите количество людей и кусочков: ";
    cin >> people >> slices;
    cout << (can_cut_cake(people, slices) ? "Можно разделить поровну!" : "Нельзя.") << endl;
    return 0;
}
