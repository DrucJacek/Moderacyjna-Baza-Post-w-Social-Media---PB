#ifndef UI_UTILS_H
#define UI_UTILS_H
#include "post_manager.h"

void wyswietl_menu();
void wyswietl_wszystkie_posty(BazaPostow* baza);
const char* status_string(Status s);
const char* kategoria_string(Kategoria k);

#endif