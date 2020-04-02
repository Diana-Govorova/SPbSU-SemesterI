#include <stdio.h>
#include <string.h>

struct Record
{
	char* name;
	char* number;
};

Record newPerson()
{
	printf("Imput name\n");
	char* name = new char[100]{};
	scanf("%s", name);
	printf("Input number\n");
	char* number = new char[100]{};
	scanf("%s", number);
	Record result { name, number };
	return result;
}

void writeRecord(Record array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%s %s\n",  array[i].name, array[i].number);
	}
}

char* findNumber(Record array[], int length, const char* name)
{
	for (int i = 0; i < length; i++)
	{
		if (strcmp(array[i].name, name) == 0)
		{
			return array[i].number;
		}
	}
	return nullptr;
}

char* findName(Record array[], int length, const char* number)
{
	for (int i = 0; i < length; i++)
	{
		if (strcmp(array[i].number, number) == 0)
		{
			return array[i].name;
		}
	}
	return nullptr;
}

void saveInFile(Record array[], int length)
{
	FILE* out = fopen("phonenumber.txt", "w");
	for (int i = 0; i < length; i++)
	{
		fprintf(out, "%s %s\n", array[i].name, array[i].number );
	}
	fclose(out);
}

void  openFile(const char* fileName, Record array[], int* length)
{

	FILE* in = fopen(fileName, "r");
	if (in == nullptr)
	{
		return;
	}
	int i = 0;
	while (!feof(in))
	{
		char* name = new char[100]{};
		int nameReadCount = fscanf(in, "%s", name);
		char* number = new char[100]{};
		int numberReadCount = fscanf(in, "%s", number);
		if (nameReadCount <= 0 && numberReadCount <= 0)
		{
			break;
		}
		else
		{
			array[i].name = name;
			array[i].number = number;
			i++;
		}
	}
	fclose(in);
	*length = i;
}

bool testFindName()
{
	Record array[2]{};
	array[0].name = new char[5] {"jack"};
	array[0].number = new char[4] {"234"};
	array[1].name = new char[6] {"loura"};
	array[1].number = new char[4] {"123"};
	const bool test1result = strcmp(findName(array, 2, "234"), "jack") == 0;
	const bool test2result = findName(array, 2, "2345") == nullptr;
	return test1result && test2result;
}

bool testFindNumber()
{
	Record array[2]{};
	array[0].name = new char[5] {"jack"};
	array[0].number = new char[4] {"234"};
	array[1].name = new char[6] {"loura"};
	array[1].number = new char[4] {"123"};
	const bool test1result = strcmp(findNumber(array, 2, "jack"), "234") == 0;
	const bool test2result = findNumber(array, 2, "nick") == nullptr;
	return test1result && test2result;
}

bool readFromFileTest()
{
	int length = 0;
	Record array[2]{};
	openFile("test.txt", array, &length);
	if (strcmp(array[0].name, "rtio") != 0 || strcmp(array[0].number, "456") != 0)
	{
		return false;
	}
	if (strcmp(array[1].name, "wer") != 0 || strcmp(array[1].number, "678") != 0)
	{
		return false;
	}
	return true;
}

int main()
{

	if (!testFindNumber() || !testFindName() || !readFromFileTest())
	{
		printf("All is bad\n");
		return -1;
	}
	Record array[100]{};
	int firstEmpty = 0;
	openFile("phonenumber.txt", array, &firstEmpty);
	printf("Please, enter command");
	while (true)
	{	
		char command = '\0';
		scanf("%c", &command);
		switch (command)
		{
		case '0':
			break;
		case '1':
			printf("record new person\n");
			array[firstEmpty] = newPerson();
			firstEmpty++;
			break;
		case '2':
			printf("Records:\n");
			writeRecord(array, firstEmpty);
			break;
		case '3':
		{
			printf("Find number\n");
			printf("Please, enter name: ");
			char name[100]{};
			scanf("%s", name);
			char* number = findNumber(array, firstEmpty, name);
			if (number == nullptr)
			{
				printf("Sorry, number not found");
			}
			else
			{
				printf("%s", number);
			}
			break;
		}
		case '4':
		{
			printf("Find name\n");
			printf("Please, enter number: ");
			char number[100]{};
			scanf("%s", number);
			char* name = findName(array, firstEmpty, number);
			if (name == nullptr)
			{
				printf("Sorry, name not found");
			}
			else
			{
				printf("%s", name);
			}
			break;
		}
		case '5':
			printf("Save");
			saveInFile(array, firstEmpty);
			break;
		}
		if (command == '0')
		{
			break;
		}
	}
	return 0;
}