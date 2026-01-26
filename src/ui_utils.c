#include <stdio.h>
#include "ui_utils.h"

const char* status_string(Status s) {
    switch(s) {
        case DO_WERYFIKACJI: return "Weryfikacja";
        case W_TRAKCIE_ANALIZY: return "Analiza";
        case ZATWIERDZONE: return "Zatwierdzony";
        case USUNIETE: return "Usuniety";
        default: return "???";
    }
}

const char* kategoria_string(Kategoria k) {
    switch(k) {
        case SPAM: return "SPAM";
        case HEJT: return "HEJT";
        case WULGARYZMY: return "WULGAR.";
        case FEJK_NEWS: return "FAKE";
        case NIEOPOWIEDNIE: return "NIEODP.";
        default: return "???";
    }
}

void wyswietl_menu() {
    printf("\n1.Dodaj 2.Lista 3.Szukaj 4.Status 5.Masowe 6.Usun 7.Sort 8.Wyjdz\nWybor: ");
}

void wyswietl_wszystkie_posty(BazaPostow* baza) {
    Post* akt = baza->head;
    printf("\n%-3s | %-12s | %-20s | %-10s | %-3s | %s\n", "ID", "Autor", "Tresc", "Kat", "Zgl", "Status");
    while (akt) {
        printf("%-3d | %-12s | %-20.20s | %-10s | %-3d | %s\n", akt->id, akt->autor, akt->tresc, kategoria_string(akt->kategoria), akt->liczba_zgloszen, status_string(akt->status));
        akt = akt->next;
    }
}