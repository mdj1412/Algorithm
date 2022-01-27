// 아쉬운 부분 찾기 !
// 내 생각) 시간 복잡도 O(n) = n^3


#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

int cache[101][101];

int match(const std::string& W, const std::string& s) {
    // base case
    if ((W.size() == 0) && (s.size() == 0))
        return 1;
    else if ((W.size() == 0) || (s.size() == 0))
        return 0;
    
    // 메모이제이션 ( memoization )
    int& ret = cache[W.size()][s.size()];
    if (ret != -1) return ret;
    
    char headW = W[0];
    if (headW != '*') {
        if ((headW == '?') || (headW == s[0]))
            return ret = match(W.substr(1), s.substr(1));
        return 0;
    }
    
    // headW == '*'일 경우
    ret = 0;
    for (int i=0;i<=s.size();i++) {
        ret = ret | match(W.substr(1), s.substr(i));
        if (ret) break;
    }
    
    return ret;
}



int main(void) {
    int C;
    std::cin >> C;
    
    for (int i=0;i<C;i++) {
        std::string W;
        
        std::cout << i+1 << "번 째 문자 : ";
        std::cin >> W;
        std::cout << "횟수 : ";
        int n;
        std::cin >> n;
        for (int j=0;j<n;j++) {
            std::string s;
            std::cin >> s;
            
            for (int k=0;k<101;k++)
                memset(cache[k], -1, 101);
            
            if (match(W, s) == 1)
                std::cout << s << std::endl;
            else
                std::cout << "결과 없음" << std::endl;
        }
        
    }
    
    return 0;
}


//100
//he?p
//3
//help
//heap
//helpp
//*p*
//4
//hp
//help
//papa
//hello
//*bb*
//1
//babbbc
//1
//******a
//aaaaaaaaaab
//??
//3
//a
//aa
//aaa




// 아쉬운 이유)
//        1. 한 문자를 검사할 때마다 재귀를 호출하지말고
//           *가 아닐 때 while문으로 최대한 검사하고
//           *가 나올 때마다 재귀를 호출하면 더 빠르다
//           부분 문제를 *가 나타날 때마다 호출하는 것이다.
//
//        2. 반복문으로 재귀를 호출하지말고 다른 방법을 생각해보자.
//           힌트) 기존 코드에서는 문자를 0개 넘길 때, 1개 넘길 때, 2개 넘길 때, ...
//                였지만,
//                문자를 자를 때와 자르지 않을 때로 구별하자.
