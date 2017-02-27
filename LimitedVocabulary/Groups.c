#include "Groups.h"
#include <stdlib.h>
#include <stdio.h>

group_a * InitGroup(char groupLine[])
{
	group_a * group = malloc(MAX_AMOUNT_OF_SYNONYMS);
	group->amountOfWords = 0;

	size_t i = 0, size;
	char *token = groupLine;
	for (;; )
	{
		size_t len = strcspn(token, " ");

		if (*(token + len - 1) == '\n')
			*(token + len - 1) = '\0';
		(group->words)[i]=token;
		++group->amountOfWords;

		token += len;
		if (*token == '\0')
		{
			break;
		}
		++token;

		if (++i >= sizeof(group->words) / sizeof(*group->words))
		{
			puts("No more room to allocate");
			break;
		}
	}

	return group;
}

boolean GroupContains(group_a *g,char * word)
{
	for (size_t i = 0; i < g->amountOfWords; i++)
	{
		if (strcmp((g->words)[i], word))
		{
			if ((g->wordsDetected)[i] >= 1)
				return TRUE;
		}
	}
	return FALSE;
}

char * GetSynonym(group_a *g, char * word)
{
	char *wordToReplace = que_pop(g->nextWord);
	if (strcmp(wordToReplace, word) == TRUE)
	{
		que_insert(g->nextWord, wordToReplace);
		wordToReplace = que_pop(g->nextWord);
	}

	return wordToReplace;
}
