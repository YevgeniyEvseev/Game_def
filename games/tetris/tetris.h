#ifndef TETRIS_H
#define TETRIS_H

typedef struct {
  int field[10][20];
  int next[10][20];
  int figure_m[10][20];
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

void init_game_info(GameInfo_t *data);
#endif