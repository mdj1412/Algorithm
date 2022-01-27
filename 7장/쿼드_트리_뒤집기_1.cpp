#include <iostream>
#include <vector>
#include <string>

// 내 생각) O(n) = n
// 내 생각) 사실 이 코드에서 내가 만든 save함수와 printing 함수를 합칠 수 있다.\
// 아쉬운 점) 1. std::string::iterator를 이용안함
//          2. 메모리를 사용하는데 비효율적이다
//          3. 반환값을 활용해보자 => std::string


class help {
public:
    // 4칸으로 분할 했을 때, 각각의 칸들이 같은 색으로 구성되어 있을 때 false, 아니면 true
    bool isX;
    // isX가 true이면 4개, false이면, 0개
    // 내 생각) queue or 배열로 생각해도됨
    std::vector<help> subhelp;
    // isX가 true이면 저장되어 있지 않고, true이면 b 또는 w로 저장되어 있다.
    char notX;
};

// 문자열을 자료구조 help방식으로 저장
void save(std::string& s, help& h) {
    // base case: 모든 픽셀이 같은 색일 경우
    if (strchr("x", s[0]) == NULL) {
        h.isX = false;
        h.notX = s[0];
        s.erase(s.begin());
        return;
    }
    
    // 모든 픽셀이 같은 색이 아닐경우
    h.isX = true; h.subhelp.resize(4);
    s.erase(s.begin());
    for (int i=0;i<4;i++)
        save(s, h.subhelp[i]);
}

void printing(const help& h) {
    // base case: 모든 픽셀이 같은 색일 경우
    if (!h.isX) {
        printf("%c", h.notX);
        return;
    }
    
    // 모든 픽셀이 같은 색이 아닐경우 아래 두 칸 출력 후 위에 두 칸 출력
    printf("x");
    for (int i=2;i<4;i++)
        printing(h.subhelp[i]);
    for (int i=0;i<2;i++)
        printing(h.subhelp[i]);
}




int main(void) {
    int C;
    std::string s;
    scanf("%d", &C);
    std::cin.ignore();
    
    for (int i=0;i<C;i++) {
        help h;
        getline(std::cin, s);   // std::cin >> s;
        save(s, h);
        printing(h);
        printf("\n");
    }
    return 0;
}



//w
//xbwwb
//xbwxwbbwb
//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
