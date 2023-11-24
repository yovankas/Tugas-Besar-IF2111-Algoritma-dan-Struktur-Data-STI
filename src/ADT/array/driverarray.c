#include <stdio.h>
#include "array.h"

int main() {
    // Membuat/inisialisasi Array
    Array penyanyiArray = CreateArray();

    // Memasukkan elemen ke Array
    SetEl(&penyanyiArray, 1, "Adele");
    SetEl(&penyanyiArray, 2, "Ed Sheeran");
    SetEl(&penyanyiArray, 3, "Beyonce");

    // Print Array
    printf("Isi Array :\n");
    PrintArrayPenyanyi(penyanyiArray);

    // Mengecek apakah Array kosong
    if (IsEmpty(penyanyiArray)) {
        printf("Array kosong.\n");
    } else {
        printf("Array tidak kosong.\n");
    }

    // Mengecek apakah Array kosong
    if (IsFull(penyanyiArray)) {
        printf("Array penuh.\n");
    } else {
        printf("Array tidak penuh.\n");
    }

    // Mengecek apakah terdapat elemen di Array
    if (IsElmtExist(penyanyiArray, "Ed Sheeran")) {
        printf("Ed Sheeran ada array.\n");
    } else {
        printf("Ed Sheeran tidak ada di array.\n");
    }

    // Menyalin Array
    Array copyArray;
    copyArray(&copyArray, penyanyiArray);

    // Print copyArray
    printf("Array hasil Copy:\n");
    PrintArrayPenyanyi(copyArray);

    return 0;
}
