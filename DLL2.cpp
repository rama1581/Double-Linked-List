#include "DLL2.h"

bool isEmpty(list L) {
    return (L.first == nullptr);
}

void createList(list& L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool createNewElmt(infotype X, address& P) {
    P = new elmlist;
    if (P != nullptr) {
        P->info = X;
        P->prev = nullptr;
        P->next = nullptr;
        return true;
    }
    return false;
}

void insertFirst(list& L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(list& L, address Prec, address P) {
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next != nullptr) {
        Prec->next->prev = P;
    } else {
        L.last = P;
    }
    Prec->next = P;
}

void insertLast(list& L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirst(list& L, address& P) {
    P = L.first;
    if (P->next == nullptr) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        P->next->prev = nullptr;
    }
}

void deleteAfter(list& L, address Prec, address& P) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        L.last = Prec;
    }
}

void deleteLast(list& L, address& P) {
    P = L.last;
    if (P->prev == nullptr) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        P->prev->next = nullptr;
    }
}

void concat(list L1, list L2, list& L3) {
    createList(L3);

    address P = L1.first;
    while (P != nullptr) {
        address Q;
        createNewElmt(P->info, Q);
        insertLast(L3, Q);
        P = P->next;
    }

    P = L2.first;
    while (P != nullptr) {
        address Q;
        createNewElmt(P->info, Q);
        insertLast(L3, Q);
        P = P->next;
    }
}

address findLagu(string Judul, list L) {
    address P = L.first;
    while (P != nullptr) {
        // Mengecek judul lagu
        // Jika ditemukan, mengembalikan alamat elemen
        if (P->info == Judul) {
            return P;
        }
        P = P->next;
    }
    return nullptr; // Lagu tidak ditemukan
}

void removeLagu(string Judul, list& L) {
    address P = findLagu(Judul, L);

    if (P != nullptr) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        delete P;
    }
}
