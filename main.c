#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fpionter;
	char line[150];
	char word[20];
	int number, line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpionter = openFile(argv[1], "r");
	while (fgets(line, sizeof(line), fpionter))
	{
		if (sscanf(line, "%4s %d", word, &number) == 2)
		{
			if (strcmp(word, "push") == 0)
				push(number);
			else
				run_op(word, line_num);
		}
		else if (sscanf(line, "%4s", word) == 1)
		{
			run_op(word, line_num);
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
void run_op(char op[], int line_num)
{
	if (strcmp(op, "pall") == 0)
		pall();
	else if (strcmp(op, "pint") == 0)
		pint(line_num);
	else if (strcmp(op, "pop") == 0)
		pop(line_num);
	else if (strcmp(op, "swap") == 0)
		swap(line_num);
	else if (strcmp(op, "add") == 0)
		add(line_num);
	else if (strcmp(op, "nop") == 0)
		nop();
	else
	{
		if (strcmp(op, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}
