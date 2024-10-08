#include <iostream>
#include "DLL.h"

address alokasi(infotype x){

}

void createList(list &L){

}
void insertFirst(list &L, address P){
    if (first(L) == Nil) {
        first(L) = P
        last(L) = P
    } else {
        next(P) = first(L)
        prev(first(L)) = P
        first(L) = P
    }
}

void insertLast(list &L, address P){
    if (first(L) == Nil) {
        first(L) = P
        last(L) = P
    } else {
        prev(P) = last(L)
        next(last(L)) = P
        last(L) = P
    }
}

void insertAfter(list &L, address Prec, address P){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    prev(Prec) = P;
};

void deleteFirst(list &L, address P){
    if (first(L) == NULL and last (L) == NULL) {
        cout << ("List Kosong")
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLast(list &L, address P){
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = Nil;

    return P;
}

void deleteAfter(list &L, address P, address Prec){
    if (first(L) == NULL && last(L) == NULL) {
        cout << ("List Kosong")
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void show(list L){
    if(first(L) == NULL && last(L) == NULL) {
        cout << ("List Kosong");
    } else {
        P = first(L)
        while (P!= NULL) {
            cout << (info(P));
            P = next(P);
        }
    }
}
