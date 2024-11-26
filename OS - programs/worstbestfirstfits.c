#include <stdio.h>

void worstfit(int b[], int m, int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i] && (maxIdx == -1 || b[maxIdx] < b[j]))
            {
                maxIdx = j;
            }
        }
        if (maxIdx != -1)
        {
            printf("Process %d allocated to Block %d\n", i + 1, maxIdx + 1);
            b[maxIdx] -= p[i];
        }
        else
        {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

void bestfit(int b[], int m, int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i] && (bestIdx == -1 || b[bestIdx] > b[j]))
            {
                bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            printf("Process %d allocated to Block %d\n", i + 1, bestIdx + 1);
            b[bestIdx] -= p[i];
        }
        else
        {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

void firstfit(int b[], int m, int p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i])
            {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                b[j] -= p[i];
                break;
            }
        }
    }
}

int main()
{
    int blockSize[10], processSize[10], m, n;
    int tempBlockSize[10];

    printf("Enter no. of blocks: ");
    scanf("%d", &m);
    printf("Enter block sizes: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter process sizes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < m; i++)
        tempBlockSize[i] = blockSize[i];
    worstfit(tempBlockSize, m, processSize, n);

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < m; i++)
        tempBlockSize[i] = blockSize[i];
    bestfit(tempBlockSize, m, processSize, n);

    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < m; i++)
        tempBlockSize[i] = blockSize[i];
    firstfit(tempBlockSize, m, processSize, n);

    return 0;
}