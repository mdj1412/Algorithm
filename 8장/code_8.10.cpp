// 코드 8.10 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘

#include <vector>

int lis(const std::vector<int>& A) {
    // 기저 사례: A가 텅 비어 있을 때
    if (A.empty()) return 0;
    int ret = 0;
    for (int i = 0; i < A.size(); ++i) {
        std::vector<int> B;
        for (int j = i+1; j < A.size(); ++j)
            if (A[i] < A[j])
                B.push_back(A[j]);
        ret = std::max(ret, 1 + lis(B));
    }
    return ret;
}