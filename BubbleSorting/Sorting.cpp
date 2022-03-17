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
    
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (a[j] < a[min]) ? j : min;
        if (i != min) {
            swap(a[i], a[min]);
        }
    }

    cout << "Результат сортировки выбором: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Shell_sorting(int* arr, int n) {
    int d = n / 2;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            int j = i;
            while (j >= 0 && a[j] > a[j + d]) {
                swap(a[j], a[j + d]);
                j--;
            }
        }
        d = d / 2;
    }

    cout << "Результат сортировки Шелла: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void create_tree(int* arr, int n, int i) //вспомогательная функция для пирамидальной сортировки
{
    int max = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[max])
        max = l;

    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i) {
        swap(arr[i], arr[max]);
        create_tree(arr, n, max);
    }
}

void pyramid_sorting(int *arr, int n)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    for (int i = n / 2 - 1; i >= 0; i--)
        create_tree(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        create_tree(a, i, 0);
    }

    cout << "Результат пирамидальной сортировки: ";
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
    Shell_sorting(mas, n);
    pyramid_sorting(mas, n);
}