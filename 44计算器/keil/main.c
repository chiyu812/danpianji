#include <REGX52.H>
#include "cunchu.h"
#include "LCD1602.h"
#include "jvzhenjianpan.h"
#include "anjianchuli.h"

#define unint unsigned int
#define unchar unsigned char
	
unchar key;//按键值
cunchu Q;//a,b的相关信息
void main()
{
	LCD_chushi();
	while(1)
	{
		key=jvzhenjianpan();
		if(key)
		{
			Q=anjianchuli(key);
			
			if(Q.yunsuanfu!=5)//a,b数值输入
			{
				zifuchuan(3-Q.flag,13,"    ");   
				shuzi(3-Q.flag,17-Q.chang_a,Q.a,Q.chang_a);
				if(Q.flag==2)
				{
					zifuchuan(2,2,"               ");
					zifuchuan(Q.flag,13,"    "); 
					shuzi(Q.flag,17-Q.chang_b,Q.b,Q.chang_b);
				}
			}
			else//a,b计算结果得出
			{
				zifuchuan(2,2,"               ");
				zifu(2,1,'=');
				if(Q.chufa==0)//加、减、乘法运算
				{
					shuzi(2,17-Q.chang_jieguo,Q.jieguo,Q.chang_jieguo);
					if(Q.fuhao)
					zifu(2,17-Q.chang_jieguo-1,'-');
				}
				else//除法运算
				{
					if(Q.xiao!=0)//除不尽,保留两位小数
					{
						shuzi(2,14-Q.chang_jieguo,Q.zheng,Q.chang_jieguo);
						zifu(2,14,'.');
						shuzi(2,15,Q.xiao,2);
					}
					else//能够除尽
					shuzi(2,17-Q.chang_jieguo,Q.zheng,Q.chang_jieguo);
				}
			}
		}
	}
}

