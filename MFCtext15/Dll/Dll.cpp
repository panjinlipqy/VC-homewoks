// Dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Dll.h"


// ���ǵ���������һ��ʾ��
DLL_API int nDll=0;

// ���ǵ���������һ��ʾ����
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
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Dll.h
CDll::CDll()
{
	return;
}
float FACD::convert(float deg){
	return deg/180;
}