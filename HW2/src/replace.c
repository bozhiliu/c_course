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
#define DEBUG


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
	 	printf("Current neg card %s\n", negcard_index->str);
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
			  while(pos_iterator->blankLength == -1 && pos_iterator->next!=pos_iterator)
			    {
			      pos_iterator = pos_iterator->next;
			      //	if(pos_iterator->blankLength != -1) DListInsertBefore(pos_card, pos_iterator, newNode);
			      //	else pos_iterator = pos_iterator->next;
			    }
			  DListInsertBefore(pos_card, pos_iterator, newNode);
			}
			negcard_index = negcard_index->next;
			DListRemove(neg_card, negcard_index->prev);
		}
		else
		{
			DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
			DListNode *str_iterator = str->head;
#ifdef DEBUG
		printf("Stamp2 ! \n");
#endif
			while(str_iterator != str_iterator->next)
			{
#ifdef DEBUG
			  printf("Str Iterator %s\n", str_iterator->str);
#endif
				if (str_iterator->blankLength == negcard_index->blankLength)
				{

					copy_replace(negcard_index, str_iterator, newNode);
#ifdef DEBUG
		printf("Stamp3 ! \n");
		printf("New Node Str %s \n", newNode->str);
#endif
					break;
				}
				else	str_iterator = str_iterator->next;
			  
			}
			if((str_iterator->blankLength == negcard_index->blankLength) && (str_iterator == str->tail))
			  {
			    copy_replace(negcard_index, str_iterator, newNode);
#ifdef DEBUG
			    printf("Stamp 3'\n");
			    printf("New Node Str %s \n", newNode->str);
#endif
			  }

			if((str_iterator == str->tail) && (str_iterator->blankLength != negcard_index->blankLength))
			{
				negcard_index = negcard_index->next;
				DListRemove(neg_card, negcard_index->prev);
				break;
			}
#ifdef DEBUG
			printf("Stamp 4 ! \n");
#endif

			DListNode *pos_iterator = pos_card->head;
			if(pos_iterator == NULL)	DListInsertBefore(pos_card, NULL, newNode);
			else
			{

			  while((pos_iterator->blankLength < newNode->blankLength)&&(pos_iterator->next != pos_iterator)) pos_iterator = pos_iterator->next;
//				if(pos_iterator->blankLength > newNode->blankLength)
				DListInsertAfter(pos_card, pos_iterator, newNode);
//				else pos_iterator = pos_iterator->next;
			}
#ifdef DEBUG
			DListShow(pos_card);
			printf("Stamp 5!\n");
#endif


			if(negcard_index ->next == negcard_index)
			  {
			    DListRemove(neg_card, negcard_index);
			    negcard_index = NULL;
			  }
			else
			  {
			    negcard_index = negcard_index->next;
			    DListRemove(neg_card, negcard_index->prev);
			  }
			DListRemove(str, str_iterator);
			str_iterator = str->head;
		}

	}
}
