#include <string.h>//包含memset()
#include "cunchu.h"
daan tmp;
unchar getwei(unlong t);//计算结果位数


daan yunsuan(cunchu t)//运算函数
{
	memset(&tmp,0,sizeof(tmp));//运算前将全部元素设置为0，避免残留
	if(t.yunsuanfu==1)//加法运算
	{
		tmp.answer=t.a+t.b;//得出结果
		tmp.chang=getwei(tmp.answer);//计算结果位数
	}
	
	if(t.yunsuanfu==2)//减法运算
	{
		if(t.a<t.b)//结果为负数
		{
			tmp.answer=t.b-t.a;
			tmp.fu=1;
		}
		else
			tmp.answer=t.a-t.b;//结果为正数
		tmp.chang=getwei(tmp.answer);//计算结果位数
	}
	
	if(t.yunsuanfu==3)//乘法运算
	{
		tmp.answer=t.a*t.b;//得出结果
		tmp.chang=getwei(tmp.answer);//计算结果位数
	} 

	if(t.yunsuanfu==4)//除法运算
	{
		unlong an=(t.a*1000)/t.b;
		tmp.answer=(an+5)/10;//进行四舍五入，保留两位小数
		tmp.zheng=tmp.answer/100;//结果整数部分
		tmp.xiao=tmp.answer%100;//结果小数部分(2位小数)
		tmp.chang=getwei(tmp.zheng);
	}
	return tmp;
}

unchar getwei(unlong t)//计算结果位数
{
	unchar i=0;
	if (t==0) return 1;//0视为1位数
  while(t>0)
  {
		i++;
    t/= 10;
  }
  return i;
}