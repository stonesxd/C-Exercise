#include <iostream>
#include <string>
#include "OJ.h"


/*
Description  
         给定一个字符串，将字符串中所有和前面重复多余的字符删除，其余字符保留，输出处理后的字符串。需要保证字符出现的先后顺序。
Prototype
         int GetResult(const char *input, char *output)
Input Param 
         input     输入的字符串
Output Param 
         output    输出的字符串
Return Value
         0         成功
         -1        失败及异常
*/
int GetResult(const char *input, char *output)
{
    if (input == NULL || output == NULL)
	{
		return -1;
	}

	output[0] = input[0];
	int len = strlen(input);
	int i = 0, j = 1, flag = 0;
	for (i = 1; i < len; i ++)
	{
		flag = 1;
		for (int k = 0; k < j; k ++)
		{
			if (output[k] == input[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			output[j] = input[i];
			j ++;
		}
	}
	output[j] = '\0';

    return 0;
}
