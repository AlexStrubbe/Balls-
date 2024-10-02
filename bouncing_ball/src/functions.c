#include "functions.h"
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define ENTER_NCURSES 10

BallPosition ball_pos[10];
int balls = 1;
int counter_val = 0;
int loop_breaker = 0;

void *UpdateBallPosition(void *arg)
{
  while (1)
  {
    int row, col;
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    for (int i = 0; i < balls; i++)
    {
      ball_pos[i].x += ball_pos[i].dx;
      ball_pos[i].y += ball_pos[i].dy;
      if (ball_pos[i].x >= col - 1)
      {
        ball_pos[i].dx = -1;
      }
      if (ball_pos[i].y >= row - 1)
      {
        ball_pos[i].dy = -1;
      }
      if (ball_pos[i].x <= 1)
      {
        ball_pos[i].dx = 1;
      }
      if (ball_pos[i].y <= 1)
      {
        ball_pos[i].dy = 1;
      }
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

void CreateBall()
{
  int row, col;
  getmaxyx(stdscr, row, col);
  if (balls < 10)
  {
    ball_pos[balls].x = rand() % row;
    ball_pos[balls].y = rand() % col;
    ball_pos[balls].dx = (rand() % 2 == 0 ? 1 : -1);
    ball_pos[balls].dy = (rand() % 2 == 0 ? 1 : -1);
    balls++;
  }
}
