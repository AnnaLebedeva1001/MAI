#include <stdio.h>
#include <stdlib.h>
void main()
{
	char c;
	int wcc = 0, rule = 0;
	while(rule != 3)
	{
		c = getchar();
		//putchar(c);
		switch(rule)
		{
			case 0:
				if (c == '/') rule = 4;
				else rule = 0;
				if (c == EOF) rule = 3;
			break;
			case 4:
			    if (c == '*') rule = 1;
			    else rule = 0;
			    if (c == EOF) rule = 3;
			break;
			case 5:
				if (c == '/') rule = 0;
				//{
				//if (c - 2 == ' ' && c - 2 == ',' && c - 2 == '\t' && c - 2 == '\n') wcc--;
				//else wcc++;
				//if (c - 2 != ' ' && c - 2 != ',' && c - 2 != '\t' && c - 2 != '\n') wcc++;
				//else wcc--;
				//rule = 0;
				//}
				else rule = 2;
				if (c == EOF) rule = 3;
			break;
			case 1: 
				if (c == ' ' || c == ',' || c == '\t' || c == '\n') rule = 1;
				if (c != ' ' && c != ',' && c != '\t' && c != '\n') rule = 2;
				if (c == '*') rule = 5;
				if (c == EOF) rule = 3;
			break;
			case 2:
				if (c == ' ' || c == ',' || c == '\t' || c == '\n')
				{ 
					wcc++;	
					rule = 1;
				}
				if (c == '*') //rule = 5;
				{
					if (c + 1 == '/')
					{
					if (c == ' ' || c == ',' || c == '\t' || c == '\n') wcc--;
					else wcc++;
					rule = 5;
					}
				}
				if (c != ' ' && c != ',' && c != '\t' && c != '\n' && c != '*') rule = 2;
				if (c == EOF) rule = 3;
			break;
		}
	}
	printf ("Word count in multiline comments: %d\n", wcc);
	//}
} 
