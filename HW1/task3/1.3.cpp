#include <stdio.h>

void reverse(int left, int right, int array[])
{
	for (int i = 0; i < (right - left + 1) / 2; i++)
	{
		const int tmp = array[left + i];
		array[left + i] = array[right - i];
		array[right - i] = tmp;
	}
}

int main()
{
	int m = 0;
	int n = 0;
	printf("Enter the lengths of the parts m and n");
	scanf("%i %i", &m, &n);
	int* array = new int[m + n]{};
	for (int i = 0; i < m + n; i++)
	{
		scanf("%d", &array[i]);
	}

	reverse(0, m - 1, array);
	reverse(m, m + n - 1, array);
	reverse(0, m + n - 1, array);
	for (int i = 0; i < m + n; i++)
	{
		printf("%i", array[i]);
	}
	delete[] array;
	return 0;
}