#pragma once

// Создание матрицы.
int** createMatrix(int sizeOfString, int sizeOfColumns);

// Печать матрицы.
void printMatrix(int** matrix, int sizeOfString, int sizeOfColumns);

// Удаление матрицы.
void deleteMatrix(int** matrix, int sizeOfString, char* header);

// Чтение матрицы из файла.
void readMatrixFromFile(int** matrix, int sizeOfString, int sizeOfColumns, FILE* file, char* header);

// Получить индекс переменной из массива заголовков.
int index(char* array, int size, char symbol);
