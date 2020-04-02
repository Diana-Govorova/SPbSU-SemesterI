#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "tree.h"

struct TreeElement
{
	char action;
	int value;
	TreeElement* leftChild = nullptr;
	TreeElement* rightChild = nullptr;
};

struct Tree
{
	TreeElement* head = nullptr;
};

Tree* create()
{
	return new Tree;
}

bool empty(Tree* tree)
{
	return tree->head == nullptr;
}

TreeElement* returnHead(Tree* tree)
{
	return tree->head;
}

int buildNumber(char* string, int* position)
{
	int answer = 0;
	while (string[*position] >= '0' && string[*position] <= '9')
	{
		answer = answer * 10 + (string[*position] - '0');
		(*position)++;
		if (string[*position] == '\0')
		{
			return answer;
		}
	}
	return answer;
}

TreeElement* returnElement(char* string, int* position)
{
	TreeElement* element = nullptr;
	while (string[*position] == '(' || string[*position] == ')' || string[*position] == ' ')
	{
		(*position)++;
		if (string[*position] == '\0')
		{
			return nullptr;
		}
	}
	if (string[*position] >= '0' && string[*position] <= '9')
	{
		int number = buildNumber(string, position);
		return new TreeElement{ '\0', number, nullptr, nullptr };
	}
	else
	{
		element = new TreeElement{ string[*position], 0, nullptr, nullptr };
		(*position)++;
		if (string[*position] == '\0')
		{
			return nullptr;
		}
		element->leftChild = returnElement(string, position);
		element->rightChild = returnElement(string, position);
	}
	return element;
}

Tree* buildTree(char* string)
{
	Tree* tree = create();
	int position = 0;
	tree->head = returnElement(string, &position);
	return tree;
}

int actionOnValue(TreeElement* element)
{
	if (element->action != '\0')
	{
		int leftValue = actionOnValue(element->leftChild);
		int rightValue = actionOnValue(element->rightChild);
		switch (element->action)
		{
			case '+':
			{
				return leftValue + rightValue;
			}
			case '-':
			{
				return leftValue - rightValue;
			}
			case '*':
			{
				return leftValue * rightValue;
			}
			case '/':
			{
				return leftValue / rightValue;
			}
		}
	}
	else
	{
		return element->value;
	}
}

int valueExpression(Tree* tree)
{
	return actionOnValue(tree->head);
}

void printElement(TreeElement* element)
{
	if (element->action != '\0')
	{
		printf("( ");
		printf("%c ", element->action);
		printElement(element->leftChild);
		printElement(element->rightChild);
		printf(") ");
	}
	else
	{
		printf("%d ", element->value);
	}
}

void printTree(Tree* tree)
{
	if (tree->head != nullptr)
	{
		printElement(tree->head);
	}
}

void deleteElement(TreeElement* element)
{
	if (element == nullptr)
	{
		return;
	}
	deleteElement(element->leftChild);
	deleteElement(element->rightChild);
	delete element;
}

void deleteTree(Tree* tree)
{
	deleteElement(tree->head);
	delete tree;
}
