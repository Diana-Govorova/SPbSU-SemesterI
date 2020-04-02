#pragma once
//Стек
struct StackElement
{
	char value;
	StackElement* next;

};

//Кладет эл-т в стек
void push(char value, StackElement** head);

//Снимает эл-т со стека
char pop(StackElement** head);

//Проверка на пустоту
bool isEmpty(StackElement* head);
