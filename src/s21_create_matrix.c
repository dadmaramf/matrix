#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int correct = OK;
  if (rows <= 0 || columns <= 0) correct = IncorrectMatrix;
  if (correct == OK) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      if (!(result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
        for (int j = i; j >= 0; j--) free(result->matrix[i]);
        free(result->matrix);
      }
    }
  }
  return correct;
}
