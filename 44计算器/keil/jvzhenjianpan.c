//P0为矩阵键盘接口
#include <REGX52.H>
#include "yanshi.h" 
#define unint unsigned int
#define unchar unsigned char
	
unchar jvzhenjianpan()//获取矩阵键盘键值
{
	unchar key=0;
	P0=0XFF;
	P0_0=0;//第一行
	if(P0_4==0){yanshi(20);while(P0_4==0);yanshi(20);key=1;}
	if(P0_5==0){yanshi(20);while(P0_5==0);yanshi(20);key=2;}
	if(P0_6==0){yanshi(20);while(P0_6==0);yanshi(20);key=3;}
	if(P0_7==0){yanshi(20);while(P0_7==0);yanshi(20);key=10;}//+
	
	P0=0XFF;
	P0_1=0;//第二行
	if(P0_4==0){yanshi(20);while(P0_4==0);yanshi(20);key=4;}
	if(P0_5==0){yanshi(20);while(P0_5==0);yanshi(20);key=5;}
	if(P0_6==0){yanshi(20);while(P0_6==0);yanshi(20);key=6;}
	if(P0_7==0){yanshi(20);while(P0_7==0);yanshi(20);key=11;}//-
	
	P0=0XFF;
	P0_2=0;//第三行
	if(P0_4==0){yanshi(20);while(P0_4==0);yanshi(20);key=7;}
	if(P0_5==0){yanshi(20);while(P0_5==0);yanshi(20);key=8;}
	if(P0_6==0){yanshi(20);while(P0_6==0);yanshi(20);key=9;}
	if(P0_7==0){yanshi(20);while(P0_7==0);yanshi(20);key=12;}//*
	
	P0=0XFF;
	P0_3=0;//第四行
	if(P0_4==0){yanshi(20);while(P0_4==0);yanshi(20);key=13;}//DEL  
	if(P0_5==0){yanshi(20);while(P0_5==0);yanshi(20);key=16;}
	if(P0_6==0){yanshi(20);while(P0_6==0);yanshi(20);key=14;}// =
	if(P0_7==0){yanshi(20);while(P0_7==0);yanshi(20);key=15;}//  /

	return key;
}