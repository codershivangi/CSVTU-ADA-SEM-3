#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000

typedef struct SegmentTree {
    int *tree;
    int size;
} SegmentTree;
void buildTree(int arr[], SegmentTree *st, int node, int start, int end) {
    if (start == end) {
        st->tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(arr, st, 2 * node + 1, start, mid);
        buildTree(arr, st, 2 * node + 2, mid + 1, end);
        st->tree[node] = (st->tree[2 * node + 1] < st->tree[2 * node + 2]) ? st->tree[2 * node + 1] : st->tree[2 * node + 2];
    }
}
int query(SegmentTree *st, int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return INF;
    }
    if (L <= start && end <= R) {
        return st->tree[node];
    }
    int mid = (start + end) / 2;
    int left_query = query(st, 2 * node + 1, start, mid, L, R);
    int right_query = query(st, 2 * node + 2, mid + 1, end, L, R);
    return (left_query < right_query) ? left_query : right_query;
}

SegmentTree *createSegmentTree(int arr[], int n) {
    SegmentTree *st = (SegmentTree *)malloc(sizeof(SegmentTree));
    int size = (1 << ((int)(log2(n)) + 1)) - 1;
    st->size = size;
    st->tree = (int *)malloc(sizeof(int) * size);
    buildTree(arr, st, 0, 0, n - 1);
    return st;
}

void destroySegmentTree(SegmentTree *st) {
    free(st->tree);
    free(st);
}

int main() {
    int arr[] = {2, 4, 0, 5, 3, 7, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    SegmentTree *st = createSegmentTree(arr, n);
    int L = 2, R = 6;
    printf("Minimum in range [%d, %d]: %d\n", L, R, query(st, 0, 0, n - 1, L, R));
    L = 1, R = 4;
    printf("Minimum in range [%d, %d]: %d\n", L, R, query(st, 0, 0, n - 1, L, R));
    destroySegmentTree(st);

    return 0;
}
