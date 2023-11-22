#include "./save.h"

void save(char *namafile, Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu, currentSong *currentSong, Queue *Q, Stackchar *History, PlaylistManager *manager, ListPlaylist *listPL)
{
  FILE *f;

  f = fopen(concat("data/", namafile), "w");
  printf("hahahihi\n");
  if (f == NULL)
  {
      printf("Tidak bisa membuka file %s\n", namafile);
      return;
  }

  fprintf(f, "%d\n", NbElmt(*arrPenyanyi) + 1);
  int i;
  for (i = 0; i <= NbElmt(*arrPenyanyi); i++)
  {
    string singer = GetElmt(*arrPenyanyi, i);
    Array singerAlbums = ValueInPenyanyi(*albumPenyanyi, singer);
    fprintf(f, "%d %s\n", NbElmt(singerAlbums) + 1, singer);

    int j;
    for (j = 0; j <= NbElmt(singerAlbums); j++)
    {
      string albumTitle = GetElmt(singerAlbums, j);
      Set albumSongs = ValueInAlbum(*laguAlbum, albumTitle);
      fprintf(f, "%d %s\n", albumSongs.Count, albumTitle);

      int k;
      for (k = 0; k < albumSongs.Count; k++)
      {
        fprintf(f, "%s\n", albumSongs.Elements[k]);
      }
    }
  }
  fprintf(f, "%s;%s;%s\n", currentSong->artist, currentSong->album, currentSong->song);
  fprintf(f, "%d\n", Length(*Q) + 1);

  printQueueToFile(f, *Q);

  fprintf(f, "%d\n", TopStackchar(*History) + 1);
  printStackcharToFile(f, *History);

  fprintf(f, "%d\n", manager->numPlaylists);

  for (i = 0; i < manager->numPlaylists; i++)
  {
    string playlistTitle = listPL->playlist[i].namePL;
    int countPlaylistSong = manager->playlists[i].numSongs;

    fprintf(f, "%d %s\n", countPlaylistSong, playlistTitle);

    printPlaylistToFile(f, manager->playlists[i]);
  }

  fclose(f);

}