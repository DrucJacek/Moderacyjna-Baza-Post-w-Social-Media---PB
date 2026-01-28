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
            printf("Kategoria (0-4): "); scanf("%d", &k);
            dodaj_post(&baza, a, t, (Kategoria)k);
        } 
        else if (wybor == 2) { 
            wyswietl_wszystkie_posty(&baza);
        }
        else if (wybor == 3) { 
            int typ;
            printf("Szukaj po: [1] Autorze, [2] ID: ");
            scanf("%d", &typ);
            if (typ == 1) {
                char p[100]; printf("Podaj prefiks: "); scanf("%s", p);
                szukaj_po_autorze_prefiks(&baza, p);
            } else {
                int id; printf("Podaj ID: "); scanf("%d", &id);
                szukaj_po_id(&baza, id);
            }
        }
        else if (wybor == 4) { 
            int i, s; 
            printf("ID i nowy status (0-3): "); 
            scanf("%d %d", &i, &s); 
            zmien_status(&baza, i, (Status)s); 
        }
        else if (wybor == 5) { 
            int k; 
            printf("Kategoria do usunięcia (0-4): "); 
            scanf("%d", &k); 
            usun_posty_kategorii(&baza, (Kategoria)k); 
        }
        else if (wybor == 6) { 
            int id;
            printf("Podaj ID do usunięcia: ");
            scanf("%d", &id);
            usun_pojedynczy_post(&baza, id);
        }
        else if (wybor == 7) { 
            int s; 
            printf("Sortuj: [1] Autor, [2] ID: "); 
            scanf("%d", &s); 
            if (s == 1) sortuj_po_autorze(&baza); 
            else sortuj_po_id(&baza); 
        }
    }
    zapisz_do_pliku(argv[1], &baza); 
    wyczysc_baze(&baza); 
    return 0;
}