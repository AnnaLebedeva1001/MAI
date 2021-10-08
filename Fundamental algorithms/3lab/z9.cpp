#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define N 30

struct Game
{
	int beach_1[3] = {1, 2, 3}; //1 - wolf, 2 - goat, 3 - cabbage, 0 - пусто
	int beach_2[3] = {0, 0, 0};
	int boat[1] = {0};	 //0 - пусто
	int move_marker = 0; //0 - beach_1, 1 - beach_2
};

int check_boat(int a[])
{
	return a[0];
}

int check_for_zero(int a[])
{
	int i, kol_zero;
	i = 0;
	kol_zero = 0;

	for (i; i < 3; i++)
		if (a[i] == 0)
			kol_zero++;

	if (kol_zero == 3)
		return 1;
	else
		return 0;
}

struct Game take(struct Game game, char *object)
{
	if (check_boat(game.boat))
	{ //сначала проверяем лодку на пустоту
		printf("Cannot take %s, the boat is full\n", object);
		exit(1);
	}
	else
	{
		if (game.move_marker == 0)
		{
			if (strcmp(object, "wolf") == 0)
			{
				if (game.beach_1[0] == 0)
				{ //если нету (на другом берегу)
					printf("The wolf has already been taken\n");
					exit(1);
				}
				else
				{
					game.boat[0] = 1;
					game.beach_1[0] = 0;
				}
			}
			else if (strcmp(object, "goat") == 0)
			{
				if (game.beach_1[1] == 0)
				{ //если нету (на другом берегу)
					printf("The goat has already been taken\n");
					exit(2);
				}
				else
				{
					game.boat[0] = 2;
					game.beach_1[1] = 0;
				}
			}
			else
			{ //cabbage
				if (game.beach_1[2] == 0)
				{ //если нету (на другом берегу)
					printf("The cabbage has already been taken\n");
					exit(3);
				}
				else
				{
					game.boat[0] = 3;
					game.beach_1[2] = 0;
				}
			}
		}
		else
		{
			if (strcmp(object, "wolf") == 0)
			{
				if (game.beach_2[0] == 0)
				{ //если нету (на другом берегу)
					printf("The wolf has already been taken\n");
					exit(1);
				}
				else
				{
					game.boat[0] = 1;
					game.beach_2[0] = 0;
				}
			}
			else if (strcmp(object, "goat") == 0)
			{
				if (game.beach_2[1] == 0)
				{ //если нету (на другом берегу)
					printf("The goat has already been taken\n");
					exit(2);
				}
				else
				{
					game.boat[0] = 2;
					game.beach_2[1] = 0;
				}
			}
			else
			{ //cabbage
				if (game.beach_2[2] == 0)
				{ //если нету (на другом берегу)
					printf("The cabbage has already been taken\n");
					exit(3);
				}
				else
				{
					game.boat[0] = 3;
					game.beach_2[2] = 0;
				}
			}
		}
	}

	return game;
}

struct Game put(struct Game game)
{
	if (check_boat(game.boat))
	{
		if (game.move_marker == 0)
		{
			if (game.boat[0] == 1)
			{
				game.beach_1[0] = 1;
				game.boat[0] = 0;
			}
			else if (game.boat[0] == 2)
			{
				game.beach_1[1] = 2;
				game.boat[0] = 0;
			}
			else
			{ //cabbage
				game.beach_1[2] = 3;
				game.boat[0] = 0;
			}
		}
		else
		{
			if (game.boat[0] == 1)
			{
				game.beach_2[0] = 1;
				game.boat[0] = 0;
			}
			else if (game.boat[0] == 2)
			{
				game.beach_2[1] = 2;
				game.boat[0] = 0;
			}
			else
			{ //cabbage
				game.beach_2[2] = 3;
				game.boat[0] = 0;
			}
		}
	}
	else
	{ //если лодка пуста
		printf("The operation put cannot be performed, the boat is empty\n");
		exit(1);
	}

	if (check_for_zero(game.beach_1) == 1 && game.move_marker == 1)
	{
		printf("You are win!\n");
		return game;
	}
	return game;
}

struct Game move(struct Game game)
{
	if (game.move_marker == 0)
	{
		if (game.beach_1[0] == 1 && game.beach_1[1] == 2 && game.beach_1[2] == 0)
		{ //если волк остался с козой
			printf("Game over, wolf ate goat\n");
			exit(1);
		}
		else if (game.beach_1[0] == 0 && game.beach_1[1] == 2 && game.beach_1[2] == 3)
		{
			printf("Game over, goat ate cabbage\n");
			exit(1);
		}
		game.move_marker = 1;
	}
	else
	{
		if (game.beach_2[0] == 1 && game.beach_2[1] == 2 && game.beach_2[2] == 0)
		{ //если волк остался с козой
			printf("Game over, wolf ate goat\n");
			exit(1);
		}
		else if (game.beach_2[0] == 0 && game.beach_2[1] == 2 && game.beach_2[2] == 3)
		{
			printf("Game over, goat ate cabbage\n");
			exit(1);
		}
		game.move_marker = 0;
	}

	return game;
}

void start(struct Game game, char *str, FILE *fp)
{
	char *action = (char *)malloc(N * sizeof(char));
	int i, j;
	i = 0;
	j = 0;

	while (fgets(str, N, fp))
	{
		while (str[i] != '\0')
		{

			while (isspace(str[i]) != 0) //пропускаем все лишние пробельные символы
				++i;
			if (str[i] == '\0')
				continue;

			while (str[i] != ';')
			{
				if (str[i] != '\0' && isspace(str[i]) == 0 && isspace(str[i + 1]) == 0)
				{
					action[j++] = str[i];
					action[j] = '\0';
				}
				else if (str[i] != '\0' && strcmp(action, "tak") == 0 && str[i] == 'e' && str[i + 1] == ' ')
				{
					j = 0;
					i = i + 2;
					while (isspace(str[i]) == 0 && str[i] != '\0' && str[i] != ';')
					{
						action[j++] = str[i];
						action[j] = '\0';
						++i;
					}
					break;
				}
				else
				{
					printf("Invalid instruction\n");
					exit(1);
				}
				++i;
			}

			j = 0;
			if (strcmp(action, "put") == 0)
				game = put(game);
			else if (strcmp(action, "move") == 0)
				game = move(game);
			else if (strcmp(action, "wolf") == 0 || strcmp(action, "goat") == 0 || strcmp(action, "cabbage") == 0)
				game = take(game, action);
			else
			{
				printf("Unknown operation\n");
				exit(1);
			}
			if (str[i] != '\0')
				++i;
		}
		i = 0;
		j = 0;
	}
}

int main()
{
	FILE *fp_right;
	FILE *fp_wrong;
	struct Game game;
	char *str = (char *)malloc(N * sizeof(char));
	fp_right = fopen("win.txt", "r");
	fp_wrong = fopen("lose.txt", "r");
	assert(fp_right);
	assert(fp_wrong);

	start(game, str, fp_right); //правильная последовательность
	start(game, str, fp_wrong); //неправильная последовательность

	free(str);
	fclose(fp_right);
	fclose(fp_wrong);
	return 0;
}