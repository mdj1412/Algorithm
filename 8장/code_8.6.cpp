// 1. s[pos]와 w[pos]가 대응되지 않는다.
//      : 볼 것도 없이 대응 실패라는 것을 알 수 있다.
// 2. w 끝에 도달한다.
//      : 패턴에 *이 하나도 없는 경우이다. 이 경우에 패턴과 문자열의 길이가 정확히 같아야만 패턴과 문자열이 대응된다고 할 수 있다.
// 3. s 끝에 도달한다.
//      : 패턴은 남았지만 문자열이 이미 끝난 경우이다. 당연히 대응 실패라고 생각할 수 있지만,
//        남은 패턴이 전부 *로 구성되어 있다면 사실 두 문자열은 대응될 수 있다. 이 경우를 제외하고는 답은 항상 거짓이다.
// 4. w[pos]가 *인 경우
//      : *가 몇 글자에 대응될지 모르기 때문에, 0글자부터 남은 문자열의 길이까지를 순회하며 모든 가능성을 검사한다.
//        이때 w의 pos+1 이후를 패턴 w'으로 하고, s의 pos+skip 이후를 문자열 s'로 해서 match(w', s')로
//        재귀 호출했을 때 답이 하나라도 참이면 답은 참이 된다.

#include <iostream>
#include <string>

// 코드 8.6 와일드카드 문제를 해결하는 완전 탐색 알고리즘

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const std::string& w, const std::string& s) {
    // w[pos]와 s[pos]를 맞춰나간다.
    int pos = 0;
    while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;
    
    // 더 이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 대응됨
    if (pos == w.size())
        return pos == s.size();
    // 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if (w[pos] == '*')
        for (int skip = 0; pos+skip <= s.size(); ++skip)
            if (match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
    // 이 외이 경우에는 모두 대응되지 않는다.
    return false;
}