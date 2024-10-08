#ifndef DLL2_H_INCLUDED
#define DLL2_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef string infotype;

struct elmlist {
    infotype info;
    elmlist* prev;
    elmlist* next;
};

typedef elmlist* address;

struct list {
    address first;
    address last;
};

bool isEmpty(list L);
void createList(list& L);
bool createNewElmt(infotype X, address& P);
void insertFirst(list& L, address P);
void insertAfter(list& L, address Prec, address P);
void insertLast(list& L, address P);
void deleteFirst(list& L, address& P);
void deleteAfter(list& L, address Prec, address& P);
void deleteLast(list& L, address& P);
void concat(list L1, list L2, list& L3);
address findLagu(string Judul, list L);
void removeLagu(string Judul, list& L);

#endif // DLL2_H
