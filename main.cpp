#include "DLL2.h"

int main() {
    list myPlaylist1, myPlaylist2, myPlaylist3;
    createList(myPlaylist1);
    createList(myPlaylist2);
    createList(myPlaylist3);

    string songInfo;
    address newSong;

    cout << "\nMasukkan judul lagu pertama (Playlist 1): ";
    cin >> songInfo;
    createNewElmt(songInfo, newSong);
    insertLast(myPlaylist1, newSong);

    cout << "\nMasukkan judul lagu kedua (Playlist 1): ";
    cin >> songInfo;
    createNewElmt(songInfo, newSong);
    insertLast(myPlaylist1, newSong);

    cout << "\nDaftar lagu dalam playlist pertama:" << endl;
    address currentSong1 = myPlaylist1.first;
    while (currentSong1 != nullptr) {
        cout << currentSong1->info << endl;
        currentSong1 = currentSong1->next;
    }

    cout << "\nMasukkan judul lagu pertama (Playlist 2): ";
    cin >> songInfo;
    createNewElmt(songInfo, newSong);
    insertLast(myPlaylist2, newSong);

    cout << "\nMasukkan judul lagu kedua (Playlist 2): ";
    cin >> songInfo;
    createNewElmt(songInfo, newSong);
    insertLast(myPlaylist2, newSong);

    cout << "\nDaftar lagu dalam playlist kedua:" << endl;
    address currentSong2 = myPlaylist2.first;
    while (currentSong2 != nullptr) {
        cout << currentSong2->info << endl;
        currentSong2 = currentSong2->next;
    }

    concat(myPlaylist1, myPlaylist2, myPlaylist3);

    cout << "\nDaftar lagu dalam playlist ketiga (setelah penggabungan):" << endl;
    address currentSong3 = myPlaylist3.first;
    while (currentSong3 != nullptr) {
        cout << currentSong3->info << endl;
        currentSong3 = currentSong3->next;
    }

    cout << "\nMasukkan judul lagu yang ingin dihapus dari Playlist 1: ";
    cin >> songInfo;

    address removedSong = findLagu(songInfo, myPlaylist1);
    if (removedSong != nullptr) {
        removeLagu(songInfo, myPlaylist1);
        cout << "Lagu " << songInfo << " dihapus dari Playlist 1." << endl;
    } else {
        cout << "Lagu tidak ditemukan di dalam Playlist 1." << endl;
    }

    cout << "\nDaftar lagu dalam playlist pertama (setelah penghapusan):" << endl;
    currentSong1 = myPlaylist1.first;
    while (currentSong1 != nullptr) {
        cout << currentSong1->info << endl;
        currentSong1 = currentSong1->next;
    }

    cout << "\nMasukkan judul lagu yang ingin dihapus dari Playlist 2: ";
    cin >> songInfo;

    address removedSong2 = findLagu(songInfo, myPlaylist2);
    if (removedSong2 != nullptr) {
        removeLagu(songInfo, myPlaylist2);
        cout << "Lagu " << songInfo << " dihapus dari Playlist 2." << endl;
    } else {
        cout << "Lagu tidak ditemukan di dalam Playlist 2." << endl;
    }

    cout << "\nDaftar lagu dalam playlist kedua (setelah penghapusan):" << endl;
    currentSong2 = myPlaylist2.first;
    while (currentSong2 != nullptr) {
        cout << currentSong2->info << endl;
        currentSong2 = currentSong2->next;
    }

    cout << "\nMasukkan judul lagu yang ingin dihapus dari Playlist 3: ";
    cin >> songInfo;

    address removedSong3 = findLagu(songInfo, myPlaylist3);
    if (removedSong3 != nullptr) {
        removeLagu(songInfo, myPlaylist3);
        cout << "Lagu " << songInfo << " dihapus dari Playlist 3." << endl;
    } else {
        cout << "Lagu tidak ditemukan di dalam Playlist 3." << endl;
    }

    cout << "\nDaftar lagu dalam playlist ketiga (setelah penghapusan):" << endl;
    currentSong3 = myPlaylist3.first;
    while (currentSong3 != nullptr) {
        cout << currentSong3->info << endl;
        currentSong3 = currentSong3->next;
    }

    return 0;
}
