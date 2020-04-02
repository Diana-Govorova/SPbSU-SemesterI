#pragma once

typedef int Value;

//Стек
struct StackElement
{
	Value value;
	StackElement* next;
};

// Кладет эл-т в стек
void push(Value value, StackElement** head);

// Снимает эл-т со стека
Value pop(StackElement** head);

// Проверяет пуст ли стек
bool isEmpty(StackElement* head);
