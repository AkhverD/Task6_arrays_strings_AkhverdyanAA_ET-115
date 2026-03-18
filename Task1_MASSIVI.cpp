#include <iostream>
using namespace std;

// МАССИВЫ

int main() {
    setlocale(LC_ALL, "RU");
    const int N = 10;
    int stud[N];

    // Ввод
    cout << "Введите 10 рейтингов (0-100):\n";
    for (int i = 0; i < N; i++) {
        cin >> stud[i];
    }

    // массив сегментов
    int segments[10] = { 0 };

    // градации для рейтингов
    int prevoshodno = 0, chetko = 0, padet = 0, ne_padet = 0;

    for (int i = 0; i < N; i++) {
        int value = stud[i];

        // проверяем к какому сегменту относится рейтинг
        int index = value / 10;
        //если рейтинг будет равен 100, то он будет относится к 
        // сегменту с индексом девять, поэтому приравниваем к 9
        if (index == 10) index = 9;
        segments[index]++;

        // относим к нужной категории
        if (value >= 85) prevoshodno++;
        else if (value >= 75) chetko++;
        else if (value >= 60) padet++;
        else ne_padet++;
    }

    // вывод сегментов
    cout << "\nСегменты в %:\n";
    for (int i = 0; i < 9; i++) {
        cout << i * 10 << "-" << i * 10 + 9 << ": " << (segments[i] * 100 / N) << "%\n";
    }
    cout << 90 << "-" << 100 << ": " << (segments[9] * 100 / N) << "%\n";

    // вывод категорий
    cout << "\nОценки в %:\n";
    cout << "Отлично: " << (prevoshodno * 100 / N) << "%\n";
    cout << "Хорошо: " << (chetko * 100 / N) << "%\n";
    cout << "Удовлитворительно: " << (padet * 100 / N) << "%\n";
    cout << "Неудовлитворительно: " << (ne_padet * 100 / N) << "%\n";

    system("pause");

    return 0;
}
