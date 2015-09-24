/*
 * output.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */

#include "string.h"
#include "output.h"

void write_output(FILE* output, DList *list)
{
	DListNode *currNode = list->head;
	if(currNode == NULL) return;
	int count = 0;
	while(currNode != currNode->next)
	  {	
	    for(count = 0;count<strlen(currNode->str);count++)	fprintf(output, "%c", currNode->str[count]);
	    fprintf(output, "\n");
	    currNode = currNode->next;
	  }
	for(count = 0;count<strlen(currNode->str);count++)  fprintf(output, "%c", currNode->str[count]);
	fprintf(output, "\n");


return;
}
