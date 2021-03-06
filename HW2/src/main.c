/*
 * main.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "dlist.h"
#include "stdio.h"
#include "card.h"
#include "output.h"
#include "str.h"
#include "replace.h"





int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Usage: chars inputCards inputStrings outputFile\n");
		return -1;
	}

	FILE* card = fopen(argv[1], "r");
	FILE* str = fopen(argv[2],"r");
	FILE* out = fopen(argv[3], "w");

	DList *neg_card = malloc(sizeof(DList));
	DList* str_list = malloc(sizeof(DList));
	DList* pos_card = malloc(sizeof(DList));

	DListInit(neg_card);
	DListInit(str_list);
	DListInit(pos_card);


//	DListNode* t1 = (DListNode* )malloc(sizeof(DListNode));
//	DListNode* t2 = (DListNode* )malloc(sizeof(DListNode));
//	DListNode* t3 = (DListNode* )malloc(sizeof(DListNode));
//	t1->str = "t1";
//	t2->str = "t2";
//	t3->str = "t3";
//	DListInsertAfter(neg_card, neg_card->tail, t1);
//	DListInsertAfter(neg_card, neg_card->tail, t2);
//	DListInsertAfter(neg_card, neg_card->tail, t3);
//	DListShow(neg_card);

	card_read(card, neg_card);
//	DListShow(neg_card);
//	DListShow(neg_card);
//	DListShow(pos_card);
	str_read(str, str_list);
//	printf("STR_LIST\n");
//	DListShow(str_list);
	replace_process(neg_card, pos_card, str_list);
	DListShow(pos_card);
	write_output(out, pos_card);
//	DListDestroy(neg_card);
//	DListDestroy(pos_card);
//	DListDestroy(str_list);
	return 0;
}
