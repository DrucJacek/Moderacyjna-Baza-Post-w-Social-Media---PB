#include <stdlib.h>
#include "post_manager.h"

void inicjalizuj_baze(BazaPostow* baza) {
    baza->head = NULL;
    baza->ostatnie_id = 0;
}