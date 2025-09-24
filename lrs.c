#include <stdio.h>
#include <string.h>

#define MAX 100

struct string
{
    char d; 
    int v; 
};

void LRS(char a[])
{
    int n = strlen(a);

    struct string cost[MAX][MAX];
    for (int i = 0; i <= n; i++)
    {
        cost[i][0].v = 0;
        cost[i][0].d = 'H'; 
    }

    for (int j = 0; j <= n; j++)
    {
        cost[0][j].v = 0;
        cost[0][j].d = 'H';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == a[j - 1] && i!=j)
            {
                cost[i][j].v = cost[i - 1][j - 1].v + 1;
                cost[i][j].d = 'D';
            }
            else if (cost[i - 1][j].v >= cost[i][j - 1].v)
            {
                cost[i][j].v = cost[i - 1][j].v;
                cost[i][j].d = 'U';
            }
            else
            {
                cost[i][j].v = cost[i][j - 1].v;
                cost[i][j].d = 'S';
            }
        }
    }

    char result[MAX];
    int index = 0;
    int i = n, j = n;

    while (i > 0 && j > 0)
    {
        if (cost[i][j].d == 'D')
        {
            result[index++] = a[i - 1];
            i--;
            j--;
        }
        else if (cost[i][j].d == 'U')
        {
            i--;
        }
        else // 'S'
        {
            j--;
        }
    }

    result[index] = '\0';
  
    for (int k = 0; k < index / 2; k++)
    {
        char temp = result[k];
        result[k] = result[index - k - 1];
        result[index - k - 1] = temp;
    }

    printf("The LRS is: %s\n", result);
    printf("The length of LRS is: %d\n", cost[n][n].v);
}

int main()
{
    char str[MAX];

    printf("Enter string: ");
    scanf("%s", str);
    LRS(str);

    return 0;
}

