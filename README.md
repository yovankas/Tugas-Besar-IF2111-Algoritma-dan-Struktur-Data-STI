# Tugas-Besar-IF2111-Algoritma-dan-Struktur-Data-STI
Sebagai makhluk kasat mata yang setia kepada Bondowoso, kami memahami perjuangan yang dialaminya dalam mencari teman dan mendekati hati Roro. Meskipun Bondowoso memiliki fisik yang menakutkan, hatinya penuh dengan kebaikan dan keahlian musik yang luar biasa.    
Kami, makhluk kasat mata yang selalu setia menemaninya, melihat bagaimana Bondowoso berusaha mencari cara untuk mendekati Roro yang tergila-gila pada musik hip-hop. Suatu hari, ketika kami sedang berdiskusi dengan Bondowoso, muncullah ide brilian dari salah satu teman kasat mata yang dulunya pendiri startup produksi roda batu.
Pemikiran untuk membuat aplikasi WayangWave adalah langkah inovatif yang kami yakini dapat meluluhkan hati Roro. Kami, sebagai makhluk kasat mata yang selalu mendukung Bondowoso, sepakat untuk membantu membangun aplikasi tersebut. Kami pun bekerja sama dengan Bondowoso dan lima teman kasat mata lainnya untuk mengembangkan WayangWave.
Dengan semangat dan tekad yang kuat, kami memanfaatkan kekuatan Anak Intern AI yang kami miliki untuk menciptakan aplikasi simulasi berbasis CLI. Kami memilih bahasa C sebagai alat utama untuk mewujudkan ide WayangWave ini, memanfaatkan struktur data yang telah kami pelajari selama mata kuliah IF2111 Algoritma dan Struktur Data STI. Struktur data yang kami gunakan meliputi ADT Array, ADT Mesin Karakter dan Mesin Kata, ADT Queue, ADT Stack, ADT Set & Map, ADT Linked List, serta library stdio.h, stdlib.h, time.h, dan math.h.
WayangWave bukan hanya sekadar aplikasi pemutar musik biasa, tetapi juga dilengkapi dengan fitur-fitur canggih seperti membuat dan menghapus playlist, mengatur urutan lagu, dan menampilkan status aplikasi. Semua ini kami rancang dengan detail, sesuai dengan keinginan Bondowoso untuk menunjukkan keindahan musik kepada Roro.
Dengan dedikasi dan kerja keras, akhirnya WayangWave berhasil dibuat dan siap digunakan. Kami yakin bahwa aplikasi ini akan menjadi senjata ampuh Bondowoso untuk mendekati hati Roro. Sebagai makhluk kasat mata, kami bersatu padu untuk memberikan yang terbaik demi kebahagiaan teman baik kami, Bondowoso.

# Struktur Folder
Berikut adalah struktur folder dari WayangWave kami:
- Folder `bin` yang berisi
  - File `Makefile` untuk melakukan kompilasi terhadap program utama
- Folder `data` yang berisi nama album, lagu, dan penyanyi
- Folder `Docs` yang berisi dokumen-dokumen tugas besar
- Folder `src` yang berisi :
  - Folder `ADT` yang berguna untuk menyimpan seluruh ADT yang digunakan
  - Folder `console` yang digunakan untuk menyimpan seluruh utilities dalam WayangWave yang diperlukan (start, load, list, play, queue, song, playlist, status, save, quit, help)
  - File `main.c` yang merupakan program utama
  - File `boolean.h` sebagai header boolean

# Prosedur Penggunaan
Windows
Program dapat dijalankan di command prompt dengan memiliki package make

Package make didapatkan dengan menginstall chocolatey terlebih dahulu. Untuk langkah-langkah menginstall chocolatey dapat mengikuti link berikut: [https://chocolatey.org/install](url)

Jika chocolatey telah terinstall pada PATH dalam Environmental Variables Device, dapat melakukan prosedur berikut:

1. Buka Windows powershell dalam device dan _run as administrator_
2. Untuk menginstall package make : **choco install make**
3. Tunggu hingga package make selesai diinstall.

Setelah package make terinstall, anda dapat mengompilasi program dengan menjalankan prosedur berikut:

1. Masuk ke folder IF2111 yang telah di download / clone dari github repositorynya.
2. Buka windows terminal dalam folder tersebut.
3. Untuk mengompilasi program ini, dapat mengetik : **make compile**
4. Setelah program selesai di-compile, anda dapat mengetik : **./main**
5. Program telah berjalan dan silahkan nikmati programnya

# Anggota Kelompok
Program WayangWave ini dikembangkan oleh Kelompok 01-Brot (K2)
1. Muhammad Daffa Ikram `18222020`
   START, QUEUE SWAP, QUEUE REMOVE, QUEUE CLEAR, SAVE, dan INVALID COMMAND.
2. Christoper Daniel `18222034`
   PLAYLIST CREATE, PLAYLIST ADD, PLAYLIST SWAP, PLAYLIST REMOVE, dan PLAYLIST DELETE.
3. Yovanka Sandrina Maharaja `18222094`
   LOAD, LIST DEFAULT, LIST PLAYLIST, PLAY SONG, QUEUE SONG, QUIT, dan HELP.
4. Ervina Limka `18222100`
   PLAY PLAYLIST, QUEUE PLAYLIST, SONG NEXT, SONG PREVIOUS, dan STATUS.
