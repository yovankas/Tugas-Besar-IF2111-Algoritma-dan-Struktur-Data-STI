CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = ../src/adt
CONSOLE_DIR = ../src/console
MAIN_DIR = ../src

all: main driverset console driveralbum driverqueue driverplaylist load

main: $(MAIN_DIR)/main.c $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/string/string.c $(SRC_DIR)/queue/circular_queue.c $(SRC_DIR)/stack/stackchar.c $(SRC_DIR)/current/current.c $(SRC_DIR)/playlist/playlist.c $(SRC_DIR)/listplaylist/listplaylist.c $(CONSOLE_DIR)/console.c $(CONSOLE_DIR)/load.c $(CONSOLE_DIR)/save.c
	$(CC) $(CFLAGS) -o main $^

driverset: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/set/driverset.c
	$(CC) $(CFLAGS) -o driverset $^

console: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/stack/stackchar.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/queue/circular_queue.c $(SRC_DIR)/current/current.c $(SRC_DIR)/playlist/playlist.c $(SRC_DIR)/listplaylist/listplaylist.c $(CONSOLE_DIR)/console.c
	$(CC) $(CFLAGS) -o console $^

driveralbum: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/album/driveralbum.c
	$(CC) $(CFLAGS) -o driveralbum $^

driverqueue: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/string/string.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/queue/circular_queue.c $(SRC_DIR)/queue/driverqueue.c
	$(CC) $(CFLAGS) -o driverqueue $^

driverplaylist: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/word/word.c $(SRC_DIR)/string/string.c $(SRC_DIR)/playlist/playlist.c $(SRC_DIR)/playlist/driverplaylist.c
	$(CC) $(CFLAGS) -o driverplaylist $^

load: $(SRC_DIR)/array/array.c $(SRC_DIR)/set/set.c $(SRC_DIR)/mesin/mesinkarakter.c $(SRC_DIR)/mesin/mesinkata.c $(SRC_DIR)/penyanyi/penyanyi.c $(SRC_DIR)/album/album.c $(SRC_DIR)/word/word.c $(SRC_DIR)/string/string.c $(SRC_DIR)/queue/circular_queue.c $(SRC_DIR)/stack/stackchar.c $(SRC_DIR)/current/current.c $(SRC_DIR)/playlist/playlist.c $(SRC_DIR)/listplaylist/listplaylist.c $(CONSOLE_DIR)/console.c $(CONSOLE_DIR)/load.c
	$(CC) $(CFLAGS) -o load $^

.PHONY: all main driverset console driveralbum driverqueue driverplaylist load