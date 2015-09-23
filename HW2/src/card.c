/*
 * card.c
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */

#include "bool.h"
#include "card.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define DEBUG


void card_read(FILE* card_file,  DList* neg_card)
{
	// index for reading single character
	int curr_index = 0;

	// array for holding the card
	char curr_card[1024];

	// current character
	char card_char;
	char card_underscore;
	char card_newline;
	card_underscore = '_';
	card_newline = '\n';
#ifdef DEBUG
	printf("Card_underscore %c\n", card_underscore);
#endif
	// array used for checking blanks initialized to "111"
	char blank_check[3];
	blank_check[0] = '1'; blank_check[1] = '1'; blank_check[2] = '1';
	// initial blank index and blank length
	int blankIndex = -1;
	int blankLength = 0;

	// blank continuity flag
	bool blankContinuity = false;

	// headers for pos_card and neg_card array
	DListNode* curr_neg = neg_card->tail;

#ifdef DEBUG
	printf("Stamp 1 reached\n");
#endif


	while(!feof(card_file))
	{
		// read single character
		fscanf(card_file, "%c", &card_char);
#ifdef DEBUG
		printf( "T %c %c\n",card_char, card_underscore);
#endif
		// handle underscore
	//	if(strcmp(&card_char, &card_underscore) == 0)
		if( card_char == card_underscore)
		{
			#ifdef DEBUG
				printf("case1 \n");
			#endif

			// check for overflow
			if(curr_index > 1023) continue;
			// increase blank length when assured continuity
			if(blankContinuity == true) blankLength += 1;
			// recursively assigning blank_check array
			//	blank_check[curr_index%3] = "_";
			//strcpy(&blank_check[curr_index%3], '_');
			blank_check[curr_index%3] = '_';
			// check continuity for initial encounter
			if((blank_check[0] == card_underscore) && (blank_check[1]== card_underscore) && (blank_check[2] == card_underscore) && blankIndex == -1 && blankContinuity == false)
			{
				blankIndex = curr_index - 2;
				blankContinuity = true;
				blankLength = 3;
			}

			curr_card[curr_index] = card_char;
			curr_index += 1;
			continue;
		}

		// handle normal characters
		if(card_char != '\n')
		{
			#ifdef DEBUG
				printf("case2 \n");
			#endif

			// check for overflow
			if(curr_index > 1023) continue;

			blankContinuity = false;
			curr_card[curr_index] = card_char;
			curr_index += 1;
			continue;
		}
		#ifdef DEBUG
			printf("case3 \n");
		#endif
		// handle if there is no string in new line
		if((card_char == '\n') && curr_index == 0)
			continue;

		#ifdef DEBUG
			printf("case4 \n");
		#endif


			// handle when this line is ending
		if((card_char == card_newline) && curr_index != 0)
		{

		#ifdef DEBUG
			printf("case5 \n");
		#endif

			// if overflow make the last one to be \0
			if (curr_card >= 1023)
			{
				curr_card[1023] = '\0';
			}
			else
			{
				curr_card[curr_index] = '\n';
				curr_card[curr_index + 1] = '\0';
			}

			// Generate new node
			DListNode* newNode = (DListNode *)malloc(sizeof(DListNode));

			// creating new array that store the string
			char* capture =(char*) malloc(sizeof(char)*(curr_index+1)) ;
			int count;
			for(count=0; count<=curr_index; count++)	capture[count] = curr_card[count];
			newNode->str = capture;

			// put into pos_card or neg_card
			if (blankIndex == -1)
			{
				// To preserve the order of input card, all card input goes to neg_card
				//DListInsertAfter(pos_card,curr_pos, newNode);
				DListShow(neg_card);
				DListInsertAfter(neg_card,neg_card->tail, newNode);
				DListShow(neg_card);
//				curr_neg = newNode;
				newNode->blankIndex = -1;
				newNode->blankLength = -1;
			}
			else
			{
				DListShow(neg_card);
				DListInsertAfter(neg_card, neg_card->tail, newNode);
				DListShow(neg_card);
				//				curr_neg = newNode;
				newNode->blankIndex = blankIndex;
				newNode->blankLength = blankLength;
			}
			// initialize the variables for a new line
			curr_index = 0;
			blank_check[0] = '1'; blank_check[1] = '1'; blank_check[2] = '1';
//			strcpy(&blank_check[0], '1');
//			strcpy(&blank_check[1], '1');
//			strcpy(&blank_check[2], '1');
			blankIndex = -1;
			blankLength = 0;
			blankContinuity = false;
			free(newNode);
			continue;
		}
	}
	// After reach EOF do another round for adding last DListNode

				if(curr_index < 1023)
				{
					curr_card[curr_index] = '\n';
					curr_card[curr_index+1] = '\0';
	//				strcpy(&curr_card[curr_index], '\n');
	//				strcpy(&curr_card[curr_index+1], '\0');
				}
				else
				{
					curr_card[curr_index] = '\0';
	//				strcpy(&curr_card[curr_index], '\0');
				}

				// Generate new node
				DListNode* newNode = (DListNode *)malloc(sizeof(DListNode));

				// creating new array that store the string
				char* capture = (char*)malloc(sizeof(char)*(curr_index + 1));
				int count;
				for (count = 0; count <= curr_index; count++)	capture[count] = curr_card[count];
				newNode->str = capture;

				// put into pos_card or neg_card
				if (blankIndex == -1)
				{
					DListShow(neg_card);
					// To preserve the order of input card, all card input goes to neg_card
					//DListInsertAfter(pos_card,curr_pos, newNode);
					DListInsertAfter(neg_card,neg_card->tail, newNode);
					DListShow(neg_card);
					//					curr_neg = newNode;
					newNode->blankIndex = -1;
					newNode->blankLength = -1;
				}
				else
				{
					DListShow(neg_card);
					DListInsertAfter(neg_card, neg_card->tail, newNode);
					DListShow(neg_card);
					//					curr_neg = newNode;
					newNode->blankIndex = blankIndex;
					newNode->blankLength = blankLength;
				}
				// initialize the variables for a new line
				curr_index = 0;
				blank_check[0] = '1'; blank_check[1] = '1'; blank_check[2] = '1';
	//			strcpy(&blank_check[0], '1');
	//			strcpy(&blank_check[1], '1');
	//			strcpy(&blank_check[2], '1');
				blankIndex = -1;
				blankLength = 0;
				blankContinuity = false;
}
