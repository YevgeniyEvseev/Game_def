#ifndef TETRIS_H
#define TETRIS_H

enum status_find { FIND_CH, NEXT_STR, GET_NUMBER };

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
int read_file(const char *user, int *offset);
void save_file(GameInfo_t *data, const char *user, int new_high_score,
               int offset);
void int_to_str(int src, char *str);
#endif