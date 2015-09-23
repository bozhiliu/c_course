/*
 * dlist.h
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */

#ifndef DLIST_H_
#define DLIST_H_

#include "bool.h"
#include "stdlib.h"
#include "stdio.h"

/* if the  str  does  not  contain a blank , then
blankIndex  and  blankLength  should  be  -1 */

typedef struct	DListNode_struct {
	char *str;
	int	blankIndex;
	int blankLength;
	struct	DListNode_struct *next;
	struct	DListNode_struct *prev;
	} DListNode;

typedef struct DList_struct {
	int size;
	DListNode *head;
	DListNode *tail;
	} DList;

	/*  creates a new  list  and  initializes  the  head/tail */
void
  DListInit(DList* list);

/*  removes  all  items  from  the list , deallocating  each  item */
void
  DListDestroy(DList* list);

/*  inserts  newNode  after  the  given  currNode  */
bool
  DListInsertAfter(DList* list , DListNode* currNode , DListNode* newNode );

/*  inserts  newNode  before  the  given  currNode  */
bool
  DListInsertBefore(DList* list , DListNode* currNode , DListNode* newNode );

/*  return  the  first  list  node to match  key */
DListNode* DListSearch(DList* list , char * key);

/*  remove  the  list  node (if it is a member  of the  list) */
bool DListRemove(DList* list , DListNode* currNode );

void DListShow(DList* list);


#endif /* DLIST_H_ */
