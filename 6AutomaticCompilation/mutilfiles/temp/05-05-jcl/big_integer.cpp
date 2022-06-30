/*
* 项目名称：大整数运算符的重载（友元部分）
* 输    入：两个整数
* 输    出：相关运算符的运算结果、过程
* 时    间：2022年5月12日
*/
#include"biginterger.h"
#include <cstddef>
#include<iostream>
/*************************************
 这里可以定义自己的最长位数
 #define MAX_BIT_LEN  XXX
 ************************************/
using namespace std;
int main() {
	BINT_t* op1=nullptr;
	BINT_t* op2=nullptr;
	BINT_t rst;
	
	while ((op1 = op1->Bint_input("第一个操作数")) == NULL);
	while ((op2 = op2->Bint_input("第一个操作数")) == NULL);
	rst = *op1 + *op2;
	/*rst.Bint_output();*/
	rst = *op1 * *op2;
	rst = *op1 - *op2;
	rst = *op1 / *op2;
	cout << "----------比较（相等）------"<<endl;
	if (*op1==*op2)
	{
		std::cout << "Equal";
	}
	else
	{
		cout << "Unequal";
	}
	return 0;
}