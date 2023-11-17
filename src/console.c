#include "console.h"

void quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    char confirm;
    scanf("%c", &confirm);
    if (confirm == 'Y')
    {
        printf("manggil save disini\n");
        //save(); // BELUM ADA FUNCTIONNYA

    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
}

void help(boolean startcheck)
{
    if(!startcheck)
    {
        printf("=========================================================[ Menu Help WayangWave ]=========================================================\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
    else 
    {
        printf("=========================================================[ Menu Help WayangWave ]=========================================================\n");
        printf("1. LIST DEFAULT -> Untuk menampilkan list penyanyi, list album dari seorang penyanyi, serta list lagu dari suatu album\n");
        printf("2. LIST PLAYLIST -> Untuk menampilkan playlist yang ada pada pengguna\n");
        printf("3. PLAY SONG -> Untuk memainkan lagu berdasarkan nama penyanyi, nama album, dan ID lagu\n");
        printf("4. PLAY PLAYLIST -> Untuk memainkan lagu berdasarkan ID playlist\n");
        printf("5. QUEUE SONG -> Untuk menambahkan lagu ke dalam queue\n");
        printf("6. QUEUE PLAYLIST -> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf("6. QUEUE SWAP <x> <y> -> Untuk menukar lagu pada urutan ke (x) dan juga urutan ke (y)\n");
        printf("7. QUEUE REMOVE <id> -> Untuk menghapus lagu dari queue dengan inputan urutan (id) lagu yang ingin dihapus dari queue\n");
        printf("8. QUEUE CLEAR -> Untuk mengosongkan queue\n");
        printf("9. SONG NEXT -> Untuk memutar lagu selanjutnya dalam queue jika ada\n");
        printf("10. SONG PREVIOUS -> Untuk memutar lagu yang sebelumnya diputar jika ada\n");
        printf("11. PLAYLIST CREATE -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n");
        printf("12. PLAYLIST ADD -> Untuk menambahkan lagu atau album ke dalam playlist yang sudah dimiliki pengguna dalam daftar playlist\n");
        printf("13. PLAYLIST SWAP <id> <x> <y> -> Untuk menukar lagu pada urutan ke (x) dan juga urutan ke (y) di playlist dengan index (id)\n");
        printf("14. PLAYLIST REMOVE <id> <n> -> Untuk menghapus lagu dengan urutan (n) pada playlist dengan index (id)\n");
        printf("15. PLAYLIST DELETE -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist\n");
        printf("16. STATUS -> Untuk menampilkan lagu yang sedang diputar, dari playlist mana lagu tersebut, serta queue song (jika ada)\n");
        printf("17. SAVE <filename> -> Untuk menyimpan state WayangWave terbaru ke dalam suatu file bernama (filename) dengan tipe txt\n");
        printf("18. QUIT -> Untuk keluar dari aplikasi WayangWave\n");
    }
}

void listDefault(Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum)
{
    printf("Data Penyanyi:\n");
    PrintArrayPenyanyi(arrPenyanyi);

    startInputWord();
    Word command;
    akuisisiCommandWord(&command, currentWord, 1);
    char *com;
    com = wordToString(command);

    if (com == "BLACKPINK")
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (com == "Arctic Monkeys")
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
}