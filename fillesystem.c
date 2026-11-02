
#include <stdio.h>
#include <string.h>

#define MAX 20

char nodes[MAX][50];
int adj[MAX][MAX];
int n;

int findNode(char name[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nodes[i], name) == 0)
            return i;
    }
    return -1;
}

int BFS(int start, char target[])
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%s ", nodes[current]);

        if (strcmp(nodes[current], target) == 0)
        {
            found = 1;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile '%s' found using BFS.\n", target);
    else
        printf("\nFile '%s' not found using BFS.\n", target);

    return found;
}

int DFSUtil(int current, char target[],
            int visited[], int *found)
{
    visited[current] = 1;

    printf("%s ", nodes[current]);

    if (strcmp(nodes[current], target) == 0)
    {
        *found = 1;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (adj[current][i] == 1 && !visited[i])
        {
            if (DFSUtil(i, target, visited, found))
                return 1;
        }
    }

    return 0;
}

int DFS(int start, char target[])
{
    int visited[MAX] = {0};
    int found = 0;

    printf("\nDFS Traversal: ");

    DFSUtil(start, target, visited, &found);

    if (found)
        printf("\nFile '%s' found using DFS.\n", target);
    else
        printf("\nFile '%s' not found using DFS.\n", target);

    return found;
}

int main()
{
    int start;
    char startName[50];
    char target[50];

    printf("FILE SYSTEM REPRESENTATION AND SEARCH\n");

    printf("\nEnter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("\nEnter file/directory names:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%49s", nodes[i]);
    }

    printf("\nEnter adjacency matrix (%d x %d):\n", n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] != 0 && adj[i][j] != 1)
            {
                printf("Invalid matrix value.\n");
                return 1;
            }
        }
    }

    printf("\nEnter starting node name: ");
    scanf("%49s", startName);

    start = findNode(startName);

    if (start == -1)
    {
        printf("Starting node not found.\n");
        return 1;
    }

    printf("Enter file/directory to search: ");
    scanf("%49s", target);

    BFS(start, target);
    DFS(start, target);

    return 0;
}
