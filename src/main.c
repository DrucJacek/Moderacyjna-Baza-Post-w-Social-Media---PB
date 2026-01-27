#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post_manager.h"
#include "file_io.h"
#include "ui_utils.h"
#include "search_sort.h"

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    BazaPostow baza;
    inicjalizuj_baze(&baza);
    wczytaj_z_pliku(argv[1], &baza);

    int wybor = 0;
    while (wybor != 8) {
        wyswietl_menu();
        if (scanf("%d", &wybor) != 1) { while (getchar() != '\n'); continue; }
        if (wybor == 1) {
            char a[101], t[281]; int k;
            printf("Autor: "); scanf("%100s", a);
            printf("Treść: "); while (getchar() != '\n'); fgets(t, 280, stdin);
            t[strcspn(t, "\n")] = 0;
            printf("Kategoria | Spam(0) Hejt(1) Wulgaryzmy(2) Fejk_news(3) Nieodpowiednie(4): "); scanf("%d", &k);
            dodaj_post(&baza, a, t, (Kategoria)k);
        } else if (wybor == 2) wyswietl_wszystkie_posty(&baza);
        else if (wybor == 3) { char p[100]; printf("Wpisz prefiks autora: "); scanf("%s", p); szukaj_po_autorze_prefiks(&baza, p); }
        else if (wybor == 4) { int i, s; printf("STATUSY: Do_weryfikacji(0) W_trakcie_analizy(1) Zatwierdzone(2) Usunięte(3) \nWpisz id posta do zmiany statusu a nastepnie nowy status: "); scanf("%d %d", &i, &s); zmien_status(&baza, i, (Status)s); }
        else if (wybor == 5) { int k; printf("Wpisz kategorie | Spam(0) Hejt(1) Wulgaryzmy(2) Fejk_news(3) Nieodpowiednie(4): "); scanf("%d", &k); usun_posty_kategorii(&baza, (Kategoria)k); }
        else if (wybor == 6) { int s; printf("Wpisz 1 aby sortować alfabetycznie lub inną liczbę aby sortować po id: "); scanf("%d", &s); if (s == 1) sortuj_po_autorze(&baza); else sortuj_po_id(&baza); }
    }
    zapisz_do_pliku(argv[1], &baza);
    wyczysc_baze(&baza);
    return 0;
}