#include <stdio.h>
#include <stdlib.h>
#include "Groups.h"

int getAmountOfLines(FILE *f)
{
	int ch = 0;
	int lines = 0;
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == '\n')
		{
			lines++;
		}
	}
	return lines;
}

int main()
{
	FILE *input_file = fopen("input.txt", "r");

	char wordList[20][32];

	if (input_file != NULL)
	{
		char line[BUFSIZ];
		while (fgets(line, sizeof line, input_file) != NULL)
		{
			size_t i = 0, size;
			char *token = line;
			//fputs(line, stdout);
			for (;; )
			{
				size_t len = strcspn(token, " ");

				if (*(token + len - 1) == '\n')
					*(token + len - 1) = '\0';
				sprintf(wordList[i], "%.*s", (int)len, token);

				token += len;
				if (*token == '\0')
				{
					sprintf(wordList[i + 1], "%.*s", 1, "\n");
					break;
				}
				++token;

				if (++i >= sizeof wordList / sizeof *wordList)
				{
					puts("No more room to allocate");
					break;
				}
			}
		}
		fclose(input_file);
	}
	else
	{
		perror("input.txt");
	}

	FILE *group_file = fopen("groups.txt", "r");
	if (group_file == NULL)
	{
		printf("plsssss");
	}
	group_a *groups[32];
	int linecount = 0;
	int ch = 0;
	while (!feof(group_file))
	{
		ch = fgetc(group_file);
		if (ch == '\n')
		{
			linecount++;
		}
	}
	fclose(group_file);

	group_file = fopen("groups.txt", "r");
	for (size_t i = 0; i < linecount; i++)
	{
		char group_line[BUFSIZ];
		while (fgets(group_line, sizeof group_line, group_file) != NULL)
		{
			size_t i = 0, size;
			char *token = group_line;
			fputs(group_line, stdout);

			size_t len = strcspn(token, "\0");

			if (*(token + len - 1) == '\n')
				*(token + len - 1) = '\0';

			groups[i] = InitGroup(token);
		}
	}
	printf("%s", (groups[0]->words)[0]);



	return 0;
}