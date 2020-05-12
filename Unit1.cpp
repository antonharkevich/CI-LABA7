//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



#include "Unit1.h"








void AutoInit(struct AutoList* list) {
	list->start = NULL;
	list->end = NULL;
}
void AutoAdd(struct AutoList* list,struct automobile numb) {
	struct AutoListItem* temp =(struct AutoListItem*)malloc(sizeof(struct AutoListItem));
	if(temp==NULL){
		printf("������������ ������ �� ����������\n");
		exit(1);
	}
	temp->next = NULL;
	temp->prev = list->end;
	temp->data.price=numb.price;
	temp->data.engine_capacity=numb.engine_capacity;
	temp->data.max_speed=numb.max_speed;
	temp->data.year=numb.year;
	strcpy(temp->data.mark,numb.mark);
	strcpy(temp->data.condition,numb.condition);
	if (!list->start) {
		list->start = temp;
	}
	else {
		list->end->next = temp;
	}
	list->end = temp;
}




void AutoDelete(struct AutoList* list, struct AutoListItem* li) {
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




void AutoPrint(struct AutoList* list) {
	AutoListItem* li = list->start;
	while (li) {
		printf("����������\n");
		printf("�����: %s\n",li->data.mark);
		printf("��� �������: %d\n",li->data.year);
		printf("����: %d\n",li->data.price);
		printf("���������: %s\n",li->data.condition);
		printf("����� ���������: %d\n",li->data.engine_capacity);
		printf("������������ ��������: %d\n\n",li->data.max_speed);
		li = li->next;

	}
}


void AutoEdit(struct AutoListItem *li, struct automobile numb){
	while (li) {
	   if ((!(strcmp(li->data.mark,numb.mark)))&&li->data.price == numb.price&&(!(strcmp(li->data.condition, numb.condition)))&&li->data.year == numb.year&&li->data.max_speed == numb.max_speed&&li->data.engine_capacity == numb.engine_capacity){
		   int n=0;
		   printf("��� �������������� ����� ���������� ������� 1\n");
		   printf("��� �������������� ���� ������� ���������� ������� 2\n");
		   printf("��� �������������� ���� ���������� ������� 3\n");
		   printf("��� �������������� ��������� ���������� ������� 4\n");
		   printf("��� �������������� ������ ��������� ���������� ������� 5\n");
		   printf("��� �������������� ������������ �������� ���������� ������� 6\n");
		   printf("\n");
		   if(!scanf("%d",&n)){
			   printf("�� ����� ���-�� �� ��\n");
			   fflush(stdin);
			   return;
		   }
		   switch(n){
			   case 1:
				  printf("������� �����\n");
				  scanf("%s",li->data.mark);
				  return;
			   case 2:
				  printf("������� ��� �������\n");
				  scanf("%d",&(li->data.year));
				  return;
			   case 3:
				  printf("������� ����\n");
				  scanf("%d",&(li->data.price));
				  return;
			   case 4:
				  printf("������� ���������\n");
				  scanf("%s",li->data.condition);
				  return;
			   case 5:
				  printf("������� ����� ���������\n");
				  scanf("%d",&(li->data.engine_capacity));
				  return;
			   case 6:
				  printf("������� ������������ ��������\n");
				  scanf("%d",&(li->data.max_speed));
				  return;
			   default: return;
		   }
	   }
	   li = li->next;
	}
	printf("������ ���������� ���\n");
}


AutoListItem* AutoFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if ((!(strcmp(li->data.mark,numb.mark)))&&li->data.price == numb.price&&(!(strcmp(li->data.condition, numb.condition)))&&li->data.year == numb.year&&li->data.max_speed == numb.max_speed&&li->data.engine_capacity == numb.engine_capacity){
		return li;
	   }
	   li = li->next;
	}
	return NULL;
}



AutoListItem* AutoMarkFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (!(strcmp(li->data.mark,numb.mark))){
			return li;
	   }
		li = li->next;
	}
	return NULL;
}


