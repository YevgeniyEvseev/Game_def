#ifndef LIB_GAME_H
#define LIB_GAME_H

enum status_find { FIND_CH, NEXT_STR, GET_NUMBER };

typedef struct {
  int field[10][20];
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef enum {
  START_KEY,
  PAUSE_KEY,
  TERMINATE,
  ROTATE,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NOSIG
} UserAction_t;

typedef enum {
  START = 0,
  SPAWN,
  STANDBY,
  SHIFTING,
  ATTACHING,
  PAUSE,
  GAMEOVER,
  EXIT_STATE
} state_game;

int read_file(const char *user, char *PATH, int *offset);
void save_file(GameInfo_t *data, char *PATH, const char *user,
               int new_high_score, int offset);
void int_to_str(int src, char *str);

#endif