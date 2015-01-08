#include <stdio.h>

#define MAKSIMUM_TERIM 500

typedef struct
{
	char ad[20];
	int sube;
	int bag;
} oge;

oge Liste[MAKSIMUM_TERIM]=
{
	{NULL,0,0}, //0
	{NULL,0,0},//1
	{NULL,0,0},//2
	{NULL,0,0},//3
	{NULL,0,0},//4
	{"Bil233-01",1,25},//5
	{"Bil233-02",2,0},//6
	{"Bil233-03",3,0},//7
	{"Bil233-04",4,0},//8
	{"Bil233-05",5,0},//9
	{NULL,0,0},//10
	{NULL,0,0},//11
	{NULL,0,0},//12
	{NULL,0,0},//13
	{NULL,0,0},//14
	{"Kubilay",1,28},//15
	{"Fatih",4,24},//16
	{"Cihangir",1,27},//17
	{"Hatice",3,33},//18
	{"Mehmet",2,22},//19
	{"Suna",1,35},//20
	{"Ayhan",1,30},//21
	{"Oguz",1,29},//22
	{"Tugba",3,26},//23
	{"Hakan",4,18},//24
	{"Ahmet",1,21},//25
	{"Umut",3,34},//26
	{"Emre",2,16},//27
	{"Marie",2,19},//28
	{"Osman",5,20},//29
	{"Burak",4,17},//30
	{"Tarik",2,23},//31
	{"Ziya",5,-1},//32
	{"Ihsan",3,15},//33
	{"Yunus",4,32},//34
	{"Talha",2,31},//35
	{"Bil233-01",1,0},//36   1.şube listesindeki en son elemanı gösteren
	{"Bil233-02",2,0},//37   2.şube listesindeki en son elemanı gösteren
	{"Bil233-03",3,0},//38   3.şube listesindeki en son elemanı gösteren
	{"Bil233-04",4,0},//39   4.şube listesindeki en son elemanı gösteren
	{"Bil233-05",5,0},//40   5.şube listesindeki en son elemanı gösteren
};

void SubeDuzenle(int AltSinir, int UstSinir);

int main()
{
	SubeDuzenle(5,9);
	printList(5,9);
	system("pause");
	return 0;
}

void SubeDuzenle(int AltSinir,int UstSinir)
{
	printf("Ogrenci listesinin subelere gore yine alfabetik olarak sirali hali hazirlaniyor.\n");
	int son=35;	//Şubelerdeki son elemanı saklayacağımız kısımın dizide başladığı bölge
	int counter=1;	//sayaç
	int p=AltSinir;
	p=Liste[p].bag;	//güncel eleman
	while(p>=0)
	{
		if(Liste[AltSinir + Liste[p].sube].bag==0)	//p nin bulunduğu şubenin ilk elemanı boşsa
		{
			Liste[AltSinir + Liste[p].sube].bag=p;	//p nin bulunduğu şubenin ilk elemanı p
		}

		if(Liste[son+Liste[p].sube].bag==0)	//p nin bulunduğu şubenin son elemanı boşsa
		{
			Liste[son+Liste[p].sube].bag=p;	//p nin bulunduğu şubenin son elemanı p
		}
		else									//p nin bulunduğu şubenin son elemanı boş değil
		{
			Liste[Liste[son+Liste[p].sube].bag].bag=p;	//p nin bulunduğu şubenin son elemanının bağ alanına p yi koy
			Liste[son+Liste[p].sube].bag=p;				//p nin bulunduğu şubenin son elemanı p
		}

		printf("Islem yapilan %d. eleman: %s\tSube:%d\tIndex:%d\tBag:%d\n",counter,Liste[p].ad,Liste[p].sube,p,Liste[p].bag);	//İşlem yapılan şimdiki elemanın bilgisini göster
		p=Liste[p].bag;
		counter++;
	}
	Liste[Liste[(son)+1].bag].bag=Liste[(AltSinir)+2].bag;	//1.şube son elemanı 2.şube ilk elemanına bağlandı
	Liste[Liste[(son)+2].bag].bag=Liste[(AltSinir)+3].bag;	//2.şube son elemanı 3.şube ilk elemanına bağlandı
	Liste[Liste[(son)+3].bag].bag=Liste[(AltSinir)+4].bag;	//3.şube son elemanı 4.şube ilk elemanına bağlandı
	Liste[Liste[(son)+4].bag].bag=Liste[(AltSinir)+5].bag;	//4.şube son elemanı 5.şube ilk elemanına bağlandı
	Liste[Liste[(son)+5].bag].bag=-1;	//Listenin son elemanının bağ alanı -1
}


void printList(int AltSinir,int UstSinir)
{
	printf("\nListe Yaziliyor:\n");
	int i=1;
	int p=AltSinir;
	p=Liste[p].bag;
	while(p>=0)
	{
		printf("%d. eleman - %s\tSube:%d\tIndex:%d\tBag:%d\n",i,Liste[p].ad,Liste[p].sube,p,Liste[p].bag);
		p=Liste[p].bag;
		i++;
	}
}
