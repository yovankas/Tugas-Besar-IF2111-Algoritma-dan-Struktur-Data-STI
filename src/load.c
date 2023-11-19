#include "load.h"

void load(char* namafile,Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu)
{
    STARTWORD(concat("data/", namafile));

    if (!EOP)
    {
        int countPenyanyi = wordToInt(ambilKataKe(currentWord, 1));

        // Bikin list buat semua penyanyi
        //printf("Count Penyanyi: %d\n", countPenyanyi);
        for (int i = 0; i < countPenyanyi; i++)
        {
            ADVWORD();
            //printf("Indeks: %d\n", i);
            int countAlbum = wordToInt(ambilKataKe(currentWord, 1));
            char *namaPenyanyi = wordToString(ambilMulaiKataKe(currentWord, 2));
            SetEl(arrPenyanyi, i, namaPenyanyi);

            //printf("Penyanyi: %s\n", namaPenyanyi);

            // Bikin map buat semua album dalam satu penyanyi
            for (int j = 0; j < countAlbum; j++)
            {
                ADVWORD();
                int countLagu = wordToInt(ambilKataKe(currentWord, 1));
                char *namaAlbum = wordToString(ambilMulaiKataKe(currentWord, 2));
                SetEl(arrAlbum, j, namaAlbum);

                //printf("Album: %s\n", namaAlbum);
                // Bikin set buat semua lagu dalam satu album
                //printf("Jumlah Lagu: ");
                //printf("%d\n", countLagu);
                CreateEmptySet(lagu);
                for (int k = 0; k < countLagu; k++)
                {
                    ADVWORD();
                    char *namaLagu = wordToString(currentWord);
                    //printf("Lagu: %s\n", namaLagu);
                    InsertSet(lagu, namaLagu);
                }
                InsertInAlbum(laguAlbum, namaAlbum, *lagu);
            }
            InsertInPenyanyi(albumPenyanyi, namaPenyanyi, *arrAlbum);
        }
        ADVWORD();
    }
}