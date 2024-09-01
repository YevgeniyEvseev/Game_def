#include <stdio.h>
#include <stdlib.h>

#include "../snake.h"

int read_file(const char* user, int* offset) {
  FILE* file_user;
  int ch;
  int i = 0, high_score = 0;
  int status = FIND_CH;
  *offset = 0;
  if ((file_user = fopen("games/tetris/user_data.txt", "r")) == NULL) {
    fprintf(stderr, "can not open file");
    return 0;
  }
  while ((ch = fgetc(file_user)) != EOF) {
    (*offset)++;
    switch (status) {
      case FIND_CH: {
        if (user[i] == '\0' && ch == ' ') {
          status = GET_NUMBER;
          break;
        }
        if (ch == user[i]) {
          i++;
        } else {
          status = NEXT_STR;
          i = 0;
        }
      } break;
      case NEXT_STR:
        if (ch == '\n') status = FIND_CH;
        break;
      case GET_NUMBER: {
        if (ch >= '0' && ch <= '9') {
          int tmp = ch - '0';
          high_score = high_score * 10 + tmp;
        } else {
          fclose(file_user);
          return high_score;
        }
        break;
      }
      default:
        fprintf(stderr, "uncorrect read file");
        break;
    }
  }
  fclose(file_user);
  return high_score;
}

void save_file(GameInfo_t* data, const char* user, int new_high_score,
               int offset) {
  FILE* file_user;
  long size;
  char n[7] = {0};
  int_to_str(new_high_score, n);
  if (data->high_score > new_high_score) return;
  if ((file_user = fopen("games/tetris/user_data.txt", "r+")) == NULL) {
    fprintf(stderr, "can not open file");
    return;
  }
  if (data->high_score == 0) {
    offset = 0;
    char tmp[256] = {0};
    sprintf(tmp, "%s %s\n", user, n);
    fseek(file_user, 0, SEEK_END);
    fputs(tmp, file_user);
  }
  if (data->high_score > 0) {
    fseek(file_user, (offset - 6) * sizeof(char), SEEK_CUR);
    fputs(n, file_user);
  }
  fclose(file_user);
}

void int_to_str(int src, char* dst) {
  char str[7] = {0};
  char* tmp = dst;
  int ch = 0, i = 0;
  do {
    ch = src % 10;
    str[i++] = '0' + ch;
  } while ((src /= 10) > 0);
  while (i < 6) {
    str[i++] = '0';
  }
  i--;
  while (i >= 0) {
    *tmp++ = str[i--];
  }
  *tmp = '\0';
}
