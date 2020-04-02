#pragma once

// Создание матрицы.
int** createMatrix(int size);

// Печать матрицы.
void printMatrix(int** matrix, int size);

// Удаление матрицы.
void deleteMatrix(int** matrix, int size);

// Чтение матрицы из файла.
void readMatrixFromFile(int** matrix, int size, FILE* file);