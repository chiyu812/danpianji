#ifndef __cunchu_H_
#define __cunchu_H_
#define unint unsigned int
#define unchar unsigned char
#define unlong unsigned long

typedef struct
{
	unlong a;//a第一个数字，b第二个数字
	unlong b;
	unchar chang_a;//a,b的位数
	unchar chang_b;
	unchar flag;//1第一个数字输入中，2第二个数字输入中
	unchar yunsuanfu;//运算符号(1+,2-,3*,4/,5=)
	unlong jieguo;//运算的结果
	unchar chang_jieguo;//结果的位数
	unchar fuhao;//结果的符号(0+,1-)
	unint zheng;//除法的整数部分
	unint xiao;//除法的小数部分
	unchar chufa;//0非除法运算，1除法运算
}cunchu;

typedef struct
{
	unlong answer;//计算得出的结果
	unchar chang;//结果的位数
	unchar fu;//结果的符号(0-,1+)
	unint zheng;//除法的整数部分
	unint xiao;//除法的小数部分
}daan;
#endif