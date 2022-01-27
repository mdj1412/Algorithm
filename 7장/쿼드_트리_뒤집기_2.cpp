#include <iostream>
#include <vector>
#include <string>

// 내 생각) O(n) = n
// 아쉬운 점) 1. std::string::iterator를 이용안함
//          2. 반환값을 활용해보자 => std::string

// 주어진 s를 문제에서 원하는 방식으로 help에 저장
void recursiveF(std::string& s, std::string& help) {
    // base case
    if (strchr("x", s[0]) == NULL) {
        help.push_back(s[0]);
        s.erase(s.begin());
        return;
    }
    
    // 위에 두 칸을 임시로 저장하기 위해 만든 변수
    std::string subHelp;
    
    // 'x' 저장
    help.push_back(s[0]);
    s.erase(s.begin());
    
    // 위에 두 칸을 먼저 실행해서 다른 곳에 저장해두기
    for (int i=0;i<2;i++)
        recursiveF(s, subHelp);
    
    // 아래 두 칸을 실행해서 저장한 이후 위에 두 칸을 붙여둔다
    for (int i=2;i<4;i++)
        recursiveF(s, help);
    help.append(subHelp);
}

int main(void) {
    int C;
    std::string s;
    scanf("%d", &C);
    std::cin.ignore();
    
    for (int i=0;i<C;i++) {
        std::string help;
        getline(std::cin, s);   // std::cin >> s;
        recursiveF(s, help);
        printf("%s\n", help.c_str());
    }
    return 0;
}



//w
//xbwwb
//xbwxwbbwb
//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb