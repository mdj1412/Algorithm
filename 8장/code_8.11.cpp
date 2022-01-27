// 코드 8.11 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘(1)

int n;
int cache[100], S[100];

// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for (int next = start+1; next < n; ++next)
        if (A[start] < A[next])
            ret = std::max(ret, lis2(next) + 1);
    return ret;
}

// 시작 위치 고정하기
int main(void) {
    
    int maxLen = 0;
    for (int begin = 0; begin < n; ++begin)
        maxLen = std::max(maxLen, lis2(begin));

    return 0;
}