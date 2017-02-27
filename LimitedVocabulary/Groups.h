#ifndef _GROUPS_H
#define _GROUPS_H
#include "Queue.h"

#define MAX_AMOUNT_OF_SYNONYMS 32

typedef enum { FALSE = 0, TRUE } boolean;

typedef struct group {
	char *words[MAX_AMOUNT_OF_SYNONYMS];
	queue_a *nextWord;
	int wordsDetected[MAX_AMOUNT_OF_SYNONYMS];
	int amountOfWords;
} group_a;

group_a * InitGroup(char groupLine[]);
boolean GroupContains(group_a *g, char *word);
char *GetSynonym(group_a *g,char *word);


#endif