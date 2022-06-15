#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h>
struct element
{
	int k;
	struct element* prev;
	struct element* next;
};

void lista_wyswietl(struct element* head);

struct element* lista_dodaj(struct element* head, struct element* nowy);

struct element* lista_szukaj(struct element* head, int zm);

struct element* lista_usun(struct element* head, struct element* x);

struct element* lista_zwolnij(struct element* head);

struct element* lista_odwroc(struct element* head);

main()
{
	struct element* head = NULL, *nowy = NULL, *wynik_ele, *odwr;
	char z;
	int liczba;
	int *wynik=0;
	while (1)
	{
		printf("\nco chcesz zrobic?");
		printf("\nd - dodac");
		printf("\ns - szukac");
		printf("\nu - usunac");
		printf("\no – odwrocic liste");
		printf("\nw - wyswietlic");
		printf("\nq - wyjsc\n");
		fflush(stdin);
		fflush(stdout);
		z = getchar();
		switch (z)
		{
		case 'd': nowy = (struct element*)malloc(sizeof(struct element));
			printf("\npodaj wartosc elementu do wstawienia: ");
			scanf("%d", &liczba);
			nowy->k = liczba;
			head = lista_dodaj(head, nowy);
			break;
		case 'w': lista_wyswietl(head);
			break;
		case 's': printf("\npodaj wartosc szukanego elementu: ");
			scanf("%d", &liczba);
			wynik=lista_szukaj(head, liczba);
			if (wynik != NULL) printf("\nszukana wartosc(%d) jest pod adresem: %d", *wynik, wynik);
			else printf("nie znaleniono podanej wartosci");
			break;
		case 'u': printf("\npodaj wartosc elementu do usuniecia: ");
			scanf("%d", &liczba);
			wynik_ele = lista_szukaj(head, liczba);
			if (wynik_ele != NULL) lista_wyswietl(lista_usun(head, wynik_ele));
			else printf("brak elemetu do usuniecia");
			break;
		case 'o': printf("tablica po odwroceniu - ");
			odwr=lista_odwroc(head);
			lista_wyswietl(odwr);
			break;
		case 'q': lista_zwolnij(head);
			return 0;
		}
	}
}

void lista_wyswietl(struct element* head)
{
	struct element* x = head;
	while (x != NULL)
	{
		printf("%d ", x->k);
		x = x->next;
	}
}

struct element* lista_dodaj(struct element* head, struct element* nowy)
{
	nowy->prev = NULL;
	nowy->next = head;
	if (head != NULL) head->prev = nowy;
	head = nowy;
	return head;
}

struct element* lista_szukaj(struct element* head, int zm)
{
	struct element* x = head;
	while (x != NULL)
	{
		if (x->k == zm)
		{
			return x;
		}
			x = x->next;
	}
	return NULL;
}

struct element* lista_usun(struct element* head, struct element* x)
{
	if (x->prev != NULL) x->prev->next = x->next;
	else head = x->next;
	if (x->next != NULL) x->next->prev = x->prev;
	printf("usunieto podany element\n");
	return head;
	
}


struct element* lista_odwroc(struct element* head)
{
	struct element* head_2 = NULL;
	struct element* x = head;
	struct element* y = NULL;
	while (x != NULL)
	{
		y = (struct element*)malloc(sizeof(struct element));
		y->k = x->k;
		head_2 = lista_dodaj(head_2, y);
		x = x->next;
	}
	return head_2;
}

struct element* lista_zwolnij(struct element* head)
{
	struct element* x = head;
	while (x != NULL)
	{
		void free(void*x);
		x = x->next;
	}
	printf("Zwolniono cala pamiec listy dwukierunkowej\nKONIEC PROGRAMU");
	return head;
}