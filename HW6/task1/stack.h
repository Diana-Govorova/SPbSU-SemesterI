#pragma once

typedef int Value;

//����
struct StackElement
{
	Value value;
	StackElement* next;
};

// ������ ��-� � ����
void push(Value value, StackElement** head);

// ������� ��-� �� �����
Value pop(StackElement** head);

// ��������� ���� �� ����
bool isEmpty(StackElement* head);
