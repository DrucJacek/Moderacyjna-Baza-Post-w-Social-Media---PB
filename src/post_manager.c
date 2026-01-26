#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post_manager.h"

void inicjalizuj_baze(BazaPostow* baza) {
    baza->head = NULL;
    baza->ostatnie_id = 0;
}

void dodaj_post(BazaPostow* baza, const char* autor, const char* tresc, Kategoria kat) {
    Post* nowy = (Post*)malloc(sizeof(Post));
    if (!nowy) return;

    baza->ostatnie_id++;
    nowy->id = baza->ostatnie_id;
    strncpy(nowy->autor, autor, 100);
    nowy->autor[100] = '\0';
    strncpy(nowy->tresc, tresc, 280);
    nowy->tresc[280] = '\0';
    nowy->kategoria = kat;
    nowy->liczba_zgloszen = 1;
    nowy->status = DO_WERYFIKACJI;
    nowy->next = NULL;

    if (!baza->head) {
        baza->head = nowy;
    } else {
        Post* temp = baza->head;
        while (temp->next) temp = temp->next;
        temp->next = nowy;
    }
}

void usun_posty_kategorii(BazaPostow* baza, Kategoria kat) {
    Post *akt = baza->head, *poprz = NULL;
    while (akt) {
        if (akt->kategoria == kat) {
            if (akt->status == DO_WERYFIKACJI) {
                printf("Pominieto ID %d: wymagana weryfikacja.\n", akt->id);
                poprz = akt;
                akt = akt->next;
                continue;
            }
            Post* do_usun = akt;
            if (!poprz) baza->head = akt->next;
            else poprz->next = akt->next;
            akt = akt->next;
            free(do_usun);
        } else {
            poprz = akt;
            akt = akt->next;
        }
    }
}

void usun_pojedynczy_post(BazaPostow* baza, int id) {
    Post *akt = baza->head, *poprz = NULL;
    while (akt) {
        if (akt->id == id) {
            if (akt->status == DO_WERYFIKACJI) {
                printf("Blad: Post ID %d nie moze zostac usuniety bez weryfikacji!\n", id);
                return;
            }
            if (!poprz) baza->head = akt->next;
            else poprz->next = akt->next;
            free(akt);
            printf("Post %d usuniety.\n", id);
            return;
        }
        poprz = akt;
        akt = akt->next;
    }
}

void zmien_status(BazaPostow* baza, int id, Status nowy_status) {
    Post* akt = baza->head;
    while (akt && akt->id != id) akt = akt->next;
    if (akt) akt->status = nowy_status;
}

void wyczysc_baze(BazaPostow* baza) {
    Post* akt = baza->head;
    while (akt) {
        Post* do_usun = akt;
        akt = akt->next;
        free(do_usun);
    }
    baza->head = NULL;
}