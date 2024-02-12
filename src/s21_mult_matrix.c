#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int correct = s21_check_empt(*A);
  if (correct == OK)
    if (!(correct = s21_create_matrix(A->rows, A->columns, result)))
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
  return correct;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int correct = s21_colum_equal_rows(*A, *B);
  if (correct == OK &&
      !(correct = s21_create_matrix(A->rows, B->columns, result)))
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++)
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
    }
  return correct;
}
