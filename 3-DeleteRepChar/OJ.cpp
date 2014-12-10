#include <iostream>
#include <string>
#include "OJ.h"


/*
Description  
         ����һ���ַ��������ַ��������к�ǰ���ظ�������ַ�ɾ���������ַ�����������������ַ�������Ҫ��֤�ַ����ֵ��Ⱥ�˳��
Prototype
         int GetResult(const char *input, char *output)
Input Param 
         input     ������ַ���
Output Param 
         output    ������ַ���
Return Value
         0         �ɹ�
         -1        ʧ�ܼ��쳣
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
