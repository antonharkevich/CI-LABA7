


#include "Unit2.h"



void ClientInit(struct ClientList* list) {
	list->start = NULL;
	list->end = NULL;
}
void ClientAdd(struct ClientList* list,struct client numb) {
	struct ClientListItem* temp =(struct ClientListItem*)malloc(sizeof(struct ClientListItem));
	if(temp==NULL){
		printf("Íåäîñòàòî÷íî ïàìÿòè íà óñòðîéñòâå\n");
		exit(1);

	}
	temp->next = NULL;
	temp->prev = list->end;

	strcpy(temp->data.FIO,numb.FIO);
	strcpy(temp->data.phone_number,numb.phone_number);
	temp->data.my_auto.price=numb.my_auto.price;
	temp->data.my_auto.engine_capacity=numb.my_auto.engine_capacity;
	temp->data.my_auto.max_speed=numb.my_auto.max_speed;
	temp->data.my_auto.year=numb.my_auto.year;
	strcpy(temp->data.my_auto.mark,numb.my_auto.mark);
	strcpy(temp->data.my_auto.condition,numb.my_auto.condition);
	if (!list->start) {
		list->start = temp;
	}
	else {
		list->end->next = temp;
	}
	list->end = temp;
}




void ClientDelete(struct ClientList* list, struct ClientListItem* li) {
	if (!li)
		return;
	if (li->prev)
		li->prev->next = li->next;
	else {

	//deleting first item
		list->start = li->next;
		if (list->start)
		list->start->prev = NULL;

	}
	if (li->next)
		li->next->prev = li->prev;
	else {
		//deleting last item
		list->end = li->prev;
		if (list->end)
			list->end->next = NULL;

	}
	free(li);
}




void ClientPrint(struct ClientList* list) {
	ClientListItem* li = list->start;
	while (li) {
		printf("×åëîâåê\n");
		printf("ÔÈÎ: %s\n",li->data.FIO);
		printf("Êîíòàêò: %s\n",li->data.phone_number);
		printf("Ìàðêà: %s\n",li->data.my_auto.mark);
		printf("Ãîä âûïóñêà: %d\n",li->data.my_auto.year);
		printf("Öåíà: %d\n",li->data.my_auto.price);
		printf("Ñîñòîÿíèå: %s\n",li->data.my_auto.condition);
		printf("Îáú¸ì äâèãàòåëÿ: %d\n",li->data.my_auto.engine_capacity);
		printf("Ìàêñèìàëüíàÿ ñêîðîñòü: %d\n\n",li->data.my_auto.max_speed);
		li = li->next;

	}
}





ClientListItem* ClientFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if ((!(strcmp(li->data.FIO,numb.FIO)))&&(!(strcmp(li->data.phone_number,numb.phone_number)))&&(!(strcmp(li->data.my_auto.mark,numb.my_auto.mark)))&&li->data.my_auto.price == numb.my_auto.price&&(!(strcmp(li->data.my_auto.condition,numb.my_auto.condition)))&&li->data.my_auto.year == numb.my_auto.year&&li->data.my_auto.max_speed == numb.my_auto.max_speed&&li->data.my_auto.engine_capacity == numb.my_auto.engine_capacity){
		return li;
	   }
	   li = li->next;
	}
	return NULL;
}



ClientListItem* ClientMarkFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (!(strcmp(li->data.my_auto.mark,numb.my_auto.mark)))
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientPriceFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (li->data.my_auto.price == numb.my_auto.price)
		return li;
		li = li->next;
	}
	return NULL;
}



ClientListItem* ClientConditionFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (!(strcmp(li->data.my_auto.condition,numb.my_auto.condition)))
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientYearFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (li->data.my_auto.year == numb.my_auto.year)
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientMaxSpeedFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (li->data.my_auto.max_speed == numb.my_auto.max_speed)
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientEngineCapacityFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (li->data.my_auto.engine_capacity == numb.my_auto.engine_capacity)
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientFIOFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if ((!(strcmp(li->data.FIO,numb.FIO))))
		return li;
		li = li->next;
	}
	return NULL;
}


ClientListItem* ClientPhoneNumberFind(struct ClientListItem* li,struct client numb) {
	while (li) {
	   if (!(strcmp(li->data.phone_number,numb.phone_number)))
		return li;
		li = li->next;
	}
	return NULL;
}




void ClientDeleteItem(struct ClientList* list, struct client numb) {
	ClientListItem* li = ClientFind(list->start, numb);
	ClientDelete(list, li);
}
void ClientClear(struct ClientList* list) {
	ClientListItem* li = list->start;
	ClientListItem* temp;
	while (li)
	{
		temp = li;
		li = li->next;
		free(temp);
	}
	list->start = NULL;
	list->end = NULL;
}
