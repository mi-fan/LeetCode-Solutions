//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

bool isValid(char* s) {
    int size = strlen(s);
 	int i, pos;
 	int *arr = (int *)malloc(size*sizeof(int));
  
    pos = 0;
    
 	for (i = 0; i < size; i++)
 	{
        if (pos < 0)
            return 0;
        
 		switch (s[i])
 		{
 			case 40: arr[pos] = 1;
 					 break;
 			case 91: arr[pos] = 2;
 					 break;
 			case 123: arr[pos] = 3;
 					  break;
 			case 41: if (arr[pos - 1] != 1)
 					 	return 0;
					 pos-=2;
 					 break;
 			case 93: if (arr[pos - 1] != 2)
 						return 0;
                     pos-=2;
 					 break;
 			case 125: if (arr[pos - 1] != 3)
 						 return 0;
                      pos-=2;
 					  break;
 		}
 		pos++;
 	}
    if (pos != 0)
        return 0;
 	return 1;
}