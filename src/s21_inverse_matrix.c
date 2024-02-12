#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int correct = s21_check_empt(*A);
  double det = 0.0;
  if (correct == OK &&
      (A->rows != A->columns || (det = s21_rec_determinant(A)) == 0.0))
    correct = CalculationError;
  else if (correct == OK) {
    if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1.0 / det;
    } else {
      matrix_t calc = {0};
      s21_calc_complements(A, &calc);
      matrix_t transpose = {0};
      s21_transpose(&calc, &transpose);
      s21_remove_matrix(&calc);
      s21_mult_number(&transpose, 1 / det, result);
      s21_remove_matrix(&transpose);
    }
  }
  return correct;
}
