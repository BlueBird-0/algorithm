#include<stdio.h>

int main()
{
	char word[50][50] = {0,};

	int line = 0;
	for (int i=0; ; i++)
	{
		char ch;
		scanf("%c", &ch);
	
		if (ch == ' ')
		{
			line++;
			i = -1;
		}
		else if (ch == '.' || ch == '\n')
		{
			word[line][i] = ch;
			break;
		}
		else
		{
			word[line][i] = ch;
		}
	}

	//Ãâ·ÂºÎ
	for (int i = 0; i<=line; i+= 2)
	{
		printf("%s\n", word[i]);
	}
}