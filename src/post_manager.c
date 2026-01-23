#include <stdio.h>
#include <stdlib.h>
#include "post_manager.h"
#include <string.h>

void inicjalizuj_baze(BazaPostow* baza) {
    baza->head = NULL;
    baza->ostatnie_id = 0;
}

void dodaj_post(BazaPostow* baza, const char* autor, const char* tresc, Kategoria kat) {
    Post* nowy = (Post*)malloc(sizeof(Post));
    if (nowy == NULL) {
        printf("Blad alokacji pamieci!\n");
        return;
    }

    baza->ostatnie_id++;
    nowy->id = baza->ostatnie_id;
    strncpy(nowy->autor, autor, 100);
    strncpy(nowy->tresc, tresc, 280);
    nowy->kategoria = kat;
    nowy->liczba_zgloszen = 0;
    nowy->status = DO_WERYFIKACJI;
    nowy->next = NULL;

    if (baza->head == NULL) {
        baza->head = nowy;
    } else {
        Post* temp = baza->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void usun_posty_kategorii(BazaPostow* baza, Kategoria kat) {
    Post *aktualny = baza->head, *poprzedni = NULL;
    int licznik = 0;

    while (aktualny != NULL) {
        if (aktualny->kategoria == kat) {
            if (aktualny->status == DO_WERYFIKACJI) {
                printf("Pominieto ID %d: Post niezweryfikowany.\n", aktualny->id);
                poprzedni = aktualny;
                aktualny = aktualny->next;
                continue;
            }

            
    }
    printf("Usunieto %d postow z wybranej kategorii.\n", licznik);
}