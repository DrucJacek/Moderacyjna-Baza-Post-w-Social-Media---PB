#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

void zapisz_do_pliku(const char* nazwa_pliku, BazaPostow* baza) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        printf("Blad: Nie mozna otworzyc pliku do zapisu!\n");
        return;
    }

    Post* aktualny = baza->head;
    while (aktualny != NULL) {
        // Zapisujemy polami, oddzielając je np. średnikiem
        fprintf(plik, "%d;%s;%s;%d;%d;%d\n", 
                aktualny->id, aktualny->autor, aktualny->tresc, 
                aktualny->kategoria, aktualny->liczba_zgloszen, aktualny->status);
        aktualny = aktualny->next;
    }

    fclose(plik);
    printf("Baza zostala zapisana do: %s\n", nazwa_pliku);
}

void wczytaj_z_pliku(const char* nazwa_pliku, BazaPostow* baza) {
    FILE* plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        printf("Informacja: Plik %s nie istnieje. Rozpoczynanie z pusta baza.\n", nazwa_pliku);
        return;
    }

    char autor[101], tresc[281];
    int id, kat, zglosz, stat;

    // Format czytania musi odpowiadać formatowi zapisu
    while (fscanf(plik, "%d;%100[^;];%280[^;];%d;%d;%d\n", 
                  &id, autor, tresc, &kat, &zglosz, &stat) == 6) {
        dodaj_post(baza, autor, tresc, (Kategoria)kat);
        // Po dodaniu aktualizujemy id i status na te wczytane z pliku
        Post* temp = baza->head;
        while(temp->next != NULL) temp = temp->next; // idziemy do ostatnio dodanego
        temp->id = id;
        temp->status = (Status)stat;
        temp->liczba_zgloszen = zglosz;
        if (id > baza->ostatnie_id) baza->ostatnie_id = id;
    }

    fclose(plik);
    printf("Wczytano dane z pliku.\n");
}