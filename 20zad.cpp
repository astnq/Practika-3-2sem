#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Векторы с парами значений (вес, размер) для мелких и крупных грузов
    vector<pair<int, int>> small_cargo = {{10, 5}, {5, 3}, {8, 4}}; 
    vector<pair<int, int>> large_cargo = {{30, 15}, {25, 10}, {40, 20}};

    // Объединяем два списка грузов в один
    vector<pair<int, int>> all_cargo(small_cargo.begin(), small_cargo.end());
    all_cargo.insert(all_cargo.end(), large_cargo.begin(), large_cargo.end());

    // Сортируем грузы по размеру (по возрастанию), при равных размерах - по весу (по возрастанию)
    sort(all_cargo.begin(), all_cargo.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    cout << "Объединенный и отсортированный список грузов:" << endl;
    for (const auto& cargo : all_cargo) {
        cout << "Вес: " << cargo.first << ", Размер: " << cargo.second << endl;
    }

    return 0;
}
