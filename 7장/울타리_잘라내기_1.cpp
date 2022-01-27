// i 번째를 높이로 설정했을 때 가장 큰 직사각형의 넓이
// 를 구해서 각각을 비교하였다.
// 시간 복잡도 -> O(n^2)
// code 7.7과 비교

int bruteForce(const std::vector<int>& h) {
    int ret = 0, n = h.size();

    // i 번째를 높이로 설정했을 때 가장 큰 직사각형의 넓이
    for (int i=0;i<n;i++) {
        int height = h[i], width = 1, j;
        
        // i 번째 기준 왼쪽
        j = i-1;
        while ((j >= 0) && (height <= h[j])) { j--; width++; }
        
        // i 번째 기준 오른쪽
        j = i+1;
        while ((j < n) && (height <= h[j])) { j++; width++; }
        
        ret = std::max(ret, height * width);
    }
    
    return ret;
}

int main(void) {
    int C;
    std::string s;
    scanf("%d", &C);
    std::cin.ignore();
    
    for (int i=0;i<C;i++) {
        int N;
        std::vector<int> h;
        scanf("%d", &N);
        
        for (int j=0;j<N;j++) {
            int a;
            scanf("%d", &a);
            h.push_back(a);
        }
        
        printf("%d\n", bruteForce(h));
    }
    return 0;
}

//3
//7
//7 1 5 9 6 7 3
//7
//1 4 4 4 4 1 1
//4
//1 8 2 2