/*
 * str.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */


#include "str.h"

void str_read(FILE * str_file, DList* str_list)
{
	char curr_str[1024];
	int count;
	for(count=0;count<1024;count++)
	{
		curr_str[count] = "\0";
	}
	DListNode * curr_node = str_list->head;


	while(!feof(str_file))
	{
		fscanf(str_file, "%s", curr_str);
		count = 1;
		while(count<1024)
		{
			if(curr_str[count] == "\0" && curr_str[count-1] != "\0")
			{
				break;
			}
			count++;
		}
		DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
		newNode->blankIndex = -1;
		newNode->blankLength = count;
		char capture[1024];
		int tmp;
		for(tmp=0;tmp<1024;tmp++)
		{
			capture[tmp] = curr_str[tmp];
		}
		newNode->str = curr_str;
		DListInsertAfter(str_list, curr_node, newNode);
		for(count=0;count<1024;count++)
		{
			curr_str[count] = "\0";
		}
	}

}
