#ifndef __LCD1602_H_
#define __LCD1602_H_
#define unint unsigned int
#define unchar unsigned char
#define unlong unsigned long
void xiez(unchar zhiling);//向LCD写入指令
void LCD_chushi();//LCD初始化
void shuzi(unchar hang,unchar lie,unlong shuzi,unchar changdu); //显示无符号数字shuzi(1,1,123,3);
void zifu(unchar hang,unchar lie,unchar zifu);  //显示字符zifu(1,1,'a');
void zifuchuan(unchar hang,unchar lie,unchar zifuchuan[]);  //显示字符串zifuchuan(1,1,"Abc")

#endif