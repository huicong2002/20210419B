//自然数拆分
/*
对于任意大于1的自然数n，总是可以拆分成若干个小于n的自然数之和。现请你编写程序求出n的所有拆分。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[25];
int n;
void dfs(int sum, int length, int start)
{
	if (sum == n)
	{
		printf("%d=%d", n, arr[0]);

		for (int i = 1; i < length; i++)
		{
			printf("+%d", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i < n; i++)
	{
		if ((i + sum) < n && i >= start)
		{
			arr[length] = i;
			length++;
			dfs(sum + i, length, i);
			length--;
		}
	}
}
int main()
{
	scanf("%d", &n);

	dfs(0, 0, 1);

	return 0;
}