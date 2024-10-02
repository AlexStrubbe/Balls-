#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <functions.h>
#define ENTER_NCURSES 10

int main()
{
  pthread_t ball, cntr, key;

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  curs_set(0);

  pthread_create(&ball, NULL, UpdateBallPosition, NULL);
  pthread_create(&cntr, NULL, Counter, NULL);

  while (1)
  {
    int key_stroke;
    key_stroke = getch();
    refresh();
    if (key_stroke == 32)
    {
      CreateBall();
    }
    else if (key_stroke == 99)
    {
      for (int i = 0; i < balls; i++)
      {
        ball_pos[i].dy = -ball_pos[i].dy;
        ball_pos[i].dx = -ball_pos[i].dx;
      }
    }
    else if (key_stroke == 10)
    {
      break;
    }

    clear();
    mvprintw(0, 0, "%d", counter_val);
    for (int i = 0; i < balls; i++)
    {
      mvprintw(ball_pos[i].y, ball_pos[i].x, "o");
    }

    refresh();

    usleep(100000); /* Duerme por 100ms */
  }
  endwin();

  return 0;
}