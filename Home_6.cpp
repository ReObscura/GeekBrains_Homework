/*
 *###############################################
 * Home_6.cpp                                   #
 *                                              #
 * Created on:14.03.2021                        #
 *                                              #
 * Author: PavelGaevoi                          #
 *                                              #
 * Created with: Clion 2020.3.2, notepad++      #
 *###############################################
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>

//1.  Написать программу, которая создаст два текстовых файла,
//    примерно по 50-100 символов в каждом (особого значения не имеет);

using namespace std;

void makeFile(string *path, string *content) {
    ofstream file;
    file.open(*path);
    if (file.is_open()) {
        file << *content << endl;
    }
    file.close();
}

//2.  Написать функцию, «склеивающую» эти файлы, предварительно буферизуя
//    их содержимое в динамически выделенный сегмент памяти нужного размера.

void concatFiles(char *filename1, char *filename2, char *filenameResult) {
    char *buffer;
    buffer = (char *) calloc(200, sizeof(char));
    FILE *f1, *f2, *f3;
    if ((f1 = fopen(filename1, "r")) == NULL) {
        perror("Error opening file 1\n");
    }
    if ((f2 = fopen(filename2, "r")) == NULL) {
        perror("Error opening file 2\n");
    }
    if ((f3 = fopen(filenameResult, "w")) == NULL) {
        perror("Error opening file 3\n");
    }
    if ((f1 = fopen(filename1, "r")) != NULL) {
        while ((fgets(buffer, 100, f1)) != NULL) {
            fputs(buffer, f3);
        }
        fclose(f1);
    }
    buffer = (char *) calloc(200, sizeof(char));
    if ((f2 = fopen(filename2, "r")) != NULL) {
        while ((fgets(buffer, 100, f2)) != NULL) {
            fputs(buffer, f3);
        }
    }
    fclose(f3);
    free(buffer);
}
//3.  * Написать программу, которая проверяет присутствует ли указанное пользователем
//    при запуске программы слово в указанном пользователем файле
//    (для простоты работаем только с латиницей).

void findTextInFile(char *filename, char *findText) {
    char *buffer;
    buffer = (char *) calloc(200, sizeof(char));
}

int main() {

    //1.
    string path1 = "C:\\cpp\\Text1.txt";
    string path2 = "C:\\cpp\\Text2.txt";
    string content1 = "Down the river drift an axe\n"
                      "From the town of Byron.\n"
                      "Let it float by itself - \n"
                      "Fucking piece of iron!";
    string content2 = "Come Marusia with the duck\nWe will eat and we will fuck!";
    makeFile(&path1, &content1);
    makeFile(&path2, &content2);

    //2.
    char *fileA = "C:\\cpp\\Text1.txt";
    char *fileB = "C:\\cpp\\Text2.txt";
    char *fileC = "C:\\cpp\\Text3.txt";
    concatFiles(fileA, fileB, fileC);
    return 0;
}
