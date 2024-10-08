#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

address alokasi(infotype x);

void createList(list &L);

void insertFirst(list &L, address P);

void insertLast(list &L, address P);

void insertAfter(list &L, address Prec, address P);

void deleteFirst(list &L);

void deleteLast(list &L);

void deleteAfter(list &L, address Prec);

void show(list L);

#endif // DLL_H_INCLUDED
