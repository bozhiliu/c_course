/*
 * replace.h
 *
 *  Created on: Sep 16, 2015
 *      Author: vito
 */

#ifndef REPLACE_H_
#define REPLACE_H_

#include "dlist.h"

void replace_process(DList* neg_card, DList* pos_card, DList* str);

void copy_replace(DListNode* neg_card, DListNode* str, DListNode* pos_card);




#endif /* REPLACE_H_ */
