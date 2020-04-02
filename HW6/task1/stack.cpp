#include "stack.h"


void push(int value, StackElement** head)
{
	StackElement* element = new StackElement{ value, *head };
	*head = element;
}

int pop(StackElement** head)
{
	int headValue = (*head)->value;
	StackElement* help = (*head)->next;
	delete *head;
	*head = help;
	return headValue;
}

bool isEmpty(StackElement* head)
{
	return head == nullptr;
}
