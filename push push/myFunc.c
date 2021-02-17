#include <stdio.h>
#include <windows.h>
#include "push.h"

extern int			(*map[LEVEL])[SIZE];
extern int			ground[SIZE][SIZE];
extern Point		player;

int check(Point *mPoint) {

	if (ground[mPoint->row][mPoint->column] == ICON_EMPTY)
		return RET_SUCCESS;
	if (ground[mPoint->row][mPoint->column] == ICON_TARGET)
		return RET_SUCCESS;
	if (ground[mPoint->row][mPoint->column] == ICON_BLOCK && ground[mPoint->row * 2 - player.row][mPoint->column * 2 - player.column] == ICON_EMPTY)
		return RET_SUCCESS;
	if (ground[mPoint->row][mPoint->column] == ICON_BLOCK && ground[mPoint->row * 2 - player.row][mPoint->column * 2 - player.column] == ICON_TARGET)
		return RET_SUCCESS;

	return RET_FAIL;
}

Point move(Point mPoint, int map[SIZE][SIZE]) {
	Point bPoint = player;
	
	if (ground[mPoint.row][mPoint.column] == ICON_BLOCK)
		ground[mPoint.row * 2 - player.row][mPoint.column * 2 - player.column] = ICON_BLOCK;
 
	ground[mPoint.row][mPoint.column] = ICON_USER;

	if (map[player.row][player.column] == ICON_TARGET)
		ground[player.row][player.column] = ICON_TARGET;
	else
		ground[player.row][player.column] = ICON_EMPTY;

	player = mPoint;

	return bPoint;
}

int finish(int map[SIZE][SIZE]) {
	int i = 0, k = 0;

	for (i = 0; i < SIZE; i++)
		for (k = 0; k < SIZE; k++)
			if (ground[i][k] == ICON_BLOCK)
				if (map[i][k] != ICON_TARGET)
					return RET_FAIL;

	return RET_SUCCESS;
}

void getindex(int key, Point *mpoint) {

	*mpoint = player;

	switch (key) {
	case KEY_UP:
		mpoint->row = player.row - 1;
		break;
	case KEY_DOWN:
		mpoint->row = player.row + 1;
		break;
	case KEY_RIGHT:
		mpoint->column = player.column + 1;
		break;
	case KEY_LEFT:
		mpoint->column = player.column - 1;
		break;
	default:
		;
	}

	return;
}

void	gotoxy(int x, int y) {
	COORD pos = { y << 1, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void display_update(Point bPoint) {
	gotoxy(player.row, player.column);
	printf("¢ç");

	gotoxy(bPoint.row, bPoint.column);
	icon_print(ground[bPoint.row][bPoint.column]);

	gotoxy(player.row * 2 - bPoint.row, player.column * 2 - bPoint.column);
	icon_print(ground[player.row * 2 - bPoint.row][player.column * 2 - bPoint.column]);

	gotoxy(10,0);
#ifdef __DEBUG
	printf("Player: (%d, %d)\n", player.row, player.column);
#endif
}

void	icon_print(int key) {
	switch (key) {
	case ICON_EMPTY:
		printf("  ");
		break;
	case ICON_WALL:
		printf("%2s", "¡à");
		break;
	case ICON_OBSTACLE:
		break;
	case ICON_OBSTACLE_ADD:
		break;
	case ICON_TARGET:
		printf("%2s", "¡Ú");
		break;
	case ICON_BLOCK:
		printf("%2s", "¡Ù");
		break;
	case ICON_USER:
		printf("%2s", "¢ç");
		break;
	case ICON_KILLER:
		break;
	}
}