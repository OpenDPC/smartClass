#pragma once
#include<string.h>
/******************************************************************
 关于 使用char表示一个十进制数有关的一些宏定义
*******************************************************************/
#define ASCII_NUM_9 57
#define ASCII_NUM_0 48
#define POS  1
#define NEG  0
#define  Fix(n) ((n)-ASCII_NUM_0)
#define NOT_NUM 0x88

/******************************************************************
 一个大整数最长的位数
*******************************************************************/
#ifndef MAX_BIT_LEN
#define MAX_BIT_LEN 500
#endif
//简化使用定义 
//#define BintGet(c)  (Bint_input((c))) 
//#define BintShow(b)  (Bint_output((b)))
typedef char bitDec;
class BINT_t
{
public:
	bitDec  numer[MAX_BIT_LEN];//十进制数字 
	char  sign;//符号位 
	unsigned long long len; //长度 
	//交互  
	BINT_t* Bint_input(const char hint[]);
	void Bint_output();
	//无符号加减
	BINT_t* Bint_Unsigned_ADD(BINT_t* op1, BINT_t* op2);
	BINT_t* Bint_Unsigned_SUB(BINT_t* op1, BINT_t* op2);
	//有符号加减 
	BINT_t operator+(BINT_t op2);
	BINT_t operator-(BINT_t op2);
	//乘法 除法 
	BINT_t operator*(BINT_t op2);
	BINT_t operator/(BINT_t op2);
	//模余
	BINT_t* Bint_MOD(BINT_t* op1, BINT_t* op2);

	BINT_t& operator=(const BINT_t other);
	bool operator==(BINT_t& other);
	bool operator>(BINT_t& other);
	bool operator<(BINT_t& other);
};

