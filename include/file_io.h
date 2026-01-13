#ifndef FILE_IO_H
#define FILE_IO_H

#include "post_manager.h"

void zapisz_do_pliku(const char* nazwa_pliku, BazaPostow* baza);
void wczytaj_z_pliku(const char* nazwa_pliku, BazaPostow* baza);

#endif