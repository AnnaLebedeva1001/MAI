#include <stdio.h>
#include <ctype.h>
#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))
unsigned int char_to_set(char c)
{
	c = tolower(c);
	if (c < 'a' || c > 'z')
	{
		return 0;
	}
	return 1u << (c - 'a');
}
int main()
{
	char c;
	int s = 0, rule = 0;
	unsigned int word_1 = 0, word_2 = 0, intersected_set = 0, CONSONANTS = ~VOWELS;
	while (rule != 3)
	{
		c = getchar();
		switch (rule)
		{
		case 0:
			if (c != ' ' && c != ',' && c != '\t' && c != '\n')
			{
				word_1 = word_1 | char_to_set(c);
				rule = 0;
			}
			if (c == ' ' || c == ',' || c == '\t' || c == '\n')
			{
				if (c + 1 == ' ' || c + 1 == ',' || c + 1 == '\t' || c + 1 == '\n')
					rule = 1;
				word_1 = word_1 & CONSONANTS;
				rule = 1;
			}
			if (c == EOF)
				rule = 3;
			break;
		case 1:
			if (c != ' ' && c != ',' && c != '\t' && c != '\n')
			{
				word_2 = word_2 | char_to_set(c);
				rule = 1;
			}
			if (c == ' ' || c == ',' || c == '\t' || c == '\n')
			{
				if (c + 1 == ' ' || c + 1 == ',' || c + 1 == '\t')
					rule = 1;
				else
				{
					word_2 = word_2 & CONSONANTS;
					intersected_set = word_1 | ~word_2;
					if (intersected_set == 4294967295)
					{
						s++;
						word_1 = word_2;
						word_2 = 0;
						rule = 1;
					}
					else
					{
						word_1 = word_2;
						word_2 = 0;
						rule = 1;
					}
				}
			}
			if (c == EOF)
				rule = 3;
			break;
		}
	}
	if (s > 0)
		printf("There are words with the same consonants\n");
	else
		printf("No words with the same consonants\n");
}
