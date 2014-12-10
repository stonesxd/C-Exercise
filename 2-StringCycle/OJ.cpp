
#include "OJ.h"
#include <string.h>


/*
功能:计算字符串的最小周期。
原型：
    int GetMinPeriod(char *string);

输入参数：
    char * string：字符串。

返回值：
    int 字符串最小周期。

*/

int GetMinPeriod(char *inputstring)
{
    /*在这里实现功能*/
	int len = strlen(inputstring);
	int flag = 0;
	int period = 1;

	for (period=1; period <= len; period ++)
	{
		if (len % period == 0)	// period 为周期，字符串长度 len 定能整除 period
		{
			flag = 1;
			for (int j=period; j < len; j ++)	// 比较 s[j] 与 首个周期的s[j % period]元素 是否相同
			{
				if (inputstring[j] != inputstring[j % period])	//如果出现不一样，则不是周期字符串
				{
					flag = 0;
					break;
				}
			}
			if (flag)	//说明已经找到最小周期
			{
				break;
			}
		}
	}
	return period;
}
