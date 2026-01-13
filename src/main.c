#include <stdio.h>
#include <stdlib.h>
#include "post_manager.h"
#include "file_io.h"
#include "search_sort.h"
#include "ui_utils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR - nie podałeś nazwy pliku bazy danych!\n");
        return 1;
    }

    BazaPostow baza;
    inicjalizuj_baze(&baza);

    printf("System QuickTalk załadowany. Plik: %s\n", argv[1]);

    return 0;
};