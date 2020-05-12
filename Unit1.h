


#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <cstring>


struct automobile{
	char mark[154];
	int year;
	int engine_capacity;
	int max_speed;
	char condition[154];
	int price;
};




struct AutoListItem {
	struct AutoListItem *prev;
	struct AutoListItem *next;
	automobile data;
};


struct AutoList {
	struct AutoListItem *start;
	struct AutoListItem *end;
};




void AutoInit(struct AutoList* list);
void AutoAdd(struct AutoList* list,struct automobile numb);
void AutoDelete(struct AutoList* list, struct AutoListItem* li) ;
void AutoPrint(struct AutoList* list);
void AutoEdit(struct AutoListItem *li, struct automobile numb);
AutoListItem* AutoFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoMarkFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoPriceFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoConditionFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoYearFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoMaxSpeedFind(struct AutoListItem* li,struct automobile numb);
AutoListItem* AutoEngineCapacityFind(struct AutoListItem* li,struct automobile numb);
void AutoDeleteItem(struct AutoList* list, struct automobile numb);
void AutoClear(struct AutoList* list);
int AutoLength(struct AutoList *list);
void AutoYearSort_info(AutoList *list);
void AutoPriceSort_info(AutoList *list);
