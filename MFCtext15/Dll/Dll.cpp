// Dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Dll.h"


// 这是导出变量的一个示例
DLL_API int nDll=0;

// 这是导出函数的一个示例。
DLL_API int fnDll(void)
{
	return 42;
}

DLL_API int factorial_1(int n){
	int sum = 1;
	if(n >10) return 0;
	else{
	for(int i =1; i<=n; i++)
		sum = sum * i;

	return sum;
	}
}
// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Dll.h
CDll::CDll()
{
	return;
}
float FACD::convert(float deg){
	return deg/180;
}