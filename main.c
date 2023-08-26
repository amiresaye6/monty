#include "monty.h"

/**
 * main - all the stuff happens here
 * @argc: number of arguments after the ./main
 * @argv: list of these arguments
 *
 * Return: 0 if succedded or EXIT_FAILURE if any thing wrong happens
*/
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
		if (sscanf(line, "%s %d", word, &number) == 2)
		{
			if (word[0] == '#')
		{
			line_num++;
			continue;
		}
			if (strcmp(word, "push") == 0)
				push(number);
			else
				run_op(word, line_num);
		}
		else if (sscanf(line, "%s", word) == 1)
		{
			if (word[0] == '#')
			{
				line_num++;
				continue;
			}
			run_op(word, line_num);
		}
		line_num++;
	}
	fclose(fpionter);
	free_stack();
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

/**
 * run_op - functions checks and runs each operator
 * @line_num: the number of the line currently running
 * @op: string contains the operator
 * Return: void
*/
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
	else if (strcmp(op, "sub") == 0)
		sub(line_num);
	else if (strcmp(op, "div") == 0)
		div_e(line_num);
	else if (strcmp(op, "mul") == 0)
		mul(line_num);
	else if (strcmp(op, "mod") == 0)
		mod(line_num);
	else if (strcmp(op, "pstr") == 0)
		pstr();
	else if (strcmp(op, "pchar") == 0)
		pchar(line_num);
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
