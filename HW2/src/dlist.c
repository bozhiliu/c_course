/*
 * dlist.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */

#include "string.h"
#include "dlist.h"
//#define DEBUG

void DNodeDataCpy(DListNode *A, DListNode *B)
{
	A->blankIndex = B->blankIndex;
	A->blankLength = B->blankLength;
	char capture[1024] ;
	int count;
	for(count=0; count<=sizeof(B->str); count++)	capture[count] = B->str[count];
	A->str = capture;
}

void DListInit(DList *list)
{
	list->size = 0;
	//DListNode * start =  malloc(sizeof(DListNode));
	list->head = NULL;
	list->tail = NULL;
}

void DListDestoy(DList *list)
{
	list->size = 0;
	DListNode *head = list->head;
	DListNode *tail = list->tail;
	while (head != tail)
	{
		DListNode *previous = tail->prev;
		free(tail);
		tail = previous;
	}
	list->head = NULL;
	free(tail);
	list->tail = NULL;
}

bool DListInsertAfter (DList *list, DListNode *currNode, DListNode* newNode )
{
	list->size = list->size + 1;
#ifdef DEBUG
	if(currNode != NULL)
		{
			printf("Header points to %s\n", list->head->str);
			printf("Tail points to %s\n", list->tail->str);
		}
#endif
	if(currNode == NULL)
	{
#ifdef DEBUG
		DListShow(list);
		printf("Inserting(after) at start. \n");
		printf("NewNode str %s\n", newNode->str);
#endif
		list->head = newNode;
		list->tail = newNode;
		newNode->prev = newNode;
		newNode->next = newNode;
#ifdef DEBUG
		DListShow(list);
		printf("Header points to %s\n", list->head->str);
		printf("Tail points to %s\n", list->tail->str);
#endif
		return 0;
	}

	if (list->tail == currNode)
	{
#ifdef DEBUG
		DListShow(list);
		printf("Inserting(after) at tail. \n");
		printf("CurrNode str %s\n", currNode->str);
		printf("NewNode str %s\n", newNode->str);
#endif
//		DListNode * newNode = (DListNode *) malloc(sizeof(DListNode));
//		DNodeDataCpy(newNode, inNode);
		currNode->next = newNode;
		newNode->prev = currNode;
		newNode->next = newNode;
		list->tail = newNode;
#ifdef DEBUG
		DListShow(list);
		printf("Header points to %s\n", list->head->str);
		printf("Tail points to %s\n", list->tail->str);
#endif
		return 0;
	}
//	DListNode * newNode = (DListNode *) malloc(sizeof(DListNode));
//	DNodeDataCpy(newNode, inNode);
	DListNode *nextNode = currNode->next;
	currNode->next = newNode;
	newNode->prev = currNode;
	newNode->next = nextNode;
	nextNode->prev = newNode;
#ifdef DEBUG
	printf("Header points to %s", list->head->str);
	printf("Tail points to %s", list->tail->str);
#endif
	return 0;
}

bool DListInsertBefore(DList* list , DListNode* currNode , DListNode* newNode )
{
	list->size = list->size + 1;

	if(currNode == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
		newNode->prev = NULL;
		newNode->next = newNode;

		return 0;
	}

	if(list->head == currNode)
	{
		currNode->prev = newNode;
		newNode->next = currNode;
		newNode->prev = NULL;
		list->head = newNode;
		return 0;
	}
	DListNode *previousNode = currNode->prev;
	currNode->prev = newNode;
	newNode->next = currNode;
	newNode->prev = previousNode;
	previousNode->next = newNode;
	return 0;
}

DListNode* DListSearch(DList* list , char * key)
{
	DListNode* iterator = list->head;
	DListNode* match = NULL;
	while(iterator != list->tail)
	{
		if (iterator->str == key)
		{
			match = iterator;
			break;
		}
		iterator = iterator->next;
	}
	if (iterator != NULL)	return match;
	else return NULL;
}

bool DListRemove(DList* list , DListNode* currNode )
{
	DListNode* iterator = list->head;
	if(list->head == currNode)
	{
		list->head = currNode->next;
		if(currNode->next != NULL) currNode->next->prev = NULL;
		free(currNode->str);
		free(currNode);
		return 0;
	}

	if(list->tail == currNode)
	{
		list->tail = currNode->prev;
		if(currNode->prev != NULL) currNode->prev->next = NULL;
		free(currNode->str);
		free(currNode);
		return 0;
	}


	while(iterator!=list->tail)
	{
		if (iterator == currNode)
		{
			DListNode *prev = iterator->prev;
			DListNode *next = iterator->next;
			free(currNode->str);
			free(currNode);
			prev->next = next;
			next->prev = prev;
			return 0;
		}
		iterator = iterator->next;
	}
	return -1;
}

void DListShow(DList *list)
{
	if(list->head == NULL)
	{
		printf("List Empty!\n");
		return;
	}
	DListNode* iterator = list->head;
	while(iterator != iterator->next)
	{
		printf("1Content:  %s\n", iterator->str);
		iterator = iterator->next;
	}
	printf("2Content:  %s\n", iterator->str);
	printf("List Size %d\n\n",list->size);
}
