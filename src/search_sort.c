#include <stdio.h>
#include <string.h>
#include "search_sort.h"

void swap_nodes(Post* a, Post* b) {
    int t_id = a->id; a->id = b->id; b->id = t_id;
    char t_s[281];
    strcpy(t_s, a->autor); strcpy(a->autor, b->autor); strcpy(b->autor, t_s);
    strcpy(t_s, a->tresc); strcpy(a->tresc, b->tresc); strcpy(b->tresc, t_s);
    Kategoria t_k = a->kategoria; a->kategoria = b->kategoria; b->kategoria = t_k;
    int t_z = a->liczba_zgloszen; a->liczba_zgloszen = b->liczba_zgloszen; b->liczba_zgloszen = t_z;
    Status t_st = a->status; a->status = b->status; b->status = t_st;
}

void sortuj_po_id(BazaPostow* baza) {
    if (!baza->head) return;
    int swapped;
    Post *p1, *lp = NULL;
    do {
        swapped = 0;
        p1 = baza->head;
        while (p1->next != lp) {
            if (p1->id > p1->next->id) { swap_nodes(p1, p1->next); swapped = 1; }
            p1 = p1->next;
        }
        lp = p1;
    } while (swapped);
}

void sortuj_po_autorze(BazaPostow* baza) {
    if (!baza->head) return;
    int swapped;
    Post *p1, *lp = NULL;
    do {
        swapped = 0;
        p1 = baza->head;
        while (p1->next != lp) {
            if (strcmp(p1->autor, p1->next->autor) > 0) { swap_nodes(p1, p1->next); swapped = 1; }
            p1 = p1->next;
        }
        lp = p1;
    } while (swapped);
}

void szukaj_po_autorze_prefiks(BazaPostow* baza, const char* prefiks) {
    Post* akt = baza->head;
    size_t len = strlen(prefiks);
    while (akt) {
        if (strncmp(akt->autor, prefiks, len) == 0) printf("[%d] %s: %s\n", akt->id, akt->autor, akt->tresc);
        akt = akt->next;
    }
}

void szukaj_po_id(BazaPostow* baza, int id) {
    Post* akt = baza->head;
    while (akt) {
        if (akt->id == id) { printf("[%d] %s: %s\n", akt->id, akt->autor, akt->tresc); return; }
        akt = akt->next;
    }
}