
#include "OJ.h"
#include <string.h>


/*
����:�����ַ�������С���ڡ�
ԭ�ͣ�
    int GetMinPeriod(char *string);

���������
    char * string���ַ�����

����ֵ��
    int �ַ�����С���ڡ�

*/

int GetMinPeriod(char *inputstring)
{
    /*������ʵ�ֹ���*/
	int len = strlen(inputstring);
	int flag = 0;
	int period = 1;

	for (period=1; period <= len; period ++)
	{
		if (len % period == 0)	// period Ϊ���ڣ��ַ������� len �������� period
		{
			flag = 1;
			for (int j=period; j < len; j ++)	// �Ƚ� s[j] �� �׸����ڵ�s[j % period]Ԫ�� �Ƿ���ͬ
			{
				if (inputstring[j] != inputstring[j % period])	//������ֲ�һ�������������ַ���
				{
					flag = 0;
					break;
				}
			}
			if (flag)	//˵���Ѿ��ҵ���С����
			{
				break;
			}
		}
	}
	return period;
}
