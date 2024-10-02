#include "functions.h"
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>

BallPosition ball_pos;
int counter_val = 0;

void *UpdateBallPosition(void *arg)
{
  ball_pos.x = 0;
  ball_pos.y = 0;
  int dx = 1, dy = 1;
  int row, col;

  while (1)
  {
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    ball_pos.x += dx;
    ball_pos.y += dy;
    if (ball_pos.x >= col - 1)
    {
      dx = -1;
    }
    if (ball_pos.y >= row - 1)
    {
      dy = -1;
    }
    if (ball_pos.x <= 1)
    {
      dx = 1;
    }
    if (ball_pos.y <= 1)
    {
      dy = 1;
    }
    usleep(100000); /* Duerme por 100ms */
  }
}

void *Counter(void *arg)
{
  while (1)
  {
    counter_val++;
    usleep(1000000);
  }
}
