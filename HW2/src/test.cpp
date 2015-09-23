#include "dlist.h"

void ttt(DList * list)
{
	DListNode * n1 = (DListNode*)malloc(sizeof(DListNode));
	n1->str = "N1N1N1";
	DListInsertAfter(list, list->tail, n1);
	return;
}