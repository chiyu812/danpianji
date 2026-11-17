#include <REGX52.H>
#include "yanshi.h"
#define unint  unsigned int
#define unchar unsigned char
#define unlong unsigned long
	
sbit RS=P2^0; //1处理数据，0处理指令
sbit RW=P2^1; //1读，0写
sbit E= P2^2; //上升沿：向LCD写入DATA(shujv/zhiling)

#define DATA P1	//LCD接收发送数据端口

void xiez(unchar zhiling);//向LCD写入指令
void xies(unchar shujv);//向LCD写入数据
void guangbiao(unchar hang,unchar lie);//设置光标位置
unlong cifang(int x,int y);//返回次方数，以便显示不同进制的数字时，配合%10剥离每一位

void LCD_chushi()//LCD初始化
{
	xiez(0x38);
	xiez(0x0C);
	xiez(0x06);
	xiez(0x01);
}

void shuzi(unchar hang,unchar lie,unlong shuzi,unchar changdu) //显示无符号数字
{
	unchar i;
	guangbiao(hang,lie);
	for(i=0;i<changdu;i++)
	{ 
		xies(shuzi/cifang(10,changdu-i-1)%10 +0x30);
		//shuzi/cifang(10,changdu-i-1)%10:从高到低剥离每一位，
		//+0x30:将剥离好的每一位转化为ASII码，进行显示
	}
	
}

void zifu(unchar hang,unchar lie,unchar zifu)  //显示字符
{
	guangbiao(hang,lie);
	xies(zifu);
}
	
void zifuchuan(unchar hang,unchar lie,unchar zifuchuan[])  //显示字符串
{
	unchar i;
	guangbiao(hang,lie);
	for(i=0;zifuchuan[i]!='\0';i++)
	{
		xies(zifuchuan[i]);
	}
}

void xiez(unchar zhiling)//向LCD写入指令
{
	RS=0;
	RW=0;
	E=0;
	DATA=zhiling;
	E=1;//上升沿写入数据
	yanshi(1);
	E=0;
}

void xies(unchar shujv)//向LCD写入数据
{
	RS=1;
	RW=0;
	E=0;
	DATA=shujv;
	E=1;//上升沿写入数据
	yanshi(1);
	E=0;
}

void guangbiao(unchar hang,unchar lie)//设置光标位置
{
	if(hang==1)//第1行，1-16列
	{
		xiez(0x80|(lie-1));
	}
	else//第2行，1-16列
	{
		xiez(0x80|(lie-1)+0x40);
	}
}

unlong cifang(int x,int y)//返回次方数，以便显示不同进制的数字时，配合%10剥离每一位
{
	unlong jieguo=1;
	unchar i;
	for(i=0;i<y;i++)
	{
		jieguo=jieguo*x;
	}
	return jieguo;
}