#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    string surname;
    string group;
    int score;
};

int main() {
    system ("chcp 65001");
    int N;
    cout << "Введите количество студентов: ";
    cin >> N;
    cin.ignore(); // Удаляем символ новой строки из буфера ввода

    vector<Student> students(N);
    int minScore;
    cout << "Введите минимальное количество баллов для сдачи экзамена: ";
    cin >> minScore;
    cin.ignore(); // Удаляем символ новой строки из буфера ввода

    cout << "Введите информацию о каждом студенте (фамилия, группа, баллы):\n";
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> students[i].surname >> students[i].group >> students[i].score;
    }

    cout << "\nРезультаты экзамена по математическому анализу:\n";
    for (const Student& student : students) {
        if (student.score >= minScore) {
            cout << student.surname << " (" << student.group << ") - сдал экзамен успешно.\n";
        } else {
            cout << student.surname << " (" << student.group << ") - остался на пересдачу.\n";
        }
    }

    return 0;
}
