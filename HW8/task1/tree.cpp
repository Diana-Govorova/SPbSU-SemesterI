#include <stdio.h>
#include "tree.h"

struct TreeElement
{
	int key;
	char* value;
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

void push(Tree* tree, int key, char* value)
{
	if (empty(tree))
	{
		tree->head = new TreeElement{ key, value, nullptr, nullptr };
		return;
	}
	TreeElement* helpElement = tree->head;
	while (true)
	{
		if (key > helpElement->key)
		{
			if (helpElement->rightChild == nullptr)
			{
				helpElement->rightChild = new TreeElement{ key, value, nullptr, nullptr };
				break;
			}
			helpElement = helpElement->rightChild;
		}
		if (key < helpElement->key)
		{
			if (helpElement->leftChild == nullptr)
			{
				helpElement->leftChild = new TreeElement{ key, value, nullptr, nullptr };
				break;
			}
			helpElement = helpElement->leftChild;
		}
		if (key == helpElement->key)
		{
			delete helpElement->value;
			helpElement->value = value;
		}
	}
}

// Получение значения элемента
char* returnValue(TreeElement* element)
{
	return element->value;
}

TreeElement* searchElement(Tree* tree, int key, TreeElement** parent)
{
	TreeElement* helpElement = tree->head;
	while (helpElement != nullptr)
	{
		if (key > helpElement->key)
		{
			*parent = helpElement;
			helpElement = helpElement->rightChild;
		}
		else if (key < helpElement->key)
		{
			*parent = helpElement;
			helpElement = helpElement->leftChild;
		}
		else
		{
			return helpElement;
		}
	}
	return nullptr;
}

bool elementAvailability(Tree* tree, int key, TreeElement** parent)
{
	return searchElement(tree, key, parent) != nullptr;
}

TreeElement* findLeftMax(TreeElement* element, TreeElement** parent)
{
	*parent = element;
	element = element->leftChild;
	if (element == nullptr)
	{
		printf("Error\n");
		return nullptr;
	}
	while (element->rightChild != nullptr)
	{
		*parent = element;
		element = element->rightChild;
	}
	return element;
}

void setChild(TreeElement* parent, TreeElement* oldChild, TreeElement* newChild)
{
	if (parent->rightChild == oldChild)
	{
		parent->rightChild = newChild;
	}
	else
	{
		parent->leftChild = newChild;
	}
}

void deleteTreeElement(TreeElement* elementForDeletion)
{
	delete elementForDeletion->value;
	delete elementForDeletion;
}

void deleteElement(Tree* tree, int key)
{
	TreeElement* parent = nullptr;
	TreeElement* elementForDeletion = searchElement(tree, key, &parent);
	if (elementForDeletion == nullptr)
	{
		return;
	}
	if (elementForDeletion->leftChild == nullptr && elementForDeletion->rightChild == nullptr)
	{
		if (tree->head == elementForDeletion)
		{
			deleteTreeElement(tree->head);
			tree->head = nullptr;
			return;
		}
		setChild(parent, elementForDeletion, nullptr);
		deleteTreeElement(elementForDeletion);
		return;
	}
	if (elementForDeletion->leftChild == nullptr && elementForDeletion->rightChild != nullptr)
	{
		if (tree->head == elementForDeletion)
		{
			tree->head = elementForDeletion->rightChild;
			deleteTreeElement(elementForDeletion);
			return;
		}
		setChild(parent, elementForDeletion, elementForDeletion->rightChild);
		deleteTreeElement(elementForDeletion);
		return;
	}
	if (elementForDeletion->rightChild == nullptr && elementForDeletion->leftChild != nullptr)
	{
		if (tree->head == elementForDeletion)
		{
			tree->head = elementForDeletion->leftChild;
			deleteTreeElement(elementForDeletion);
			return;
		}
		setChild(parent, elementForDeletion, elementForDeletion->leftChild);
		deleteTreeElement(elementForDeletion);
		return;
	}
	TreeElement* parentOfchangeElement = nullptr;
	TreeElement* changeElement = findLeftMax(elementForDeletion, &parentOfchangeElement);
	TreeElement* childOfChangeElement = changeElement->leftChild;
	elementForDeletion->value = changeElement->value;
	elementForDeletion->key = changeElement->key;
	setChild(parentOfchangeElement, changeElement, childOfChangeElement);
	delete changeElement;
}

void deleteTree(Tree* tree)
{
	while (!empty(tree))
	{
		int helpKey = tree->head->key;
		deleteElement(tree, helpKey);
	}
	delete tree;
}