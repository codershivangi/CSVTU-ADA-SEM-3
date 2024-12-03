#include <stdio.h>
#define MAX 10  

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            for (int k = 0; k < colFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int rowFirst, colFirst, rowSecond, colSecond;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colFirst; j++) {
            scanf("%d", &first[i][j]);
        }
    }
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);
    if (colFirst != rowSecond) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return 1;
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rowSecond; i++) {
        for (int j = 0; j < colSecond; j++) {
            scanf("%d", &second[i][j]);
        }
    }
    multiplyMatrices(first, second, result, rowFirst, colFirst, rowSecond, colSecond);
    printf("\nResultant Matrix after multiplication:\n");
    displayMatrix(result, rowFirst, colSecond);

    return 0;
}
