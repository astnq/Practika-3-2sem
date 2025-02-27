#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string sentence;
    cout << "Введите предложение: ";
    getline(cin, sentence);

    istringstream iss(sentence);
    vector<std::string> words{std::istream_iterator<string>{iss}, {}};

    reverse(words.begin(), words.end());
    
    for (const auto& w : words) cout << w << " ";
    return 0;
}
