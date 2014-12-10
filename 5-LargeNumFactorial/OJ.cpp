#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "OJ.h"

void CalcNN(int n, char *pOut)
{
	int digits = 1;
	int cy = 0;

	pOut[0] = 1;
	
	for (int i=2; i <= n; i ++)
	{
		cy = 0;
		for (int j = 1; j <= digits; j ++)
		{
			int tp = pOut[j - 1] * i + cy;
			pOut[j - 1] = tp % 10;
			cy = tp / 10;
		}
		while (cy)
		{
			digits++;
			pOut[digits - 1] = cy % 10;
			cy = cy / 10;
		}
	}
	for (int i = 0; i < digits; i ++)
	{
		pOut[i] += '0';
	}
	pOut[digits] = '\0';
	char *pTail = pOut + digits - 1;
	while (pOut < pTail)
	{
		char c = *pOut;
		*pOut = *pTail;
		*pTail = c;
		pOut ++;
		pTail --;
	}

	return;
}