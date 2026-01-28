#include <stdio.h>
#include "ui_utils.h"

const char* status_string(Status s) {
    switch(s) {
        case DO_WERYFIKACJI: return "Weryfikacja";
        case W_TRAKCIE_ANALIZY: return "Analiza";
        case ZATWIERDZONE: return "Zatwierdzony";
        case USUNIETE: return "Usunięty";
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
    printf("\n|======-MENU-======|");
    printf("\n| 1.Dodaj post     |");
    printf("\n| 2.Wyświetl posty |");
    printf("\n| 3.Szukaj posta   |"); 
    printf("\n| 4.Zmień status   |");
    printf("\n| 5.Usuń (Kateg.)  |");
    printf("\n| 6.Usuń (ID)      |"); 
    printf("\n| 7.Sortuj         |");
    printf("\n| 8.Wyjdź          |");
    printf("\n|==================| \n Wybór: ");
}

void wyswietl_wszystkie_posty(BazaPostow* baza) {
    Post* akt = baza->head;
    printf("\n%-3s | %-12s | %-20s | %-10s | %-3s | %s\n", "ID", "Autor", "Treść", "Kategoria", "Zgłoszenie", "Status");
    while (akt) {
        printf("%-3d | %-12s | %-20.20s | %-10s | %-3d | %s\n", akt->id, akt->autor, akt->tresc, kategoria_string(akt->kategoria), akt->liczba_zgloszen, status_string(akt->status));
        akt = akt->next;
    }
}