#include <stdio.h>
#include <string.h>
#include "search_sort.h"

void szukaj_po_autorze_prefiks(BazaPostow* baza, const char* prefiks) {
    Post* aktualny = baza->head;
    int znaleziono = 0;
    size_t len = strlen(prefiks);

    printf("\nWyniki wyszukiwania dla prefiksu '%s':\n", prefiks);
    while (aktualny != NULL) {
        if (strncmp(aktualny->autor, prefiks, len) == 0) {
            printf("[%d] Autor: %s | Tresc: %.30s...\n", aktualny->id, aktualny->autor, aktualny->tresc);
            znaleziono = 1;
        }
        aktualny = aktualny->next;
    }
    if (!znaleziono) printf("Brak pasujacych autorow.\n");
}