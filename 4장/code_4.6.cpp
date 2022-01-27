#include <iostream>
#include <vector>

// 코드 4.6 가장 간단한 형태의 소인수 분해 알고리즘

// 자연수 n의 소인수 분해 결과를 담은 정수 배열을 반환한다.
std::vector<int> factor(int n) {
    if (n == 1) return std::vector<int>(1, 1); // n = 1인 경우는 예외로 한다.
    
    std::vector<int> ret;
    for (int div=2;n>1;++div)
        while (n % div == 0) {
            n /= div;
            ret.push_back(div);
        }
    
    return ret;
}