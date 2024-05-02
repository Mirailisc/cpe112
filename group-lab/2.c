#include <stdio.h>

int mat[1000][1000];
int visited[1000];

void dfs(int now)
{
    if (visited[now])
    {
        return;
    }

    printf("%d ", now);

    visited[now] = 1;

    for (int v = 0; v < 1000; v++)
    {
        if (mat[now][v])
        {
            dfs(v);
        }
    }
}

int queue[1000];
int rear, front;

int main()
{
    int n, m;
    rear = 0;
    front = 0;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < 1000; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < 1000; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;

        scanf("%d%d", &u, &v);
        mat[u][v] = 1;
    }

    int s;
    scanf("%d", &s);

    queue[rear++] = s;
    visited[s] = 1;

    while (rear > front)
    {
        int now = queue[front];
        front++;
        printf("%d ", now);
        for (int v = 0; v < 1000; v++)
        {
            if (now == v)
            {
                continue;
            }
            if (mat[now][v] && visited[v] == 0)
            {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        visited[i] = 0;
    }

    printf("\n");
    dfs(s);
}