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





void main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: chars inputCards inputStrings outputFile\n");
		return;
	}

	FILE* card = fopen(argv[1], "r");
	FILE* str = fopen(argv[2],"r");
	FILE* out = fopen(argv[3], "w");

	DList neg_card ;
	DList str_list;
	DList pos_card;

	DListInit(neg_card);
	DListInit(str_list);
	DListInit(pos_card);

	card_read(card, neg_card, pos_card);
	str_read(str, str_list);
	replace_process(neg_card, pos_card, str_list);

	write_output(out, pos_card);
}
