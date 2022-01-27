// 코드 8.5 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘

int n, board[100][100];
int cache[100][100];

int jump2(int y, int x) {
    // 기저 사례 처리
    if (y >= n || x >= n) return 0;
    if (y == n-1 && x == n-1) return 1;

    // 메모이제이션
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}



// 의문점) 마지막 return에서 논리 연산자가 아닌 비트 연산자를 적용해야되지 않을까 ?
//        그렇게 작성하는 이유는 무엇일까 ?

bool isTrue() {
    return true;
}
bool isFalse() {
    return false;
}
int main(void) {

    printf("%d\n", 1||0);
    printf("%d\n", 1|0);
    
    // 의문점)
    //  a || b  => 논리 연산자
    //  a가 만약 true면 b를 확인하지 않고 바로 true를 결론 짓는다.
    //  a | b   => 비트 연산자
    //  a가 true여도 b까지 확인한다.
    
    printf("%d\n", isTrue() || isFalse());
    printf("%d\n", isTrue() | isFalse());
    
    // breakpoint를 이용해서 문제를 해결한다.

    return 0;
}