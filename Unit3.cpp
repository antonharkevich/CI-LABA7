
#include "Unit3.h"







void DealInit(struct DealList* list) {
	list->start = NULL;
	list->end = NULL;
}
void DealAdd(struct DealList* list,struct deal numb) {
	struct DealListItem* temp =(struct DealListItem*)malloc(sizeof(struct DealListItem));
	if(temp==NULL){
		printf("Íåäîñòàòî÷íî ïàìÿòè íà óñòðîéñòâå\n");
		exit(1);
	}
	temp->next = NULL;
	temp->prev = list->end;
	temp->data.selled_auto.price = numb.selled_auto.price;
	temp->data.selled_auto.year = numb.selled_auto.year;
	temp->data.selled_auto.max_speed = numb.selled_auto.max_speed;
	temp->data.selled_auto.engine_capacity = numb.selled_auto.engine_capacity;
	strcpy(temp->data.selled_auto.mark,numb.selled_auto.mark);
	strcpy(temp->data.selled_auto.condition,  numb.selled_auto.condition);
	temp->data.profit = numb.profit;
	temp->data.buyer.my_auto.price = numb.buyer.my_auto.price;
	temp->data.buyer.my_auto.year = numb.buyer.my_auto.year;
	temp->data.buyer.my_auto.max_speed = numb.buyer.my_auto.max_speed;
	temp->data.buyer.my_auto.engine_capacity = numb.buyer.my_auto.engine_capacity;
	strcpy(temp->data.buyer.FIO , numb.buyer.FIO);
	strcpy(temp->data.buyer.phone_number , numb.buyer.phone_number);
	strcpy(temp->data.buyer.my_auto.mark , numb.buyer.my_auto.mark);
	strcpy(temp->data.buyer.my_auto.condition , numb.buyer.my_auto.condition);
	if (!list->start) {
		list->start = temp;
	}
	else {
		list->end->next = temp;
	}
	list->end = temp;
}


void DealClear(struct DealList* list) {
	DealListItem* li = list->start;
	DealListItem* temp;
	while (li)
	{
		temp = li;
		li = li->next;
		free(temp);
	}
	list->start = NULL;
	list->end = NULL;
}
