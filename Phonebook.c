#include <stdio.h>
#include <stdlib.h>

typedef struct TelefonRehberi {
	int numara;
	char ad[10];
	char soyad [10];
	struct rehber *sonraki;
}rehber;
rehber *ilk=NULL, *gecici, *son=NULL;


int main() {
 
    while (1) {
        system("cls");
        menu();
    }
    return 0;
}


void menu() {
	int secim, sayi, sira, kontrol;
	printf("---TELEFON REHBERI---\n");
	printf(" 1-Ekleme\n 2-Arama \n 3-Guncelleme \n 4-Silme\n 5-Listeleme  ");
	printf("\n Seciminiz:");
	scanf("%d",&secim);
  
    switch (secim) {
        case 1:
            system("cls");
            Ekleme();
            printf("\nKisi Eklendi...");
            getch();
            break;
        case 2:
            system("cls");
            Arama();
            getch();
            break;
        case 3:
            system("cls");
            Guncelleme();
            getch();
            break;
	
        case 4:
            system("cls");
       		Silme();
        case 5:
             system("cls");
    		Listele();
        
        default:
            system("cls");
            printf("Hatali Secim\n");
    }
}

void Ekleme() {  
	rehber *ptr, *onceki;
	gecici=(rehber *)malloc(sizeof(rehber));
	printf("--------------------------\n   KISI EKLEME \n--------------------------\n");
	printf("Kisi Adi:");
	scanf("%s", gecici->ad);
	printf("Kisi Soyadi:");
	scanf("%s", gecici->soyad);
	printf("Kisi Numara:");
	scanf("%d", &gecici->numara);
	
	gecici->sonraki=NULL;
	if(ilk==NULL)    
		ilk=gecici; 
	else {
 		onceki=ptr=ilk;
		if(ptr==onceki) {
			gecici->sonraki=ilk;
			ilk=gecici;
		}
		else if(ptr==NULL)
			onceki->sonraki=gecici;
		else {
			gecici->sonraki=ptr;
			onceki->sonraki=gecici;
		}
	}	
}

void Arama() {
	rehber *ptr;
	char aranacak[20];
	int aranumara;
	int sec;
	printf("--------------------------\n   KISI ARAMA \n--------------------------\n");
	printf("Arama Kriterinizi Seciniz:\n");
	printf("\t1-Isme Gore Arama\n\t2-Numaraya Gore Arama\n");
	printf("Seciminiz:");
	scanf("%d",&sec);
	if(ilk==NULL) {
		printf("\n\tRehber Bos ! \n Devam etmek icin bir tusa basiniz...");
		getch();
		return;
	}
	switch (sec) {
        case 1:
		    system("cls");
		    printf("Aranacak Kisinin Adini Giriniz : ");
			scanf("%s",aranacak);
		 	ptr=ilk;
			while(strcmp(ptr->ad,aranacak)!=0){
			 	ptr= ptr->sonraki;
			if (ptr == NULL) break;
			}
			if(ptr!=NULL) {
				printf("---Kisi Bulundu!---\n Kisi Bilgileri:\n");
				printf("\tAdi : %s\n",ptr->ad);
				printf("\tSoyadi : %s\n",ptr->soyad);
				printf("\tTelefon Numarasi : %d\n",ptr->numara);
			}
			else {
				printf("Kisi Bulunamadi....\n");
			}
            break;
        case 2:
            system("cls");
		    printf("Aramak Istediginiz Numarayi Giriniz : ");
			scanf("%d",&aranumara);
		 	ptr=ilk;
			while(ptr->numara!=aranumara){
			 	ptr= ptr->sonraki;
			if (ptr == NULL) break;
			}
			if(ptr!=NULL) {
				printf("---Kisi Bulundu!---\n Kisi Bilgileri:\n");
				printf("\tAdi : %s\n",ptr->ad);
				printf("\tSoyadi : %s\n",ptr->soyad);
				printf("\tTelefon Numarasi : %d\n",ptr->numara);
			}
			else {
				printf("Kisi Bulunamadi....\n");
			}
            break;
        default:
            system("cls");
            printf("Hatali Secim\n");
    }
}

void Guncelleme() {
	rehber *ptr;
	int aranacak;
	printf("--------------------------\n   KISI GUNCELLEME \n--------------------------\n");
	if(ilk==NULL) {  
		printf("\n\t\tRehber Bos !...\n");
		getch();
		return;
	}
	printf("Guncellenecek Numarayi Giriniz: ");
	scanf("%d",&aranacak);
 	ptr=ilk;
	while(ptr->numara!=aranacak){
	 	ptr= ptr->sonraki;
		if (ptr == NULL) break;
	}
	if(ptr!=NULL) { 
		printf("Yeni Ad : ", ptr->ad);
		scanf("%s", ptr->ad);
		printf("Yeni Soyad : ", ptr->soyad);
		scanf("%s", ptr->soyad);
		printf("Yeni Telefon Numarasi : ", ptr->numara);
		scanf("%d", &ptr->numara);
	}
	else {
		printf("Kisi Bulunamadi...\n");
	}
}


void Silme() {
	rehber *ptr,*onceki,*gecici;
	char aranacak[20],secim='h';
	printf("--------------------------\n   KISI SILME \n--------------------------\n");
	if(ilk==NULL) {
		printf("\n\t\tRehber Bos !...\n");
		getch();
		return;
	}
	printf("Silinecek Kisinin Soyadini Giriniz : ");
	scanf("%s",aranacak);
	onceki=ptr=ilk;
	while(strcmp(ptr->soyad,aranacak)!=0){
	 	onceki=ptr;
	 	ptr= ptr->sonraki;
	if (ptr == NULL) 
		break;
	}
	if(ptr!=NULL){
		printf("Kisi Bulundu !\nKISI BILGILERI");
		printf("\n-------------------------------------------------------");
		printf("\nAd : %s\n",ptr->ad);
		printf("Soyad : %s\n",ptr->soyad);
		printf("Telefon Numarasi : %d\n",ptr->numara);
		printf("---------------------------------------------------------");
		printf("\nKisi Silinsin mi?...Onayla [e/h]: ");
		secim=getch();
		if(secim=='e') {
			if (ptr==ilk) {
				gecici=ilk->sonraki;
				free(ilk);
				ilk=gecici;
			}
			else {
				gecici=ptr->sonraki;
				free(ptr);
				onceki->sonraki=gecici;
			}
			printf("\n\n1 Kisi Silindi...");
		}
		else
			printf("\n\nKisi Silinemedi...");
	}
	else {
		printf("\nKisi Bulunamadi !...");
	}
 getch();
}

void Listele() {
	rehber *ptr;
	if(ilk==NULL) {
		printf("\n\tRehber Bos !...\n");
		getch();
		return;
	}
	for(ptr=ilk; ptr!=NULL; ptr=ptr->sonraki) {
		printf("\n\t-----Kisi Bilgileri--------\n");
		printf("\tKisi Ismi: %s", ptr->ad);
		printf("\n\tKisi Soyadi:%s", ptr->soyad);
		printf("\n\tTelefon Numarasi: %d", ptr->numara);
 	}
 	getch();
}


