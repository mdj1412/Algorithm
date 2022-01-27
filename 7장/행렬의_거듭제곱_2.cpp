// 내 생각) divide and conquer + dynamic programming
// 내 생각) O(n) = lgn

#include <iostream>
#include <vector>

// 정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정하자.
class SquareMatrix;     // 정방행렬 = square matrix

// n*n 크기의 항등행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);

// 내 생각) class SquareMatrix의 nonmember function에 다음이 구현되어 있다.
SquareMatrix operator *(const SquareMatrix& a, const SquareMatrix& b);

// A^m을 반환한다.
// help = 값을 구하면 동적으로 저장해주는 변수
SquareMatrix pow(const SquareMatrix& A, int m, std::vector<SquareMatrix>& help) {
    SquareMatrix a1, a2;
    SquareMatrix I = identity(m);

    // base case
    if (m == 0) return 1;

    // A^m = A^(m-half) + A^half (= a1 * a2)
    int half = m / 2;

    // 함수가 처음 시작할 때 => help가 빈 공간이라고 가정하자.
    // 이때 크기를 설정해준다.
    if (help.size() == 0)
        help.resize(half+2, I);

    // divide and conquer(분할 정복) -> 재귀 시작
    a1 = pow(A, m-half, help);
    if (help[m-half] != I)
        help[m-half] = a1;
    a2 = pow(A, half, help);
    if (help[half] != I)
        help[half] = a2;
    
    return a1 * a2;
}