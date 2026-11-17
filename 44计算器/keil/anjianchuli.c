#include <REGX52.H>
#include <string.h>//包含memset()
#include "cunchu.h"
#include "LCD1602.h"
#include "yunsuan.h"
#include "yanshi.h"
#define unchar unsigned char
#define QING  0x01//清屏指令	
cunchu temp={0,0,0,0,1};//相当于a,b的副本
daan zhong;

cunchu anjianchuli(unchar key)//按键处理函数
{
	if(key<10||key==16)//按下1-9,0数字键
	{
		if(temp.flag==1)//a输入
		{
			temp.a=(key==16)?temp.a*10:temp.a*10+key;
			temp.chang_a++;
		}
		else//b输入
		{
			temp.b=(key==16)?temp.b*10:temp.b*10+key;
			temp.chang_b++;
		}
		
		//a,b输入超出范围
		if(temp.chang_a>4||temp.chang_b>4)
		{
			
			xiez(QING);//LCD清屏
			yanshi(1);
			zifuchuan(1,6,"INPUT");
			zifuchuan(2,3,"OUT OF RANGE");
			yanshi(2000);
			xiez(QING);//LCD清屏
			yanshi(1);
			
			if(temp.chang_a>4)//a超出范围
			{
				temp.a=0;
				temp.chang_a=0;
			}
			else//////////////b超出范围
			{
				temp.b=0;
				temp.chang_b=0;
				switch(temp.yunsuanfu)
				{
					case 1:zifu(2,1,'+');break;
					case 2:zifu(2,1,'-');break;
					case 3:zifu(2,1,'*');break;
					case 4:zifu(2,1,'/');break;
				}
			}
			return temp;
		}
	}
	
	//////////////////// 按下+-*/运算按键
	if(key==10)//+
	{
		temp.flag=2;
		zifu(2,1,'+');
		temp.yunsuanfu=1;//运算符号为+
	}
	if(key==11)//-
	{
		temp.flag=2;
		zifu(2,1,'-');
		temp.yunsuanfu=2;//运算符号为-
	}
	if(key==12)//*
	{
		temp.flag=2;
		zifu(2,1,'*');
		temp.yunsuanfu=3;//运算符号为*
	}
	if(key==15)//  /
	{
		temp.flag=2;
		zifu(2,1,'/');
		temp.yunsuanfu=4;//运算符号为 /
		temp.chufa=1;
	}
	
	
	/////////////////按下=键
	if(key==14)//=
	{
		if(temp.yunsuanfu==4&&temp.b==0)//除法运算进行除数判断，除数不能为0
		{
			xiez(QING);//LCD清屏
			yanshi(1);
			zifuchuan(1,6,"ERROR");//除数不能为0
			zifuchuan(2,5,"DIV BY 0");
			yanshi(2000);
			xiez(QING);//LCD清屏
			yanshi(1);
			
			temp.b=0;
			temp.chang_b=0;
			zifu(2,1,'/');		
		}
		else//输入正常，进行计算
		{
			zhong=yunsuan(temp);
			if(temp.yunsuanfu!=4)//+-*运算
			{
				temp.jieguo=zhong.answer;
				temp.chang_jieguo=zhong.chang;
				temp.fuhao=zhong.fu;
				
			}
			else//  /运算
			{
				temp.zheng=zhong.zheng;
				temp.xiao=zhong.xiao;
				temp.chang_jieguo=zhong.chang;
			}	
			shuzi(1,16-temp.chang_b-temp.chang_a,temp.a,temp.chang_a);//运算完成，第一行显示算式
			shuzi(1,17-temp.chang_b,temp.b,temp.chang_b);
			switch(temp.yunsuanfu)
			{
				case 1:zifu(1,16-temp.chang_b,'+');break;
				case 2:zifu(1,16-temp.chang_b,'-');break;
				case 3:zifu(1,16-temp.chang_b,'*');break;
				case 4:zifu(1,16-temp.chang_b,'/');break;
			}
			
			temp.yunsuanfu=5;//运算符号为 =
		}
	}
	
	////////////////按下delete键
	if(key==13)//delete
	{
		if(temp.yunsuanfu==5)//运算完成，直接清空
		{
			memset(&temp,0,sizeof(temp));//将全部元素设置为0
			temp.flag=1;//设置为输入a
			xiez(QING);//LCD清屏
			yanshi(1);
		}
		else//运算未完成，删除
		{
			if(temp.flag==1)//输入a时
			{
				temp.a=temp.a/10;
				if(temp.chang_a>0)
				temp.chang_a--;
			}
			if(temp.flag==2)//输入b时
			{
				temp.b=temp.b/10;
				if(temp.chang_b>0)
				temp.chang_b--;
			}	
		}
	}
	
	return temp;
}