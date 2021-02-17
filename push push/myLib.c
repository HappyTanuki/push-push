#include <stdio.h>
#include <windows.h>
#include "push.h"

extern int			(*map[LEVEL])[SIZE];
extern int			ground[SIZE][SIZE];
extern Point		player;

void init(int level) {
	int i, k;

	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			ground[i][k] = map[level][i][k];
			if (ground[i][k] == ICON_USER) {
				player.row		= i;
				player.column	= k;
			}
		}
	}
}

void display() {
	int i, k;

	system("cls");

	for (i = 0; i < SIZE; i++) {
		for (k = 0; k < SIZE; k++) {
			icon_print(ground[i][k]);
		}
		printf("\n");
	}
#ifdef __DEBUG
	printf("Player: (%d, %d)\n", player.row, player.column);
#endif
}

int getkey() {
	int key;

	key = getch();
	if (key == KEY_EXT) {
		key = getch();
	}

	return key;
}
