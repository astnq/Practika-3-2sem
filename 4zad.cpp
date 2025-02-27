#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void most_frequent_number() {
    vector<int> nums;
    int n, x;
    cout << "Введите количество чисел: ";
    cin >> n;
    cout << "Введите числа: ";
    while (n--) {
        cin >> x;
        nums.push_back(x);
    }

    unordered_map<int, int> freq;
    for_each(nums.begin(), nums.end(), [&freq](int x) { freq[x]++; });

    auto max_elem = max_element(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    cout << "Число " << max_elem->first << " встречается " << max_elem->second << " раз." << std::endl;
}

int main() {
    most_frequent_number();
    return 0;
}
