#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

int err_n() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 1) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

void bubble_sorting(int* arr, int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    cout << "Результат пузырьковой сортировки: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insert_sorting(int* arr, int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
            swap(a[j - 1], a[j]);

    cout << "Результат сортировки вставками: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void choice_sorting(int* arr, int n) {
    int min;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr[i];
    
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (a[j] < a[min]) ? j : min;
        if (i != min)
        {
            swap(a[i], a[min]);
        }
    }

    cout << "Результат сортировки выбором: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;

    cout << "Введите количество чисел: ";
    n = err_n();

    cout << "Введите числа через пробел: ";
    int* mas = new int [n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];

    bubble_sorting(mas, n);
    insert_sorting(mas, n);
    choice_sorting(mas, n);
}