// 내 생각) 시간 복잡도 O(n) = n^2
// 느낀점) 처음에 if문이 복잡하더라도 기준을 잘 잡고 분류해서
//       정리하는 연습을 하기
// 아쉬운점) 재귀를 호출할 때마다 매번 문자열 객체를 생성해야된다.


#include <iostream>
#include <string>
#include <memory.h>

int cache[101][101];

int match(const std::string& W, const std::string& s) {
    // 메모이제이션 ( memoization )
    int& ret = cache[W.size()][s.size()];
    if (ret != -1) return ret;
    
    // base case
    if ((W.size() != 0) && (s.size() != 0) && ((W[0] == s[0]) || (W[0] == '?')))
        ret = match(W.substr(1), s.substr(1));
    
    else if (W.size() == 0)
        ret = (s.size() == 0);
    
    else if (W[0] == '*') {
        if (s.size() != 0)
            ret = match(W.substr(1), s) || match(W, s.substr(1));
        else
            ret = match(W.substr(1), s);
    }
    
    // 나머지 경우는 어떤 경우일까?
    // (s.size() == 0) && (W[0] != '*')
    // (s.size() != 0) && ((W[0] != s[0]) && (W[0] != '?'))
    else
        ret = 0;
    
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
                memset(cache+k, -1, 101);
            
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
