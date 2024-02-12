#include "s21_matrix.h"

int s21_check_empt(matrix_t A) {
  int correct = OK;
  if (A.matrix == NULL || A.rows <= 0 || A.columns <= 0)
    correct = IncorrectMatrix;
  return correct;
}

int s21_equal_size(matrix_t A, matrix_t B) {
  int correct = s21_check_empt(A);
  if (correct == OK) correct = s21_check_empt(B);
  if (correct == OK)
    if (A.rows != B.rows || A.columns != B.columns) correct = CalculationError;
  return correct;
}

int s21_colum_equal_rows(matrix_t A, matrix_t B) {
  int correct = s21_check_empt(A) | s21_check_empt(B);
  if (correct == OK)
    if (A.columns != B.rows) correct = CalculationError;
  return correct;
}
