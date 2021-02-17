#include "push.h"

extern int			(*map[LEVEL])[SIZE];
int					ground[SIZE][SIZE];
Point				player;

int main() {
	int key = 0, level = 0;
	Point mPoint;

	while (level < LEVEL) {
		init(level);
		display();

		while (!finish(map[level])) {

			key = getkey();
			if (key == KEY_STOP)
				return;
			if (key == KEY_RESET) {
				init(0);
				display();
				continue;
			}

			getindex(key, &mPoint);

			if (!check(&mPoint))
				continue;

			display_update(move(mPoint, map[level]));
		}

		level++;
	}

	return 0;
}