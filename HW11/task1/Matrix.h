#pragma once

// Создать матрицу.
int** createMatrix(int size);

// Печать матрицы.
void printMatrix(int** matrix, int size);

// Удалить матрицу.
void deleteMatrix(int** matrix, int size);

// Прочитать матрицу с файла.
void readMatrixFromFile(int** matrix, int size, FILE* file);