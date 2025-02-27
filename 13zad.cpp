#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    string surname;  // Фамилия студента
    string group;    // Группа студента
    int score;       // Баллы за экзамен
};

int main() {
    system("chcp 65001"); 

    int N;
    cout << "Введите количество студентов: ";
    cin >> N;
    cin.ignore(); 

    vector<Student> students(N); // Создаём вектор студентов

    int minScore;
    cout << "Введите минимальное количество баллов для сдачи экзамена: ";
    cin >> minScore;
    cin.ignore(); // Удаляем символ новой строки из буфера ввода

    cout << "Введите информацию о каждом студенте (фамилия, группа, баллы):\n";
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line); // Считываем всю строку
        stringstream ss(line); // Используем stringstream для разбора строки
        ss >> students[i].surname >> students[i].group >> students[i].score;
    }

    // Вывод результатов экзамена
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
