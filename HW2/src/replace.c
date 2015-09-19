/*
 * replace.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "replace.h"


void copy_replace(DListNode* neg_card, DListNode* str, DListNode* pos_card)
{
	pos_card->blankIndex = neg_card->blankIndex;
	pos_card->blankLength = neg_card->blankLength;
	int count;
	for(count=0;count<1024;count++)
	{
		pos_card->str[count] = neg_card->str[count];
	}
	if(str!=NULL)
	{
		int index = neg_card->blankIndex;
		int length = neg_card->blankLength;
		for(count=0; count<length; count++)
		{
			pos_card->str[index+count] = str->str[count];
		}
	}

}





void replace_process(DList* neg_card, DList* pos_card, DList* str)
{
	DListNode *negcard_index = neg_card->head;

//	DListNode *poscard_index = pos_card->head;
	while(negcard_index != NULL)
	{
		if(str->head == NULL) break;
		if(negcard_index->blankIndex == -1)
		{
			DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
			copy_replace(negcard_index,NULL,newNode);
			DListNode *pos_iterator = pos_card->head;
			if(pos_iterator == pos_card->tail)	DListInsertBefore(pos_card, NULL, newNode);
			else
			{
				if(pos_iterator->blankLength != -1) DListInsertBefore(pos_card, pos_iterator, newNode);
				else pos_iterator = pos_iterator->next;
			}
			DListRemove(neg_card, negcard_index);
		}
		else
		{
			DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
			DListNode *str_iterator = str->head;
			if (str_iterator->blankLength == negcard_index->blankLength)
			{
				copy_replace(negcard_index, str_iterator, newNode);
			}
			else	str_iterator = str_iterator->next;
			if((str_iterator == str->tail) && (str_iterator->blankLength != negcard_index->blankLength))
			{
				DListRemove(neg_card, negcard_index);
				continue;
			}
			DListNode *pos_iterator = pos_card->head;
			if(pos_iterator == pos_card->tail)	DListInsertBefore(pos_card, NULL, newNode);
			else
			{
				if(pos_iterator->blankLength > newNode->blankLength) DListInsertBefore(pos_card, pos_iterator, newNode);
				else pos_iterator = pos_iterator->next;
			}
			DListRemove(neg_card, negcard_index);
			DListRemove(str, str_iterator);
		}
		negcard_index = negcard_index->next;
	}
}
