#pragma once
#include "List.h"

const int size = 10;
const int maxDistance = 2000000000;

// Построение разбиения городов между столицами.
void captureOfCities(int graph[size][size], int capitals[], int amountOfCapitals, int sizeOfGraph, List* countries[]);