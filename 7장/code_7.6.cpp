// 코드 7.6 쿼드 트리 뒤집기 문제를 해결하는 분할 정복 알고리즘

#include <iostream>
#include <string>

std::string reverse(std::string::iterator& it) {
    char head = *it;
    ++it;
    if ((head == 'b') || (head == 'w'))
        return std::string(1, head);
    
    std::string upperLeft = reverse(it);
    std::string upperRight = reverse(it);
    std::string lowerLeft = reverse(it);
    std::string lowerRight = reverse(it);

    // 각각 위와 아래 조각들의 위치를 바꾼다.
    return std::string('x') + lowerLeft + lowerRight + upperLeft + upperRight;
}


// 의문점) 교재 p.194에서 시간 복잡도 분석을 할 때,
//       O(n) = n 이라고 한다.
//       하지만 내 생각에는 O(n) = n*n 인 것 같다.
//
// 해결)  O(n) = n 맞음.
//       string의 덧셈을 생각해보자