#include <iostream>
#include <vector>
#include <memory.h>


// 내 생각) 시간 복잡도 O(n) = n^2
// help 의미 : 바로 앞의 index (만약, 앞이 없으면 -1)
//
// help == -1 : x번째부터 재귀 시작
// help != -1 : 1. ls[help] >= ls[x]
//                  -> 다음 index로 재귀 호출
//              2. ls[help] < ls[x]
//                  1) x번째를 포함하지 않는 경우
//                  2) x번째를 포함시키는 경우

std::vector<int> ls;
int cache[100];
int M = 0;

int recursive(int x, int help) {
    // base case
    if (x == ls.size()) return 0;
    
    // memoization
    int& ret = cache[x];
    
    if (help == -1) {
        if (ret != -1)
            return ret;
        return ret = recursive(x+1, x) + 1;
    }
    
    if (ls[help] >= ls[x])
        return recursive(x+1, help);
    
    else if (ret != -1)
        return ret;
    
    else {
        int a = recursive(x+1, help);
        ret = recursive(x+1, x) + 1;
        return std::max<int>(a, ret);
    }
}

int main(void) {
    M = 0; ls.clear();
    std::memset(cache, -1, 100);
    
    ls.push_back(2);
    ls.push_back(1);
    ls.push_back(5);
    ls.push_back(2);
    ls.push_back(4);
    ls.push_back(7);
    recursive(0, -1);
    for (int i=0;i<100;i++) {
        M = (cache[i] > M) ? cache[i] : M;
    }
    std::cout << "M : " << M << std::endl;
    
    M = 0; ls.clear();
    std::memset(cache, -1, 100);
    
    ls.push_back(1);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(2);
    ls.push_back(4);
    recursive(0, -1);
    for (int i=0;i<100;i++) {
        M = (cache[i] > M) ? cache[i] : M;
    }
    std::cout << "M : " << M << std::endl;
    
    M = 0; ls.clear();
    std::memset(cache, -1, 100);
    
    ls.push_back(2);
    ls.push_back(1);
    ls.push_back(5);
    ls.push_back(2);
    ls.push_back(4);
    ls.push_back(7);
    recursive(0, -1);
    for (int i=0;i<100;i++) {
        M = (cache[i] > M) ? cache[i] : M;
    }
    std::cout << "M : " << M << std::endl;
    
    M = 0; ls.clear();
    std::memset(cache, -1, 100);
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    ls.push_back(1);
    recursive(0, -1);
    for (int i=0;i<100;i++) {
        M = (cache[i] > M) ? cache[i] : M;
    }
    std::cout << "M : " << M << std::endl;
    return 0;
}