/*
 * replace.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "replace.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
//#define DEBUG


void copy_replace(DListNode* neg_card, DListNode* str, DListNode* pos_card)
{
	pos_card->blankIndex = neg_card->blankIndex;
	pos_card->blankLength = neg_card->blankLength;
	int count;
//	printf("test: %d \n",  sizeof("aaa ___ bbb"));
//	printf("neg card size: %d \n",  sizeof(neg_card->str));
//	printf("Neg CARD %s", neg_card->str);
	char* str_pass = (char*) malloc(strlen(neg_card->str));


	for(count=0;count<strlen(neg_card->str);count++)
	{
		str_pass[count] = neg_card->str[count];
		//strcpy(&pos_card->str[count], &neg_card->str[count]);
	}
//	printf("STR_PASS %s\n", str_pass);
	pos_card->str = str_pass;


	if(str!=NULL)
	{
		int index = neg_card->blankIndex;
		int length = neg_card->blankLength;
//		printf("%s", neg_card->str);
//		printf("Blank Length %d\n", neg_card->blankLength);
//		printf("%s\n", pos_card->str);
		for(count=0; count<length; count++)
		{
			pos_card->str[index+count] = str->str[count];
//			strcpy(&pos_card->str[count], &neg_card->str[count]);
		}
//		printf("%s", pos_card->str);
	}

}





void replace_process(DList* neg_card, DList* pos_card, DList* str)
{
	DListNode *negcard_index = neg_card->head;

//	DListNode *poscard_index = pos_card->head;
	while(negcard_index != NULL)
	{
		if(str->head == NULL) break;
	#ifdef DEBUG
			printf("Stamp0 ! \n");
	#endif
		if(negcard_index->blankIndex == -1)
		{
	#ifdef DEBUG
			printf("Stamp1 ! \n");
	#endif
			DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
			copy_replace(negcard_index,NULL,newNode);

			DListNode *pos_iterator = pos_card->head;
			if(pos_iterator == pos_card->tail)	DListInsertBefore(pos_card, NULL, newNode);
			else
			{
				if(pos_iterator->blankLength != -1) DListInsertBefore(pos_card, pos_iterator, newNode);
				else pos_iterator = pos_iterator->next;
			}
			negcard_index = negcard_index->next;
			DListRemove(neg_card, negcard_index);
		}
		else
		{
			DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
			DListNode *str_iterator = str->head;
#ifdef DEBUG
		printf("Stamp2 ! \n");
#endif
			while(str_iterator != str->tail)
			{

				if (str_iterator->blankLength == negcard_index->blankLength)
				{

					copy_replace(negcard_index, str_iterator, newNode);
#ifdef DEBUG
		printf("Stamp3 ! \n");
#endif
					break;
				}
				else	str_iterator = str_iterator->next;

			}

			if((str_iterator == str->tail) && (str_iterator->blankLength != negcard_index->blankLength))
			{
				negcard_index = negcard_index->next;
				DListRemove(neg_card, negcard_index);
				break;
			}



			DListNode *pos_iterator = pos_card->head;
			if(pos_iterator == NULL)	DListInsertBefore(pos_card, NULL, newNode);
			else
			{

				while(pos_iterator->blankLength < newNode->blankLength) pos_iterator = pos_iterator->next;
//				if(pos_iterator->blankLength > newNode->blankLength)
				DListInsertBefore(pos_card, pos_iterator, newNode);
//				else pos_iterator = pos_iterator->next;
			}
			negcard_index = negcard_index->next;
			DListRemove(neg_card, negcard_index);
			DListRemove(str, str_iterator);
		}

	}
}
