
// 아쉬운 부분 찾기 !
// 내 생각) 시간 복잡도 O(n) = n^2

#include <iostream>

int n, triangle[100][100];
int cache[100][100];

int path(int y, int x) {
    // base case
    if (y == n-1)
        return triangle[y][x];
    
    // memoization
    int& ret1 = cache[y+1][x];
    int& ret2 = cache[y+1][x+1];

    if (ret1 == -1) ret1 = path(y+1, x);
    if (ret2 == -1) ret2 = path(y+1, x+1);
    
    return triangle[y][x] + std::max<int>(ret1, ret2);
}

// 아쉬운 이유)
// cache[y][x]의 의미 : (y, x)부터 y == n-1까지의 최댓값
// 이때 ret을 잡을 때 (y, x)를 기준으로 값이 존재하는지 확인
//
// 문제 포인트 !
// 1. 어떤 부분 문제로 분할할 수 있는지
// 2. cache에 저장되는 기준을 명확하게