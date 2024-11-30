#include <stdio.h>
#define ROWS 4
#define COLS 4

int is_local_minimum(int grid[ROWS][COLS], int i, int j) {
    int current_value = grid[i][j];
    
    
    if (i > 0 && grid[i-1][j] < current_value) return 0;
    
    if (i < ROWS - 1 && grid[i+1][j] < current_value) return 0;
    
    if (j > 0 && grid[i][j-1] < current_value) return 0;
    
    if (j < COLS - 1 && grid[i][j+1] < current_value) return 0;
    
    return 1;
}

void find_local_minima(int grid[ROWS][COLS]) {
    printf("Local minima positions:\n");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (is_local_minimum(grid, i, j)) {
                printf("Local minimum found at (%d, %d) with value %d\n", i, j, grid[i][j]);
            }
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {
        {9, 8, 7, 6},
        {5, 4, 3, 2},
        {1, 2, 3, 4},
        {9, 10, 11, 12}
    };
    
    find_local_minima(grid);
    
    return 0;
}
