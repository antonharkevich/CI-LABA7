#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>


#include "Unit3.h"



int _tmain()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	DealList DEAL;
	ClientList CLIENT;
	AutoList AUTO;
	DealInit(&DEAL);
	ClientInit(&CLIENT);
	AutoInit(&AUTO);
	FILE* onclient  = fopen("D:\\clients.txt", "r");
	FILE* onauto  = fopen("D:\\automobiles.txt", "r");
	while(!(feof(onclient))){
		struct client temp;
		char str[154];
		fscanf(onclient,"%s",temp.FIO);
		fscanf(onclient,"%s",temp.phone_number);
		fscanf(onclient,"%s",temp.my_auto.mark);
		fscanf(onclient,"%d",&(temp.my_auto.year));
		fscanf(onclient,"%d",&(temp.my_auto.price));
		fscanf(onclient,"%s",temp.my_auto.condition);
		fscanf(onclient,"%d",&(temp.my_auto.max_speed));
		fscanf(onclient,"%d",&(temp.my_auto.engine_capacity));
		ClientAdd(&CLIENT,temp);
	}
	while(!(feof(onauto))){
		struct automobile temp;
		char str[154];
		fscanf(onauto,"%s",temp.mark);
		fscanf(onauto,"%d",&(temp.year));
		fscanf(onauto,"%d",&(temp.price));
		fscanf(onauto,"%s",temp.condition);
		fscanf(onauto,"%d",&(temp.max_speed));
		fscanf(onauto,"%d",&(temp.engine_capacity));
		AutoAdd(&AUTO,temp);
	}
	fclose(onclient);
	fclose(onauto);
	int k=0;
	int i=0;
	while(1){
		printf("Äîáðî ïîæàëîâàòü â ïðîãðàììó ðàáîòû ñ àâòîìîáèëÿ è ïîêóïàòåëÿìè\n");
		printf("Äëÿ âõîäà â ðåæèì ðåäàêòèðîâàíèÿ áàçû àâòîìîáèëåé ââåäèòå 1\n");
		printf("Äëÿ âõîäà â ðåæèì ñîâåðøåíèÿ ñäåëêè ââåäèòå 2\n");
		printf("Äëÿ âûõîäà èç ïðîãðàììû ââåäèòå 0\n");
		if(!scanf("%d",&i)){
			printf("Âû ââåëè ÷òî-òî íå òî\n");
			fflush(stdin);
			i=54;
		}
		switch(i){
			case 1:{
				int j=0;
				while(true){
					if(k==54){
						k=0;
						break;
					}
					printf("Äîáðî ïîæàëîâàòü â ðåæèì ðåäàêòèðîâàíèÿ áàçû àâòîìîáèëåé\n");
					printf("Äëÿ ïðîñìîðòà âñåé áàçû àâòîìîáèëåé ââåäèòå 1\n");
					printf("Äëÿ ïîèñêà ïî áàçå ââåäèòå 2\n");
					printf("Äëÿ ðåäàêòèðîâàíèÿ àâòîìîáèëÿ ââåäèòå 3\n");
					printf("Äëÿ ñîðòèðîâêè áàçû ïî ãîäó âûïóñêà ââåäèòå 4\n");
					printf("Äëÿ ñîðòèðîâêè áàçû ïî öåíå ââåäèòå 5\n");
					printf("Äëÿ âûõîäà èç ðåæèìà ââåäèòå 0\n");
					if(!scanf("%d",&j)){
						printf("Âû ââåëè ÷òî-òî íå òî\n");
						fflush(stdin);
						j=54;
					}
					switch(j){
						case 1: AutoPrint(&AUTO); break;
						case 2:{

							int p=0;
							while(true){

								if(k==54){
									k=0;
									break;
								}
                                printf("Äîáðî ïîæàëîâàòü â ðåæèì ïîèñêà ïî áàçå àâòîìîáèëåé\n");
								printf("Äëÿ ïîèñêà êîêðåòíîãî àâòîìîáèëÿ ââåäèòå 1\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé îïðåäåëåííîé ìàðêè ââåäèòå 2\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé îïðåäåëåííîãî ãîäà âûïóñêà ââåäèòå 3\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé îïðåäåëåííîé öåíû ââåäèòå 4\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé îïðåäåëåííîãî ñîñòîíèÿ ââåäèòå 5\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé ñ îïðåäåëåííûì îáú¸ìîì äâèãàòåëÿ ââåäèòå 6\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëåé ñ îïðåäåëåííîé ìàêñèìàëüíîé ñêîðîñòüþ ââåäèòå 7\n");
								printf("Äëÿ âûõîäà èç ðåæèìà ââåäèòå 0\n");
								if(!scanf("%d",&p)){
									printf("Âû ââåëè ÷òî-òî íå òî\n");
									fflush(stdin);
									break;
								}
								switch(p){
									case 1:{
										printf("Ââåäèòå àâòîìîáèëü\n");
										struct automobile temp;
										printf("Ââåäèòå ìàðêó àâòîìîáèëÿ\n");
										scanf("%s",temp.mark);
										printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ\n");;
										if(!scanf("%d",&(temp.year))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå öåíó àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.price))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ\n");
										scanf("%s",temp.condition);
										printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.max_speed))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.engine_capacity))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										AutoListItem* from = AutoFind(AUTO.start, temp);
										if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoFind(from->next, temp);
										}
										break;
									}
									case 2:{
										struct automobile temp;
										printf("Ââåäèòå ìàðêó àâòîìîáèëÿ\n");
										scanf("%s",temp.mark);
										AutoListItem* from = AutoMarkFind(AUTO.start, temp);
										if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoMarkFind(from->next, temp);
										}
										break;
									}
									case 3:{
										struct automobile temp;
										printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.year))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										AutoListItem* from = AutoYearFind(AUTO.start, temp);
										if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoYearFind(from->next, temp);
										}
										break;
									}
									case 4:{
										struct automobile temp;
										printf("Ââåäèòå öåíó àâòîìîáèëÿ\n");
										if(!scanf("%d",&temp.price)){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										AutoListItem* from = AutoPriceFind(AUTO.start, temp);
                                        if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoPriceFind(from->next, temp);
										}
										break;
									}
									case 5:{
										struct automobile temp;
										printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ\n");
										scanf("%s",temp.condition);
										AutoListItem* from = AutoConditionFind(AUTO.start, temp);
                                        if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoConditionFind(from->next, temp);
										}
										break;
									}
									case 6:{
										struct automobile temp;
										printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.engine_capacity))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										AutoListItem* from = AutoEngineCapacityFind(AUTO.start, temp);
                                        if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoEngineCapacityFind(from->next, temp);
										}
										break;
									}
									case 7:{
										struct automobile temp;
										printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ\n");
										if(!scanf("%d",&(temp.max_speed))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										AutoListItem* from = AutoMaxSpeedFind(AUTO.start, temp);
                                        if(from==NULL){
											printf("Àâòîìîáèëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.mark);
											printf("%d\n",from->data.year);
											printf("%d\n",from->data.price);
											printf("%s\n",from->data.condition);
											printf("%d\n",from->data.max_speed);
											printf("%d\n",from->data.engine_capacity);
											printf("\n");
											from = AutoMaxSpeedFind(from->next, temp);
										}
										break;
									}
									case 0: k=54; break;
									default: break;
								}
							}
							break;
						}
						case 3: {
							printf("Ââåäèòå àâòîìîáèëü äëÿ ðåäàêòèðîâàíèÿ");
							struct automobile temp;
							printf("Ââåäèòå ìàðêó àâòîìîáèëÿ\n");
							scanf("%s",temp.mark);
							printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ\n");
							if(!scanf("%d",&(temp.year))){
								printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå öåíó àâòîìîáèëÿ\n");
							if(!scanf("%d",&(temp.price))){
								printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ\n");
							scanf("%s",temp.condition);
							printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ\n");
							if(!scanf("%d",&(temp.max_speed))){
								printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ\n");
							if(!scanf("%d",&(temp.engine_capacity))){
								printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							AutoEdit(AUTO.start,temp);
							break;
						}
						case 4: AutoYearSort_info(&AUTO); break;
						case 5: AutoPriceSort_info(&AUTO); break;
						case 0: k=54; break;
						default: break;
					}
				}
				break;
			}
			case 2:{
				int j=0;
				while(true){
					if(k==54){
						k=0;
						break;
					}
					printf("Äîáðî ïîæàëîâàòü â ðåæèì ñîâåðøåíèÿ ñäåëîê\n");
					printf("Äëÿ ïðîñìîðòà âñåé áàçû ïîêóïàòåëåé ââåäèòå 1\n");
					printf("Äëÿ ïîèñêà ïî áàçå ïîêóïàòåëåé ââåäèòå 2\n");
					printf("Äëÿ ñîâåðøåíèÿ ñäåëêè ââåäèòå 3\n");;
					printf("Äëÿ âûõîäà èç ðåæèìà ââåäèòå 0\n");
					if(!scanf("%d",&j)){
						printf("Âû ââåëè ÷òî-òî íå òî\n");
						j=54;
					}
					switch(j){
						case 1: ClientPrint(&CLIENT); break;
						case 2: {
							int p=0;
							while(true){
								if(k==54){
									k=0;
									break;
								}
								printf("Äîáðî ïîæàëîâàòü â ðåæèì ïîèñêà ïî áàçå ïîêóïàòåëåé\n");
								printf("Äëÿ ïîèñêà êîêðåòíîãî ïîêóïàòåëÿ ââåäèòå 1\n");
								printf("Äëÿ ïîèñêà ïîêóïàòåëÿ ñ îïåäëåííûì ÔÈÎ ââåäèòå 2\n");
								printf("Äëÿ ïîèñêà ïîêóïàòåëÿ ñ îïðåäëåííûì íîìåðîì íîìåðîì òåëåôîíà ââåäèòå 3\n");
								printf("Äëÿ ïîèñêà âñåõ ïîêóïàòëåé íà àâòîìîáèëè îïðåäåëåííîé ìàðêè ââåäèòå 4\n");
								printf("Äëÿ ïîèñêà âñåõ ïîêóïàòåëåé íà àâòîìîáèëè îïðåäåëåííîãî ãîäà âûïóñêà ââåäèòå 5\n");
								printf("Äëÿ ïîèñêà âñåõ ïîêóïàòåëåé íà àâòîìîáèëè îïðåäåëåííîé öåíû ââåäèòå 6\n");
								printf("Äëÿ ïîèñêà âñåõ ïîêóïàòåëåé íà àâòîìîáèëè îïðåäåëåííîãî ñîñòîíèÿ ââåäèòå 7\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëè ñ îïðåäåëåííûì îáú¸ìîì äâèãàòåëÿ ââåäèòå 8\n");
								printf("Äëÿ ïîèñêà âñåõ àâòîìîáèëè ñ îïðåäåëåííîé ìàêñèìàëüíîé ñêîðîñòüþ ââåäèòå 9\n");
								printf("Äëÿ âûõîäà èç ðåæèìà ââåäèòå 0\n");
								scanf("%d",&p);
								switch(p){
									case 1:{
										printf("Ââåäèòå ïîêóïàòåëÿ\n");
										struct client temp;
										printf("Ââåäèòå ÔÈÎ ïîêóïàòåëÿ\n");
										scanf("%s",temp.FIO);
										printf("Ââåäèòå êîíòàêò ïîêóïàòåëÿ\n");
										scanf("%s",temp.phone_number);
										printf("Ââåäèòå ìàðêó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										scanf("%s",temp.my_auto.mark);
										printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.year))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå öåíó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.price))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										scanf("%s",temp.my_auto.condition);
										printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.max_speed))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.engine_capacity))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										ClientListItem* from = ClientFind(CLIENT.start, temp);
										if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientFind(from->next, temp);
										}
										break;
									}
									case 2:{
										struct client temp;
										printf("Ââåäèòå ôàìèëèþ ïîêóïàòåëÿ\n");
										scanf("%s",temp.FIO);
										ClientListItem* from = ClientFIOFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientFIOFind(from->next, temp);
										}
										break;
									}
									case 3:{
										struct client temp;
										printf("Ââåäèòå êîíòàêò ïîêóïàòåëÿ\n");
										scanf("%s",temp.phone_number);
										ClientListItem* from = ClientPhoneNumberFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientPhoneNumberFind(from->next, temp);
										}
										break;
									}
									case 4:{
										struct client temp;
										printf("Ââåäèòå ìàðêó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										scanf("%s",temp.my_auto.mark);
										ClientListItem* from = ClientMarkFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientMarkFind(from->next, temp);
										}
										break;
									}
									case 5:{
										struct client temp;
										printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.year))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										ClientListItem* from = ClientYearFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientYearFind(from->next, temp);
										}
										break;
									}
									case 6:{
										struct client temp;
										printf("Ââåäèòå öåíó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.price))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										ClientListItem* from = ClientPriceFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientPriceFind(from->next, temp);
										}
										break;
									}
									case 7:{
										struct client temp;
										printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										scanf("%s",(temp.my_auto.condition));
										ClientListItem* from = ClientConditionFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientConditionFind(from->next, temp);
										}
										break;
									}
									case 8:{
										struct client temp;
										printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.engine_capacity))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										ClientListItem* from = ClientEngineCapacityFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientEngineCapacityFind(from->next, temp);
										}
										break;
									}
									case 9:{
										struct client temp;
										printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
										if(!scanf("%d",&(temp.my_auto.max_speed))){
											printf("Âû ââåëè ÷òî-òî íå òî\n");
											fflush(stdin);
											break;
										}
										ClientListItem* from = ClientMaxSpeedFind(CLIENT.start, temp);
                                        if(from==NULL){
											printf("Ïîêóïàòåëåé íå íàéäåíî\n");
										}
										while (from) {
											printf("%s\n",from->data.FIO);
											printf("%s\n",from->data.phone_number);
											printf("%s\n",from->data.my_auto.mark);
											printf("%d\n",from->data.my_auto.year);
											printf("%d\n",from->data.my_auto.price);
											printf("%s\n",from->data.my_auto.condition);
											printf("%d\n",from->data.my_auto.max_speed);
											printf("%d\n",from->data.my_auto.engine_capacity);
											printf("\n");
											from = ClientMaxSpeedFind(from->next, temp);
										}
										break;
									}
									case 0: k=54; break;
									default: break;
								}
							}
							break;
						}
						case 3:{
							printf("Ââåäèòå ïîêóïàòåëÿ, ñ êîòîðûì âîçìîæíî áóäåò ñîâåðøåíà ñäåëêà\n");
							struct client temp;
							printf("Ââåäèòå ÔÈÎ ïîêóïàòåëÿ\n");
							scanf("%s",temp.FIO);
							printf("Ââåäèòå êîíòàêò ïîêóïàòåëÿ\n");
							scanf("%s",temp.phone_number);
							printf("Ââåäèòå ìàðêó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							scanf("%s",temp.my_auto.mark);
							printf("Ââåäèòå ãîä âûïóñêà àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							if(!scanf("%d",&(temp.my_auto.year))){
								printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå öåíó àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							if(!scanf("%d",&(temp.my_auto.price))){
                                printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå ñîñòîÿíèå àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							scanf("%s",temp.my_auto.condition);
							printf("Ââåäèòå ìàêñèìàëüíóþ ñêîðîñòü àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							if(!scanf("%d",&(temp.my_auto.max_speed))){
                                printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							printf("Ââåäèòå âìåñòèìîñòü äâèãàòåëÿ àâòîìîáèëÿ, íóæíî äëÿ ïîêóïàòåëÿ\n");
							if(!scanf("%d",&(temp.my_auto.engine_capacity))){
                                printf("Âû ââåëè ÷òî-òî íå òî\n");
								fflush(stdin);
								break;
							}
							ClientListItem* potential_client=ClientFind(CLIENT.start,temp);
							if(potential_client!=NULL){
								printf("Ââåäèòå ïî êàêîìó ïîëþ ïîäáèðàòü íàèáîëåå ïîäõîäÿùèé ïîêóïàòåëþ àâòîìîáèëü\n");
								printf("Äëÿ ïîäáîðà ïî ìàðêå ââåäèòå 1\n");
								printf("Äëÿ ïîäáîðà ïî ãîäó âûïóñêà ââåäèòå 2\n");
								printf("Äëÿ ïîäáîðà ïî öåíå ââåäèòå 3\n");
								printf("Äëÿ ïîäáîðà ïî ñîñòîÿíèþ ââåäèòå 4\n");
								printf("Äëÿ ïîäáîðà ïî îáú¸ìó äâèãàòåëÿ ââåäèòå 5\n");
								printf("Äëÿ ïîäáîðà ïî ìàêñèìàëüíîé ñêîðîñòè ââåäèòå 6\n");
								int ind=0;
								if(!scanf("%d",&ind)){
									printf("Âû ââåëè ÷òî-òî íå òî\n");
									fflush(stdin);
									break;
								}
								switch(ind){
									case 1: {
										struct automobile good_auto;
										strcpy(good_auto.mark,temp.my_auto.mark);
										AutoListItem* from = AutoMarkFind(AUTO.start, good_auto);
										if(from!=NULL){
											printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
											double addedprice=250;
											if(2020-from->data.year<=3){
												addedprice=0.6*from->data.engine_capacity;
											}
											else if(2020-from->data.year>3&&2020-from->data.year<=10){
												if(from->data.engine_capacity<2500){
													addedprice=0.35*from->data.engine_capacity;
												}
												else {
                                                    addedprice=0.6*from->data.engine_capacity;
                                                }
											}
											else if(2020-from->data.year>10&&2020-from->data.year<=14){
												addedprice=0.6*from->data.engine_capacity;
											}
											else {
												addedprice=2*from->data.engine_capacity;
                                            }
											printf("Êîíå÷íàÿ ñòîèìîñòü àâòîìîáèëÿ:%f\n",from->data.price*1.15+addedprice);
											int chance=rand()%2;
											if(chance!=0){
												printf("Ñäåëêà ñîñòîÿëàñü\n");
												struct deal purchase;
												purchase.selled_auto.price = from->data.price;
												purchase.selled_auto.year = from->data.year;
												purchase.selled_auto.max_speed = from->data.max_speed;
												purchase.selled_auto.engine_capacity = from->data.engine_capacity;
												strcpy(purchase.selled_auto.mark,from->data.mark);
												strcpy(purchase.selled_auto.condition,  from->data.condition);

												purchase.buyer.my_auto.price = temp.my_auto.price;
												purchase.buyer.my_auto.year = temp.my_auto.year;
												purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
												purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
												strcpy(purchase.buyer.FIO , temp.FIO);
												strcpy(purchase.buyer.phone_number , temp.phone_number);
												strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
												strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
												purchase.profit=(int)(from->data.price*015);
												DealAdd(&DEAL,purchase);
												AutoDeleteItem(&AUTO,from->data);
												ClientDeleteItem(&CLIENT,temp);
												break;
											}
											else {
												printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
												break;
											}
										}
										else {
											printf("Ïîäõîäÿùèé àâòîìîáèëü íå íàéäåí\n");
											break;
										}
									}
									case 2:{
										struct AutoListItem* t=AUTO.start;
										struct AutoListItem*from=AUTO.start;
										int min=abs(from->data.year-temp.my_auto.year);
										while(t){
											if(abs(t->data.year-temp.my_auto.year)<min){
												min=abs(t->data.year-temp.my_auto.year);
												from=t;
											}
											t=t->next;
										}
										printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
										double addedprice=250;
										if(2020-from->data.year<=3){
											addedprice=0.6*from->data.engine_capacity;
										}
										else if(2020-from->data.year>3&&2020-from->data.year<=10){
											if(from->data.engine_capacity<2500){
												addedprice=0.35*from->data.engine_capacity;
											}
											else {
											   addedprice=0.6*from->data.engine_capacity;
											}
										}
										else if(2020-from->data.year>10&&2020-from->data.year<=14){
											addedprice=0.6*from->data.engine_capacity;
										}
										else {
											addedprice=2*from->data.engine_capacity;
										}

										printf("Êîíå÷íàÿ ñòîèîìòü àâòîìîáèëÿ:%f\n",from->data.price*1.15+addedprice);
										int chance=rand()%2;
										if(chance!=0){
											printf("Ñäåëêà ñîñòîÿëàñü\n");
											struct deal purchase;
											purchase.selled_auto.price = from->data.price;
											purchase.selled_auto.year = from->data.year;
											purchase.selled_auto.max_speed = from->data.max_speed;
											purchase.selled_auto.engine_capacity = from->data.engine_capacity;
											strcpy(purchase.selled_auto.mark,from->data.mark);
											strcpy(purchase.selled_auto.condition,  from->data.condition);

											purchase.buyer.my_auto.price = temp.my_auto.price;
											purchase.buyer.my_auto.year = temp.my_auto.year;
											purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
											purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
											strcpy(purchase.buyer.FIO , temp.FIO);
											strcpy(purchase.buyer.phone_number , temp.phone_number);
											strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
											strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
											purchase.profit=(int)(from->data.price*015);
											DealAdd(&DEAL,purchase);
											AutoDeleteItem(&AUTO,from->data);
											ClientDeleteItem(&CLIENT,temp);
											break;
										}
										else {
											printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
											break;
										}

									}
									case 3:{
										struct AutoListItem* t=AUTO.start;
										struct AutoListItem*from=AUTO.start;
                                        double addedprice=250;
										if(2020-from->data.year<=3){
											addedprice=0.6*from->data.engine_capacity;
										}
										else if(2020-from->data.year>3&&2020-from->data.year<=10){
											if(from->data.engine_capacity<2500){
												addedprice=0.35*from->data.engine_capacity;
											}
											else {
											   addedprice=0.6*from->data.engine_capacity;
											}
										}
										else if(2020-from->data.year>10&&2020-from->data.year<=14){
											addedprice=0.6*from->data.engine_capacity;
										}
										else {
											addedprice=2*from->data.engine_capacity;
										}
										int min=(int)(fabs(0.85*from->data.price+addedprice-temp.my_auto.price));
										while(t){
											double addedpricet=250;
											if(2020-t->data.year<=3){
												addedpricet=0.6*t->data.engine_capacity;
											}
											else if(2020-t->data.year>3&&2020-t->data.year<=10){
												if(t->data.engine_capacity<2500){
													addedpricet=0.35*t->data.engine_capacity;
												}
												else {
													addedpricet=0.6*t->data.engine_capacity;
												}
											}
											else if(2020-t->data.year>10&&2020-t->data.year<=14){
												addedpricet=0.6*t->data.engine_capacity;
											}
											else {
												addedpricet=2*t->data.engine_capacity;
											}
											if((int)(fabs(0.85*t->data.price+addedpricet-temp.my_auto.price))<min){
												min=abs(0.85*t->data.price+addedpricet-temp.my_auto.price);
												from=t;
											}
											t=t->next;
											addedprice=addedpricet;
										}
										printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
										printf("Êîíå÷íàÿ ñòîèîìòü àâòîìîáèëÿ:%d\n",(int)(from->data.price+addedprice));
										int chance=rand()%2;
										if(chance!=0){
											printf("Ñäåëêà ñîñòîÿëàñü\n");
											struct deal purchase;
											purchase.selled_auto.price = from->data.price;
											purchase.selled_auto.year = from->data.year;
											purchase.selled_auto.max_speed = from->data.max_speed;
											purchase.selled_auto.engine_capacity = from->data.engine_capacity;
											strcpy(purchase.selled_auto.mark,from->data.mark);
											strcpy(purchase.selled_auto.condition,  from->data.condition);

											purchase.buyer.my_auto.price = temp.my_auto.price;
											purchase.buyer.my_auto.year = temp.my_auto.year;
											purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
											purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
											strcpy(purchase.buyer.FIO , temp.FIO);
											strcpy(purchase.buyer.phone_number , temp.phone_number);
											strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
											strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
											purchase.profit=(int)(from->data.price*015);
											DealAdd(&DEAL,purchase);
											AutoDeleteItem(&AUTO,from->data);
											ClientDeleteItem(&CLIENT,temp);
											break;
										}
										else {
											printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
											break;
										}
										break;

									}
									case 4:{
										struct automobile good_auto;
										strcpy(good_auto.condition,temp.my_auto.condition);
										AutoListItem* from = AutoConditionFind(AUTO.start, good_auto);
										if(from!=NULL){
											printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
											double addedprice=250;
											if(2020-from->data.year<=3){
												addedprice=0.6*from->data.engine_capacity;
											}
											else if(2020-from->data.year>3&&2020-from->data.year<=10){
												if(from->data.engine_capacity<2500){
													addedprice=0.35*from->data.engine_capacity;
												}
												else {
												   addedprice=0.6*from->data.engine_capacity;
												}
											}
											else if(2020-from->data.year>10&&2020-from->data.year<=14){
												addedprice=0.6*from->data.engine_capacity;
											}
											else {
												addedprice=2*from->data.engine_capacity;
											}
											printf("Êîíå÷íàÿ ñòîèîìòü àâòîìîáèëÿ:%f\n",from->data.price*1.15+addedprice);
											int chance=rand()%2;
											if(chance!=0){
												printf("Ñäåëêà ñîñòîÿëàñü\n");
												struct deal purchase;
												purchase.selled_auto.price = from->data.price;
												purchase.selled_auto.year = from->data.year;
												purchase.selled_auto.max_speed = from->data.max_speed;
												purchase.selled_auto.engine_capacity = from->data.engine_capacity;
												strcpy(purchase.selled_auto.mark,from->data.mark);
												strcpy(purchase.selled_auto.condition,  from->data.condition);

												purchase.buyer.my_auto.price = temp.my_auto.price;
												purchase.buyer.my_auto.year = temp.my_auto.year;
												purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
												purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
												strcpy(purchase.buyer.FIO , temp.FIO);
												strcpy(purchase.buyer.phone_number , temp.phone_number);
												strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
												strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
												purchase.profit=(int)(from->data.price*015);
												DealAdd(&DEAL,purchase);
												AutoDeleteItem(&AUTO,from->data);
												ClientDeleteItem(&CLIENT,temp);
												break;
											}
											else {
												printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
												break;
											}
										}
										else {
											printf("Ïîäõîäÿùèé àâòîìîáèëü íå íàéäåí\n");
											break;
										}
										break;
									}
									case 5:{
										struct AutoListItem* t=AUTO.start;
										struct AutoListItem*from=AUTO.start;
										int min=abs(from->data.engine_capacity-temp.my_auto.engine_capacity);
										while(t){
											if(abs(t->data.engine_capacity-temp.my_auto.engine_capacity)<min){
												min=abs(t->data.engine_capacity-temp.my_auto.engine_capacity);
												from=t;
											}
											t=t->next;
										}
										printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
                                        double addedprice=250;
										if(2020-from->data.year<=3){
											addedprice=0.6*from->data.engine_capacity;
										}
										else if(2020-from->data.year>3&&2020-from->data.year<=10){
											if(from->data.engine_capacity<2500){
												addedprice=0.35*from->data.engine_capacity;
											}
											else {
											   addedprice=0.6*from->data.engine_capacity;
											}
										}
										else if(2020-from->data.year>10&&2020-from->data.year<=14){
											addedprice=0.6*from->data.engine_capacity;
										}
										else {
											addedprice=2*from->data.engine_capacity;
										}
										printf("Êîíå÷íàÿ ñòîèîìòü àâòîìîáèëÿ:%f\n",from->data.price*1.15+addedprice);
										int chance=rand()%2;
										if(chance!=0){
											printf("Ñäåëêà ñîñòîÿëàñü\n");
											struct deal purchase;
											purchase.selled_auto.price = from->data.price;
											purchase.selled_auto.year = from->data.year;
											purchase.selled_auto.max_speed = from->data.max_speed;
											purchase.selled_auto.engine_capacity = from->data.engine_capacity;
											strcpy(purchase.selled_auto.mark,from->data.mark);
											strcpy(purchase.selled_auto.condition,  from->data.condition);

											purchase.buyer.my_auto.price = temp.my_auto.price;
											purchase.buyer.my_auto.year = temp.my_auto.year;
											purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
											purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
											strcpy(purchase.buyer.FIO , temp.FIO);
											strcpy(purchase.buyer.phone_number , temp.phone_number);
											strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
											strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
											purchase.profit=(int)(from->data.price*015);
											DealAdd(&DEAL,purchase);
											AutoDeleteItem(&AUTO,from->data);
											ClientDeleteItem(&CLIENT,temp);
											break;
										}
										else {
											printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
											break;
										}
										break;
									}
									case 6:{
										struct AutoListItem* t=AUTO.start;
										struct AutoListItem*from=AUTO.start;
										int min=abs(from->data.max_speed-temp.my_auto.max_speed);
										while(t){
											if(abs(t->data.max_speed-temp.my_auto.max_speed)<min){
												min=abs(t->data.max_speed-temp.my_auto.max_speed);
												from=t;
											}
											t=t->next;
										}
										printf("Íàéäåí ïîäõîäÿùèé àâòîìîáèëü!\n");
                                        double addedprice=250;
										if(2020-from->data.year<=3){
											addedprice=0.6*from->data.engine_capacity;
										}
										else if(2020-from->data.year>3&&2020-from->data.year<=10){
											if(from->data.engine_capacity<2500){
												addedprice=0.35*from->data.engine_capacity;
											}
											else {
											   addedprice=0.6*from->data.engine_capacity;
											}
										}
										else if(2020-from->data.year>10&&2020-from->data.year<=14){
											addedprice=0.6*from->data.engine_capacity;
										}
										else {
											addedprice=2*from->data.engine_capacity;
										}
										printf("Êîíå÷íàÿ ñòîèîìòü àâòîìîáèëÿ:%f\n",from->data.price*1.15+addedprice);
										int chance=rand()%2;
										if(chance!=0){
											printf("Ñäåëêà ñîñòîÿëàñü\n");
											struct deal purchase;
											purchase.selled_auto.price = from->data.price;
											purchase.selled_auto.year = from->data.year;
											purchase.selled_auto.max_speed = from->data.max_speed;
											purchase.selled_auto.engine_capacity = from->data.engine_capacity;
											strcpy(purchase.selled_auto.mark,from->data.mark);
											strcpy(purchase.selled_auto.condition,  from->data.condition);

											purchase.buyer.my_auto.price = temp.my_auto.price;
											purchase.buyer.my_auto.year = temp.my_auto.year;
											purchase.buyer.my_auto.max_speed = temp.my_auto.max_speed;
											purchase.buyer.my_auto.engine_capacity = temp.my_auto.engine_capacity;
											strcpy(purchase.buyer.FIO , temp.FIO);
											strcpy(purchase.buyer.phone_number , temp.phone_number);
											strcpy(purchase.buyer.my_auto.mark , temp.my_auto.mark);
											strcpy(purchase.buyer.my_auto.condition , temp.my_auto.condition);
											purchase.profit=(int)(from->data.price*015);
											DealAdd(&DEAL,purchase);
											AutoDeleteItem(&AUTO,from->data);
											ClientDeleteItem(&CLIENT,temp);
                                            break;
										}
										else {
											printf("Ê ñîæàëåíèþ, ñäåëêà ñ ïîêóïàòåëåì íå ñîñòîÿëàñü\n");
											break;
										}
										break;

									}
									default: break;
								}
							}
							else {
								printf("Òàêîãî ïîêóïàòåëÿ íåò\n");
								break;
                            }
							break;
						}
						case 0: k=54; break;
						default: break;
					}
				}
				break;
			}
			case 0:{
				FILE* inclient  = fopen("D:\\clients.txt", "w");
				FILE* inauto  = fopen("D:\\automobiles.txt", "w");
				FILE* indeal = fopen("D:\\deals.txt", "a");
				DealListItem* dealli=DEAL.start;
				while(dealli){
					fprintf(indeal,"%s\n",dealli->data.selled_auto.mark);
					fprintf(indeal,"%d\n",dealli->data.selled_auto.year);
					fprintf(indeal,"%d\n",dealli->data.selled_auto.price);
					fprintf(indeal,"%s\n",dealli->data.selled_auto.condition);
					fprintf(indeal,"%d\n",dealli->data.selled_auto.max_speed);
					fprintf(indeal,"%d\n",dealli->data.selled_auto.engine_capacity);
					fprintf(indeal,"\n");
					fprintf(indeal,"%s\n",dealli->data.buyer.FIO);
					fprintf(indeal,"%s\n",dealli->data.buyer.phone_number);
					fprintf(indeal,"%s\n",dealli->data.buyer.my_auto.mark);
					fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.year);
					fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.price);
					fprintf(indeal,"%s\n",dealli->data.buyer.my_auto.condition);
					fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.max_speed);
					fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.engine_capacity);
					fprintf(indeal,"\n");
					fprintf(indeal,"Ïðèáûëü: %d\n",dealli->data.profit);
					fprintf(indeal,"\n");
					dealli=dealli->next;
				}
				ClientListItem* clientli=CLIENT.start;
				while(clientli){
					fprintf(inclient,"%s\n",clientli->data.FIO);
					fprintf(inclient,"%s\n",clientli->data.phone_number);
					fprintf(inclient,"%s\n",clientli->data.my_auto.mark);
					fprintf(inclient,"%d\n",clientli->data.my_auto.year);
					fprintf(inclient,"%d\n",clientli->data.my_auto.price);
					fprintf(inclient,"%s\n",clientli->data.my_auto.condition);
					fprintf(inclient,"%d\n",clientli->data.my_auto.max_speed);
					fprintf(inclient,"%d",clientli->data.my_auto.engine_capacity);
					if(clientli->next!=NULL){
						fprintf(inclient,"\n\n");
					}
					clientli=clientli->next;
				}
				AutoListItem* autoli=AUTO.start;
				while(autoli){
					fprintf(inauto,"%s\n",autoli->data.mark);
					fprintf(inauto,"%d\n",autoli->data.year);
					fprintf(inauto,"%d\n",autoli->data.price);
					fprintf(inauto,"%s\n",autoli->data.condition);
					fprintf(inauto,"%d\n",autoli->data.max_speed);
					fprintf(inauto,"%d",autoli->data.engine_capacity);
					if(autoli->next!=NULL){
						fprintf(inauto,"\n\n");
					}
					autoli=autoli->next;
				}
				DealClear(&DEAL);
				ClientClear(&CLIENT);
				AutoClear(&AUTO);
				return 0;
			}
			default: break;
		}
	}
	return 0;
}
