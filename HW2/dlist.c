/*
 * dlist.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "dlist.h"


void DListInit(DList *list)
{
	list->size = 1;
	//DListNode * start = (DListNode *) malloc(sizeof(DListNode));
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

	if(currNode == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
		newNode->prev = NULL;
		newNode->next = newNode;
		return 0;
	}

	if (list->tail == currNode)
	{
		currNode->next = newNode;
		newNode->prev = currNode;
		newNode->next = NULL;
		list->tail = newNode;
		return 0;
	}

	DListNode *nextNode = currNode->next;
	currNode->next = newNode;
	newNode->prev = currNode;
	newNode->next = nextNode;
	nextNode->prev = newNode;
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
	else return -1;
}

bool DListRemove(DList* list , DListNode* currNode )
{
	DListNode* iterator = list->head;
	if(list->head == currNode)
	{
		list->head = currNode->next;
		if(currNode->next != NULL) currNode->next->prev = NULL;
		free(currNode);
		return 0;
	}

	if(list->tail == currNode)
	{
		list->tail = currNode->prev;
		if(currNode->prev != NULL) currNode->prev->next = NULL;
		free(currNode);
		return 0;
	}


	while(iterator!=list->tail)
	{
		if (iterator == currNode)
		{
			DListNode *prev = iterator->prev;
			DListNode *next = iterator->next;
			free(currNode);
			prev->next = next;
			next->prev = prev;
			return 0;
		}
		iterator = iterator->next;
	}
	return -1;
}
