#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct
{
  int x, y;
  int dx, dy;
} BallPosition;

extern BallPosition ball_pos[10];
extern int balls;
extern int counter_val;
extern int loop_breaker;
void *UpdateBallPosition(void *arg);
void *Counter(void *arg);
void CreateBall();

#endif
