/*
 *###############################################
 * Home_4.cpp                                   #
 *                                              #
 * Created on:04.03.2021                        #
 *                                              #
 * Author: PavelGaevoi                          #
 *                                              #
 * Created with: Clion 2020.3.2, notepad++      #
 *###############################################
*/

#include <iostream>
#include <stdio.h>

//1. Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до 20 (включительно),
// если да – вывести true, в противном случае – false;

void ifSumFrom10To20(int *a, int *b) {
    if ((*a + *b) >= 10 && (*a + *b) <= 20) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

//2. Написать программу, проверяющую, является ли некоторое число - натуральным простым.
// Простое число - это число, которое делится без остатка только на единицу и себя само.

void ifNumIsSimple(int *a) {
    int i = 2;
    bool isSimple = 1;
    while (i < *a) {
        if (*a % i == 0) {
            isSimple = 0;
            break;
        }
        i++;
    }
    printf(isSimple == 1 ? "Number %d is simple\n" : "Number %d is not simple\n", *a);
}

//3. Написать программу, выводящую на экран “истину”, если две целочисленные константы,
// объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.

void ifMultiply10(int *a, int *b) {
    if ((*a == *b == 10) || (*a + *b == 10)) {   //так понял, что либо обе равны 10, либо их сумма равна 10
        //иначе условие будет выглядеть так: (((*a == 10) || (*b == 10)) || (*a + *b == 10))
        std::cout << "true" << std::endl;
    }
}

//4. * Написать программу, которая определяет является ли год високосным.
// Каждый 4-й год является високосным, кроме каждого 100-го,
// при этом каждый 400-й – високосный.
// Для проверки работы вывести результаты работы программы в консоль

void ifLeapYear(int *year) {
    bool leap = 0;
    if (*year % 4 == 0) {
        leap = 1;
        if (*year % 100 == 0) {
            leap = 0;
            if (*year % 400 == 0) {
                leap = 1;
            }
        }
    }
    printf(leap == 1 ? "%dth year is leap\n" : "%dth year is not leap\n", *year);
}

int main() {
    //1.
    int a = 11;
    int b = 7;
    ifSumFrom10To20(&a, &b);

    //2.
    int n = 17;
    ifNumIsSimple(&n);

    //3.
    int c = 10;
    int d = 0;
    ifMultiply10(&c, &d);

    //4.
    int year1 = 1999;
    int year2 = 2000;
    int year3 = 2100;
    ifLeapYear(&year1);
    ifLeapYear(&year2);
    ifLeapYear(&year3);

    return 0;
}
