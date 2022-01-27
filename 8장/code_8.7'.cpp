// 코드 8.7' 와일드카드 문제를 해결하는 동적 계획법 알고리즘
// 시간 복잡도) O(n) = n^2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

// -1은 아직 답이 계산되지 않았음을 의미한다.
// 1은 해당 입력들이 서로 대응됨을 의미한다.
// 0은 해당 입력들이 서로 대응되지 않음을 의미한다.
int cache[101][101];

// 패턴과 문자열
std::string W, S;

// 와일드카드 패턴 W[w..]가 문자열 S[s..]에 대응되는지 여부를 반환한다.
bool matchMemoized(int w, int s) {
    // 메모이제이션
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    // 패턴과 문자열의 첫 한 글자씩을 떼고 이들이 서로 대응되는지를 재귀 호출로 확인
    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = matchMemoized(w+1, s+1);

    // 더 이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 참
    if (w == W.size()) return ret = (s == S.size());

    // 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if (W[w] == '*')
        if (matchMemoized(w+1, s) || (s < S.size() && matchMemoized(w, s+1)))
            return ret = 1;
            
    // 3. 이 외이 경우에는 모두 대응되지 않는다.
    return ret = 0;
}



int main(void) {
    int C;
    std::cin >> C;
    
    for (int i=0;i<C;i++) {
        std::vector<std::string> p;
        
        std::cout << i+1 << "번 째 문자 : ";
        std::cin >> W;
        std::cout << "횟수 : ";
        int n;
        std::cin >> n;
        for (int j=0;j<n;j++) {
            std::cin >> S;
            
            for (int k=0;k<W.size()+1;k++)
                memset(cache+k, -1, S.size()+1);
            
            if (matchMemoized(0, 0))
                p.push_back(S);
//            else
//                std::cout << "결과 없음" << std::endl;
        }
        
        std::cout << "-----------------" << std::endl;
        // 알파벳 순서대로 출력
        std::sort(p.begin(), p.end());
        for (int j=0;j<p.size();j++) {
            std::cout << p[j] << std::endl;
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
