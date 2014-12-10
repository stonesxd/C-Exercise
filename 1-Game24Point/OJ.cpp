/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define CNT			4	// 4个数字之间24点计算 
#define VALUE		24	//计算24点

static const double LIMITMIN = 1E-6;	//判断浮点数与整数之间是否相等
static bool m_judge = false;	//  a, b, c, d 是否有解
static double number[CNT];	// 保存计算过程中的值

/************************************************************************/
/* 思想：先对四个数中任意2个数进行四则运算，得到的结果与其他2个再组合成3个数 */
/* 然后，再对三个数中任意2个数进行四则运算，得到的结果与剩下1个再组合*/
/* 最后，再对剩下2个数进行四则运算，得到结果为24则，说明成功，否则不成功*/
/* Param: n 表示还剩下几个数进行运算，当n = 1时，说明就是计算结果 */
/************************************************************************/
bool is24Points(int n)	//递归调用
{
	if (1 == n)	//判断计算结果
	{
		if (fabs(number[0] - VALUE) <= LIMITMIN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// 任意2个数之间的四则运算
	for (int i = 0; i < n; i ++)
	{
		for (int j = i+1; j < n; j ++)
		{
			double ta, tb;
			ta = number[i];		//保存起来，万一计算不正确，则恢复
			tb = number[j];
			
			number[j] = number[n-1];	//把最后一个数放最2个位置，也方便进行下一步计算
			//测试 加法 是否可以
			number[i] = ta + tb;
			if (is24Points(n-1))
			{
				return true;
			}
			//测试 减法 是否可以
			number[i] = ta	- tb;
			if (is24Points(n-1))
			{
				return true;
			}
			number[i] = tb	- ta;
			if (is24Points(n-1))
			{
				return true;
			}

			//测试 乘法 是否可以
			number[i] = ta * tb;
			if (is24Points(n-1))
			{
				return true;
			}
			//测试 除法 是否可以
			if (tb != 0)
			{
				number[i] = ta / tb;
				if (is24Points(n-1))
				{
					return true;
				}
			}
			if (ta != 0)
			{
				number[i] = tb / ta;
				if (is24Points(n-1))
				{
					return true;
				}
			}
			// 如果都不可行，则恢复，进行下一轮的计算
			number[i] = ta;
			number[j] = tb;
		}
	}
	return false;
}

bool Game24Points(int a, int b, int c, int d)
{
	//TODO: Add codes here ...
	number[0] = a;
	number[1] = b;
	number[2] = c;
	number[3] = d;

	return is24Points(CNT);
}

