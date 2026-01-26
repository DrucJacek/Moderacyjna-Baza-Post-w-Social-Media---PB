#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H
#include "post_manager.h"

void sortuj_po_id(BazaPostow* baza);
void sortuj_po_autorze(BazaPostow* baza);
void szukaj_po_autorze_prefiks(BazaPostow* baza, const char* prefiks);
void szukaj_po_id(BazaPostow* baza, int id);

#endif