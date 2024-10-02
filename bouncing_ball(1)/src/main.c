#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

#define ENTER_NCURSES 10

int main()
{
  pthread_t ball, cntr;

  initscr();
  keypad(stdscr, TRUE);
  noecho();

  curs_set(0);

  pthread_create(&ball, NULL, UpdateBallPosition, NULL);
  pthread_create(&cntr, NULL, Counter, NULL);

  while (1)
  {
    clear();
    mvprintw(0, 0, "%d", counter_val);
    mvprintw(ball_pos.y, ball_pos.x, "o");
    refresh();

    usleep(100000); /* Duerme por 100ms */
  }

  getch();
  endwin();

  pthread_join(ball, NULL);
  pthread_join(cntr, NULL);

  return 0;
}