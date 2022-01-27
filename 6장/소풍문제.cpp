#include <iostream>

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    int count = 0, next = 0;
    
    while ((next<n) && taken[next])
        next++;
    
    if (next == n) { return 1; }
    
    taken[next] = true;
    for (int i=next+1;i<n;i++)
        if (!taken[i] && areFriends[next][i]) {
            taken[i] = true;
            count += countPairings(taken);
            taken[i] = false;
        }
    taken[next] = false;
    
    return count;
}


int main(void) {
    int C;
    scanf("%d", &C);
    
    for (int i=0;i<C;i++) {
        int m, a, b;
        bool taken[10];
        scanf("%d %d", &n, &m);
        
        for (int j=0;j<10;j++) {
            taken[j] = false;
            for (int k=0;k<10;k++)
                areFriends[j][k] = false;
        }
        
        for (int j=0;j<m;j++) {
            scanf("%d %d", &a, &b);
            if (a < b)
                areFriends[a][b] = true;
            else
                areFriends[b][a] = true;
        }
        
        printf("%d\n", countPairings(taken));
    }
}


//3
//2 1
//0 1
//1
//4 6
//0 1 1 2 2 3 3 0 0 2 1 3
//1
//6 10
//0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
//1