//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#endif



#include "Unit2.h"



struct deal{
	automobile selled_auto;
	client buyer;
	int profit;
};


struct DealListItem {
	struct DealListItem *prev;
	struct DealListItem *next;
	struct deal data;
};




struct DealList {
	struct DealListItem *start;
	struct DealListItem *end;
};



void DealInit(struct DealList* list);
void DealAdd(struct DealList* list,struct deal numb);
void DealClear(struct DealList* list);
