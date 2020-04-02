#pragma once
//����
struct StackElement
{
	char value;
	StackElement* next;

};

//������ ��-� � ����
void push(char value, StackElement** head);

//������� ��-� �� �����
char pop(StackElement** head);

//�������� �� �������
bool isEmpty(StackElement* head);

//������� ������� ������� �����
char top(StackElement* head);