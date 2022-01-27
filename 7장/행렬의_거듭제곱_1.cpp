// O(n) = lgn + lglgn + lglglgn + ~
// 자세하게 볼 필요 없음.

#include <iostream>

// 정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정하자.
class SquareMatrix;     // 정방행렬 = square matrix

// n*n 크기의 항등행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);

// 내 생각) class SquareMatrix의 nonmember function에 다음이 구현되어 있다.
SquareMatrix operator *(const SquareMatrix& a, const SquareMatrix& b);

// pow 함수의 결과값을 구하는데 도와주는 함수이다.
SquareMatrix powHelp(const SquareMatrix& A, int m, int& remainder) {
    // 추가된 매개변수: remainder
    // 의미: 시작할 때, remainder을 0으로 갖고있고
    //      홀수가 나오면, remainder을 1씩 더해준다.

    // 기저 사례: A^0 = I
    if (m == 0) return identity(A.size());

    if (m % 2 == 1) {
        remainder++;
        return powHelp(A, m-1, 1);
    }

    SquareMatrix half = powHelp(A, m / 2);
    // A^m = (A^(m/2)) * (A^(m/2))
    return half * half;
}

// A^m을 반환한다.
SquareMatrix pow(const SquareMatrix& A, int m) {
    int remainder = 0;

    SquareMatrix answer = powHelp(A, m, remainder);
    if (remainder == 0)
        return answer;
    
    int r = 0;
    return A * pow(A, remainder, r);
}