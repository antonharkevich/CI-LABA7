


#include "Unit1.h"



struct client{
	char FIO[154];
	char phone_number[154];
	struct automobile my_auto;
};



struct ClientListItem {
	struct ClientListItem *prev;
	struct ClientListItem *next;
	client data;
};


struct ClientList {
	struct ClientListItem *start;
	struct ClientListItem *end;
};


void ClientInit(struct ClientList* list);
void ClientAdd(struct ClientList* list,struct client numb);
void ClientDelete(struct ClientList* list, struct ClientListItem* li);
void ClientPrint(struct ClientList* list);
ClientListItem* ClientFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientMarkFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientPriceFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientConditionFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientYearFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientMaxSpeedFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientEngineCapacityFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientFIOFind(struct ClientListItem* li,struct client numb);
ClientListItem* ClientPhoneNumberFind(struct ClientListItem* li,struct client numb);
void ClientDeleteItem(struct ClientList* list, struct client numb) ;
void ClientClear(struct ClientList* list);
