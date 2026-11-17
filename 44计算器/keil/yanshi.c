#define unint unsigned int
#define unchar unsigned char

void yanshi(unint t)//1ms延时函数
{
	unchar x,y;
	while(t--)
	{
		x=2;
		y=239;
		do
		{
			while(--y);	
		}
		while(--x);
	}
}
