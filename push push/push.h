#ifndef _PUSH_H
#define _PUSH_H

#if 0
#define __DEBUG
#endif

typedef struct _Point {
	int row;
	int column;
} Point;

#define SIZE				10
#define LEVEL				2

#define KEY_EXT				247
#define KEY_UP				72
#define KEY_DOWN			80
#define KEY_RIGHT			77
#define KEY_LEFT			75
#define KEY_STOP			'q'
#define KEY_RESET			'r'

#define ICON_EMPTY			0
#define ICON_WALL			1
#define ICON_OBSTACLE		2
#define ICON_OBSTACLE_ADD	3
#define ICON_TARGET			4
#define ICON_BLOCK			7
#define ICON_USER			8
#define ICON_KILLER			9

#define RET_SUCCESS			1
#define RET_FAIL			0

void	init(int);
void	display();
int		getkey();
int		check(Point *);
Point	move(Point, int [SIZE][SIZE]);
int		finish(int [SIZE][SIZE]);
void	getindex(int, Point *);
void	display_update(Point);
void	gotoxy(int x, int y);
void	icon_print(int);

#endif