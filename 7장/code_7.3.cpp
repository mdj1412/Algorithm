// 코드 7.3 두 큰 수를 곱하는 O(n^2) 시간 알고리즘

#include <iostream>
#include <vector>

// num[]의 자릿수 오림을 처리한다.
void mormalize(std::vector<int>& num) {
    num.push_back(0);
    
    // 자릿수 올림을 처리한다.
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back()) num.pop_back();
}


// 두 긴 자연수의 곱을 반환한다.
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
// 예: multiply([3, 2, 1], [6, 5, 4]) = 123 * 456 = 56088 = [8, 8, 0, 6, 5]
std::vector<int> multiply(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            c[i+j] += a[i] * b[j];
    mormalize(c);

    return c;
}



// 인상적인 점)
// mormalize 함수에서
//              1. 시작하자마자 num.push_back(0)을 하는 이유
//                  내 생각) 카라츠바 코드의 addTo 함수에서 이용하기 위해서
//              2. if 문에서 음수를 따로 빼는 이유
//                  내 생각) 카라츠바 코드의 subFrom 함수에서 이용하기 위해서
//              3. borrow를 그렇게 설정한 이유
//                  내 생각) 가우스를 이용하면 쉽게 구할 수 있다.     
//              4. 마지막에 while문을 집어넣은 이유
//                  내 생각) multiply 함수에서 반환값 c를 설정할 때, 
//                         크기를 a.size() + b.size() + 1로 설정했다.
//                         즉, 최대로 설정 했으므로 필요없는 부분을 지우는 것이다.
//
// multiply 함수에서 
//              자리 수를 이렇게 설정한 이유 => " a.size() + b.size() + 1 "
//                  내 생각) m자리수 최대 -> 10^(m+1)-1
//                         n자리수 최대 -> 10^(n+1)-1
//                         두 수를 곱한 자리수 최대 -> m + n + 2 - 1
