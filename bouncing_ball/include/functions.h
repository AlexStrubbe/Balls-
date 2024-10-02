#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct
{
  int x;
  int y;
} BallPosition;

extern BallPosition ball_pos;
extern int counter_val;
void *UpdateBallPosition(void *arg);
void *Counter(void *arg);

#endif
