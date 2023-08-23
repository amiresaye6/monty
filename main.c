#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fpionter;
	char line[150];
	char word[20];
	int number, line_num = 1;
	size_t i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpionter = openFile(argv[1], "r");
	while (fgets(line, sizeof(line), fpionter))
	{
		char cleanedLine[100];
		int cleanedIndex = 0;

		for (i = 0; i < strlen(line); i++)
		{
			if (!isspace(line[i]))
			{
				cleanedLine[cleanedIndex++] = line[i];
			}
		}
		cleanedLine[cleanedIndex] = '\0';

		if (sscanf(cleanedLine, "%149[^0-9] %d", word, &number) == 2)
		{
			if (strcmp(word, "push") != 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, word);
				exit(EXIT_FAILURE);
			}
			else
			{
				if (!number)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
				else
					push(number);
			}
		}
		else if (sscanf(cleanedLine, "%149s", word) == 1)
		{
			if (strcmp(word, "pall") == 0)
				pall();
			else if (strcmp(word, "pint") == 0)
				pint(line_num);
			else if (strcmp(word, "pop") == 0)
				pop(line_num);
			else if (strcmp(word, "swap") == 0)
				swap(line_num);
			else if (strcmp(word, "add") == 0)
				add(line_num);
			else
			{
				if (strcmp(word, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, word);
				exit(EXIT_FAILURE);
			}
		}
		line_num++;
	}
	fclose(fpionter);
	return (EXIT_SUCCESS);
}

FILE *openFile(const char *filename, const char *mode)
{
	FILE *file = fopen(filename, mode);

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}
