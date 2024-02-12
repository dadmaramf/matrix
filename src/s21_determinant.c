#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  int correct = s21_check_empt(*A);
  if (!correct && A->rows != A->columns)
    correct = CalculationError;
  else
    *result = s21_rec_determinant(A);
  return correct;
}

double s21_rec_determinant(matrix_t *A) {
  double result = 0.0;
  matrix_t minor = {0};
  if (A->rows == 1)
    result = A->matrix[0][0];
  else {
    for (int i = 0; i < A->rows; i++) {
      s21_get_minor_matrix(0, i, *A, &minor);
      result +=
          (i % 2 == 0 ? 1 : -1) * A->matrix[0][i] * s21_rec_determinant(&minor);
      s21_remove_matrix(&minor);
    }
  }

  return result;
}
