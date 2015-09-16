#include "bool.h"
#include "dlist.h"
#include "output.h"
#include "replace.h"
#include "str.h"
#include "card.h"


void main()
{
  DList * list;
  DListInit(list);
  DListNode * t1 = (DListNode*) malloc(sizeof(DListNode));
  t1->blankIndex = 1;
  DListNode * t2 = (DListNode*) malloc(sizeof(DListNode));
  t2->blankIndex = 2;
  DListNode * t3 = (DListNode*) malloc(sizeof(DListNode));
  t2->blankIndex = 3;
  DListNode * t4 = (DListNode*) malloc(sizeof(DListNode));
  t2->blankIndex = 4;


  DListInsertAfter(list, list->head, t1);
  


}
