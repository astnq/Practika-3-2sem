#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> even_numbers, odd_numbers;

    for_each(numbers.begin(), numbers.end(), [&](int x) {
        (x % 2 == 0 ? even_numbers : odd_numbers).push_back(x);
    });

    cout << "Чётные числа: ";
    for (int num : even_numbers) cout << num << " ";
    
    cout << "\nНечётные числа: ";
    for (int num : odd_numbers) cout << num << " ";

    return 0;
}
