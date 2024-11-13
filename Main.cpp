#include <iostream>
#include <Windows.h>

using namespace std;

// Задание 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysBetween(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = day1 + (month1 - 1) * 30 + year1 * 365;
    int days2 = day2 + (month2 - 1) * 30 + year2 * 365;

    for (int i = 1; i < year1; i++) {
        if (isLeapYear(i)) days1++;
    }
    for (int i = 1; i < year2; i++) {
        if (isLeapYear(i)) days2++;
    }

    return abs(days2 - days1);
}

// Задание 2
double average(int* arr, int size) {
    if (size == 0) return 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Задание 3
void countElements(int* arr, int size, int& positive, int& negative, int& zero) {
    positive = 0;
    negative = 0;
    zero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positive++;
        else if (arr[i] < 0) negative++;
        else zero++;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1
    int day1 = 10, month1 = 3, year1 = 2021;
    int day2 = 5, month2 = 4, year2 = 2021;
    cout << "Разница в днях: " << daysBetween(day1, month1, year1, day2, month2, year2) << " дней" << endl;

    // 2
    int arr1[] = { 1, 2, 3, 4, 5 };
    cout << "Среднее арифметическое: " << average(arr1, 5) << endl;

    // 3
    int arr2[] = { -1, 0, 2, 3, -5, 0, 7 };
    int positiveCount, negativeCount, zeroCount;
    countElements(arr2, 7, positiveCount, negativeCount, zeroCount);
    cout << "Положительные: " << positiveCount << ", Отрицательные: " << negativeCount << ", Нулевые: " << zeroCount << endl;
    return 0;
}