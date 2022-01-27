// 코드 7.4 카라츠바의 빠른 정수 곱셈 알고리즘
// 추가) 고속푸리에변환 알고리즘
//      을 이용하면 
//      시간 복잡도가 O(n) = n*lgn 이다.

#include <iostream>
#include <vector>

// a += b * (10^k);를 구현한다.
void addTo(std::vector<int>& a, const std::vector<int>& b, int k);

// a -= b;를 구현한다. a >= b를 가정한다.
void subFrom(std::vector<int>& a, const std::vector<int>& b);

// 두 긴 정수의 곱을 반환한다.
std::vector<int> karatsuba(const std::vector<int>& a, const std::vector<int>& b) {
    int an = a.size(), bn = b.size();

    // a가 b보다 짧은 경우 둘을 바꾼다.
    if (an < bn) return karatsuba(b, a);

    // 기저 사례: a나 b가 비어 있는 경우
    if (an == 0 || bn == 0) return std::vector<int>();
    // 기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셉으로 변경한다.
    if (an <= 50) return multiply(a, b);

    int half = an / 2;
    // a와 b를 밑에서 half 자리와 나머지로 분리한다.
    std::vector<int> a0(a.begin(), a.begin() + half);
    std::vector<int> a1(a.begin() + half, a.end());
    std::vector<int> b0(b.begin(), b.begin() + std::min<int>(b.size(), half));
    std::vector<int> b1(b.begin() + std::min<int>(b.size(), half), b.end());

    // z2 = a1 * b1
    std::vector<int> z2 = karatsuba(a1, b1);
    // z0 = a0 * b0
    std::vector<int> z0 = karatsuba(a0, b0);
    // a0 = a0 + a1; b0 = b0 + b1
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    // z1 = (a0 * b0) - z0 - z2
    std::vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    std::vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, ret);
    addTo(ret, z2, half + half);
    return ret;
}