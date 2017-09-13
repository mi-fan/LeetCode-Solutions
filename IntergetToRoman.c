char r[16];
char* intToRoman(int num){
int a, b, c, d;
	int i = 0;
	a = num / 1000;
	b = (num - a * 1000) / 100;
	c = (num - a * 1000 - b * 100) / 10;
	d = (num - a * 1000 - b * 100 - c * 10) % 10;

	while (a)
	{
		r[i++] = 'M';
		a--;
	}

	if (b <= 3)
	{
		while (b)
		{
			r[i++] = 'C';
			b--;
		}
	}
	else if (b == 4 || b == 9)
	{
		r[i++] = 'C';
		r[i++] = (b == 4) ? 'D' : 'M';
	}
	else
	{
		r[i++] = 'D';
		while (b > 5)
		{
			r[i++] = 'C';
			b--;
		}
	}

	if (c <= 3)
	{
		while (c)
		{
			r[i++] = 'X';
			c--;
		}
	}
	else if (c == 4 || c == 9)
	{
		r[i++] = 'X';
		r[i++] = (c == 4) ? 'L' : 'C';
	}
	else
	{
		r[i++] = 'L';
		while (c > 5)
		{
			r[i++] = 'X';
			c--;
		}
	}

	if (d <= 3)
	{
		while (d)
		{
			r[i++] = 'I';
			d--;
		}
	}
	else if (d == 4 || d == 9)
	{
		r[i++] = 'I';
		r[i++] = (d == 4) ? 'V' : 'X';
	}
	else
	{
		r[i++] = 'V';
		while (d > 5)
		{
			r[i++] = 'I';
			d--;
		}
	}

	r[i++] = '\0';
	return r;
}