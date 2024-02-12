#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int equal = SUCCESS;
  if (s21_equal_size(*A, *B) == 0) {
    for (int i = 0; i < A->rows && equal == SUCCESS; i++)
      for (int j = 0; j < A->columns && equal == SUCCESS; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) equal = FAILURE;
  } else
    equal = FAILURE;
  return equal;
}
