#include"stdafx.h"
#include"w32.h"

int factorial(int n){

	int sum = 1;
	if(n >10) return 0;
	else{
	for(int i =1; i<=n; i++)
		sum = sum * i;

	return sum;
	}
}

float FAC::convert(float deg){
	return deg/180;
}