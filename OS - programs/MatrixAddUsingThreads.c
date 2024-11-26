#include <stdio.h>
#include <pthread.h>

#define N 4


int A[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}};
int B[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}};
int C[N][N]; 

void *multiply_row(void *arg)
{
    int row = *(int *)arg; 
    for (int j = 0; j < N; j++)
    {
        C[row][j] = 0; 
        for (int k = 0; k < N; k++)
        {
            C[row][j] += A[row][k] * B[k][j];
        }
    }
    return NULL;
}

int main()
{
    pthread_t threads[N];
    int rows[N]; 

    
    for (int i = 0; i < N; i++)
    {
        rows[i] = i;
        if (pthread_create(&threads[i], NULL, multiply_row, &rows[i]) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }

    
    printf("Result matrix C:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
