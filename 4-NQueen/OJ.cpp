#include <stdio.h>
#include <stdlib.h>
#include "OJ.h"

#define MAXQUEEN 20

static int queen[MAXQUEEN], sum = 0;

int check(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
		{
			return 1;
		}
	}
	return 0;
}

void putQueen(int n, int max)
{
	for (int i = 0; i < max; i ++)
	{
		queen[n] = i;
		if (!check(n))
		{
			if (n == max -1)
			{
				sum	++;
			}
			else
			{
				putQueen(n+1, max);
			}
		}
	}
}

/*
功能: 求解放置8皇后方案的个数。
输入：
    无
返回：
    int：放置8皇后方案的个数
*/

int PlaceQueenMethodNum(int n)
{
    /*在这里实现功能*/
	putQueen(0, n);

    return sum;
}

