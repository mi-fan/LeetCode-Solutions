#include <stdio.h>
#include <string.h>
 
int romantoInt(char* s)
{
	int num = 0;
	int i = 0;
	int size = strlen(s);

	while (s[i] == 'M' && i < size)
	{
		num += 1000;
		i++;
	}


	if (s[i] == 'D' && i < size)
	{
		num += 500;
	}

	while (s[i] == 'C' && i < size)
	{
		if (s[i+1] == 'D')
		{
			num += 400;
			i += 2; 
			break;
		}
		else if (s[i+1] == 'M')
		{
			num += 900;
			i += 2; 
			break;
		}
		num += 100;
		i++;
	}

	if (s[i] == 'L' && i < size)
	{
		num += 50;
	}


	while (s[i] == 'X' && i < size)
	{
		if (s[i+1] == 'L')
		{
			num += 40;
			i += 2; 
			break;
		}
		else if (s[i+1] == 'C')
		{
			num += 90;
			i += 2; 
			break;
		}
		num += 10;
		i++;
	} 

	if (s[i] == 'V' && i < size)
	{
		num += 5;
	}

	while (s[i] == 'I' && i < size)
	{
		if (s[i+1] == 'V')
		{
			num += 4;
			i += 2; 
			break;
		}
		else if (s[i+1] == 'X')
		{
			num += 9;
			i += 2; 
			break;
		}
		num += 1;
		i++;
	}

	return num;
}
