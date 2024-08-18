#include "../matrix.h"

void clear_matrix(int matrix[][20]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      matrix[i][j] = 0;
    }
  }
}