AutoListItem* AutoPriceFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (li->data.price == numb.price)
		return li;
		li = li->next;
	}
	return NULL;
}



AutoListItem* AutoConditionFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (!(strcmp(li->data.condition,numb.condition)))
		return li;
		li = li->next;
	}
	return NULL;
}


AutoListItem* AutoYearFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (li->data.year == numb.year)
		return li;
		li = li->next;
	}
	return NULL;
}


AutoListItem* AutoMaxSpeedFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (li->data.max_speed == numb.max_speed)
		return li;
		li = li->next;
	}
	return NULL;
}


AutoListItem* AutoEngineCapacityFind(struct AutoListItem* li,struct automobile numb) {
	while (li) {
	   if (li->data.engine_capacity == numb.engine_capacity)
		return li;
		li = li->next;
	}
	return NULL;
}






void AutoDeleteItem(struct AutoList* list, struct automobile numb) {
	AutoListItem* li = AutoFind(list->start, numb);
	AutoDelete(list, li);
}
void AutoClear(struct AutoList* list) {
	AutoListItem* li = list->start;
	AutoListItem* temp;
	while (li)
	{
		temp = li;
		li = li->next;
		free(temp);
	}
	list->start = NULL;
	list->end = NULL;
}

int AutoLength(struct AutoList *list){
	AutoListItem* li = list->start;
	int average=0;
	while(li){
		average++;
		li=li->next;
	}
	return average;
}


void AutoYearSort_info(AutoList *list) {
	AutoListItem *t = NULL;
	AutoListItem *t1;
	struct automobile r;
	do {
			for (t1=list->start; t1 -> next != t; t1 = t1-> next)
				if (t1-> data.year > t1-> next -> data.year)  {
								r.price=t1->data.price;
								r.engine_capacity=t1->data.engine_capacity;
								r.max_speed=t1->data.max_speed;
								r.year=t1->data.year;
								strcpy(r.mark,t1->data.mark);
								strcpy(r.condition,t1->data.condition);
								t1->data.price=t1->next->data.price;
								t1->data.engine_capacity=t1->next->data.engine_capacity;
								t1->data.max_speed=t1->next->data.max_speed;
								t1->data.year=t1->next->data.year;
								strcpy(t1->data.mark,t1->next->data.mark);
								strcpy(t1->data.condition,t1->next->data.condition);
								t1->next->data.price=r.price;
								t1->next->data.engine_capacity=r.engine_capacity;
								t1->next->data.max_speed=r.max_speed;
								t1->next->data.year=r.year;
								strcpy(t1->next->data.mark,r.mark);
								strcpy(t1->next->data.condition,r.condition);
				}
			t = t1;
	} while (list-> start -> next != t);
}

void AutoPriceSort_info(AutoList *list) {
	AutoListItem *t = NULL;
	AutoListItem *t1;
	struct automobile r;
	do {
			for (t1=list->start; t1 -> next != t; t1 = t1-> next)
				if (t1-> data.price > t1-> next -> data.price)  {
					r.price=t1->data.price;
					r.engine_capacity=t1->data.engine_capacity;
					r.max_speed=t1->data.max_speed;
					r.year=t1->data.year;
					strcpy(r.mark,t1->data.mark);
					strcpy(r.condition,t1->data.condition);
					t1->data.price=t1->next->data.price;
					t1->data.engine_capacity=t1->next->data.engine_capacity;
					t1->data.max_speed=t1->next->data.max_speed;
					t1->data.year=t1->next->data.year;
					strcpy(t1->data.mark,t1->next->data.mark);
					strcpy(t1->data.condition,t1->next->data.condition);
					t1->next->data.price=r.price;
					t1->next->data.engine_capacity=r.engine_capacity;
					t1->next->data.max_speed=r.max_speed;
					t1->next->data.year=r.year;
					strcpy(t1->next->data.mark,r.mark);
					strcpy(t1->next->data.condition,r.condition);
				}
			t = t1;
	} while (list-> start -> next != t);
}
