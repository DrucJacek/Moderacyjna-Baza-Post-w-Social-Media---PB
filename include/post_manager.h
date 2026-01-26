#ifndef POST_MANAGER_H
#define POST_MANAGER_H

typedef enum { SPAM, HEJT, WULGARYZMY, FEJK_NEWS, NIEOPOWIEDNIE } Kategoria;
typedef enum { DO_WERYFIKACJI, W_TRAKCIE_ANALIZY, ZATWIERDZONE, USUNIETE } Status;

typedef struct Post {
    int id;
    char autor[101];
    char tresc[281];
    Kategoria kategoria;
    int liczba_zgloszen;
    Status status;
    struct Post* next;
} Post;

typedef struct {
    Post* head;
    int ostatnie_id;
} BazaPostow;

void inicjalizuj_baze(BazaPostow* baza);
void dodaj_post(BazaPostow* baza, const char* autor, const char* tresc, Kategoria kat);
void wyczysc_baze(BazaPostow* baza);
void usun_posty_kategorii(BazaPostow* baza, Kategoria kat);
void usun_pojedynczy_post(BazaPostow* baza, int id);
void zmien_status(BazaPostow* baza, int id, Status nowy_status);

#endif