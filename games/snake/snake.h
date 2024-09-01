#ifndef SNAKE_H
#define SNAKE_H

enum status_find { FIND_CH, NEXT_STR, GET_NUMBER };

enum intersection { NOT_ITR, LEFT_BOARD, RIGHT_BOARD, DOWN_BOARD, FIELD };

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int count;
  Point snake[200];
} figure;

typedef struct {
  Point eat;
  figure cur_figure;
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

void init_game_info(GameInfo_t *data);
int read_file(const char *user, int *offset);
void save_file(GameInfo_t *data, const char *user, int new_high_score,
               int offset);
void int_to_str(int src, char *str);

void load_interface();
void updateCurrentState(GameInfo_t *data, state_game *state, const char *user,
                        int input);
UserAction_t userInput(int action);

#endif