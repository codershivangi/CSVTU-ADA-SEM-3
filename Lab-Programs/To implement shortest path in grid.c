#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

int rowDir[] = {-1, 1, 0, 0};  
int colDir[] = {0, 0, -1, 1};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* points;
    int front, rear, size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->points = (Point*)malloc(q->size * sizeof(Point));
    return q;
}

bool isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Point p) {
    if (q->rear == q->size - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->points[q->rear] = p;
}

Point dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        Point p = {-1, -1};  
        return p;
    }
    Point p = q->points[q->front];
    q->front++;
    if (q->front > q->rear) { 
        q->front = q->rear = -1;
    }
    return p;
}

bool isValid(int grid[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] == 0 && !visited[x][y];
}
int bfs(int grid[ROWS][COLS], Point start, Point end) {
    bool visited[ROWS][COLS] = {false};
    int dist[ROWS][COLS] = {0};  
    
    Queue* q = createQueue(ROWS * COLS);
    
    enqueue(q, start);
    visited[start.x][start.y] = true;
    
    while (!isQueueEmpty(q)) {
        Point curr = dequeue(q);
        if (curr.x == end.x && curr.y == end.y) {
            return dist[curr.x][curr.y];
        }
        
        for (int i = 0; i < 4; i++) {
            int newX = curr.x + rowDir[i];
            int newY = curr.y + colDir[i];
            
            if (isValid(grid, visited, newX, newY)) {
                visited[newX][newY] = true;
                dist[newX][newY] = dist[curr.x][curr.y] + 1;
                Point newPoint = {newX, newY};
                enqueue(q, newPoint);
            }
        }
    }
    
    return -1;
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };
    
    Point start = {0, 0}; 
    Point end = {4, 4};    
    
    int result = bfs(grid, start, end);
    
    if (result != -1)
        printf("Shortest path length: %d\n", result);
    else
        printf("No path found\n");
    
    return 0;
}
