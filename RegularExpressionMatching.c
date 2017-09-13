// RegularExpressionMatching.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE         1
#define FALSE        0
#define STAR(x)           ((x)=='*')
#define DOT(x)            ((x)=='.')
#define ALPHA(x)          ((x>=65 && x<= 90)||(x>=97 && x<=122))
#define EQUAL_2(x, y)     ((x==y) || (x=='.')|| (y=='.'))
#define EQUAL_3(x, y, z)  ((EQUAL_2(x,y))&&(EQUAL_2(x,z))&&(EQUAL_2(y,z)))

bool isMatch(const char *s, const char *p)
{
	
}

int main()
{
	char *s = "aa";
	char *p = "a";
	int result = isMatch(s, p);

	return 0;
}

