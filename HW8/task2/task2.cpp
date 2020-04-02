#include <stdio.h>
#include "tree.h"


bool test()
{
	char string1[13]{ "/ (+ 13 2) 5" };
	Tree* tree = buildTree(string1);
	const bool test1Result = valueExpression(tree) == 3;
	deleteTree(tree);
	return test1Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	char string[100];
	FILE* in = fopen("Text.txt", "r");
	fgets(string, 100, in);
	fclose(in);
	Tree* tree = buildTree(string);
	printf("Finally tree: ");
	printTree(tree);
	printf("\n");
	printf("Value expresssion: ");
	printf("%d", valueExpression(tree));
	deleteTree(tree);
	return 0;
}