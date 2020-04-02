#include "stack.h"


void push(char value, StackElement** head)
{
	StackElement* element = new StackElement{ value, *head };
	*head = element;
}

char pop(StackElement** head)
{
	char headValue = (*head)->value;
	StackElement* help = (*head)->next;
	delete *head;
	*head = help;
	return headValue;
}

char top(StackElement* head)
{
	return head->value;
}

bool isEmpty(StackElement* head)
{
	return head == nullptr;
}
