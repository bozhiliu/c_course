/*
 * output.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "output.h"

void write_output(FILE* output, DList *list)
{
	DListNode *currNode = list->head;
	if(currNode == NULL) return;
	int count = 0;
	for(count = 0;count<1023;count++)	fprintf(output, "%c", currNode->str[count]);
	fprintf(output, "\n");
	return;
}
