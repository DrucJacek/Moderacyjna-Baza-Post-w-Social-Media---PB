#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

void zapisz_do_pliku(const char* nazwa_pliku, BazaPostow* baza) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (!plik) return;
    Post* akt = baza->head;
    while (akt) {
        fprintf(plik, "%d;%s;%s;%d;%d;%d\n", akt->id, akt->autor, akt->tresc, akt->kategoria, akt->liczba_zgloszen, akt->status);
        akt = akt->next;
    }
    fclose(plik);
}

void wczytaj_z_pliku(const char* nazwa_pliku, BazaPostow* baza) {
    FILE* plik = fopen(nazwa_pliku, "r");
    if (!plik) return;
    char autor[101], tresc[281];
    int id, kat, zgl, st;
    while (fscanf(plik, "%d;%100[^;];%280[^;];%d;%d;%d\n", &id, autor, tresc, &kat, &zgl, &st) == 6) {
        dodaj_post(baza, autor, tresc, (Kategoria)kat);
        Post* temp = baza->head;
        while (temp->next) temp = temp->next;
        temp->id = id;
        temp->status = (Status)st;
        temp->liczba_zgloszen = zgl;
        if (id > baza->ostatnie_id) baza->ostatnie_id = id;
    }
    fclose(plik);
}