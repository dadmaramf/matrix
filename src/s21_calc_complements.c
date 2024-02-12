#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int correct = s21_check_empt(*A);
  if (!correct && (A->rows != A->columns || A->rows == 1))
    correct = CalculationError;
  if (correct == OK &&
      !(correct = s21_create_matrix(A->rows, A->columns, result))) {
    matrix_t minor = {0};
    double resultt = 0.0;
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        s21_get_minor_matrix(i, j, *A, &minor);
        s21_determinant(&minor, &resultt);
        s21_remove_matrix(&minor);
        result->matrix[i][j] = pow(-1, i + j) * resultt;
      }
  }
  return correct;
}

int s21_get_minor_matrix(int rows, int columns, matrix_t A, matrix_t *minor) {
  int correct = 0;
  if (!(correct = s21_create_matrix(A.rows - 1, A.columns - 1, minor))) {
    for (int i = 0, k = 0; i < A.rows; i++) {
      for (int c = 0, j = 0; j < A.columns; j++)
        if (rows != i && columns != j) minor->matrix[k][c++] = A.matrix[i][j];
      if (rows != i) k++;
    }
  }
  return correct;
}
