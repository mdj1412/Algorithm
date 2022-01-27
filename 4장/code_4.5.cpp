#include <iostream>
#include <vector>

// 코드 4.5 음식 메뉴 정하기

const int INF = 987654321;

// 이 메뉴로 모두가 식사할 수 있는지 여부를 반환
bool canEverybodyEat(const std::vector<int>& menu);

int M;      // 요리할 수 있는 음식의 종류 수

// food 번째 음식을 만들지 여부를 결정
int selectMenu(std::vector<int>& menu, int food) {
    // 기저 사례: 모든 음식에 대해 만들지 여부를 결정했을 때
    if (food == M) {
        if (canEverybodyEat(menu)) { return menu.size(); }
        return INF;
    }

    // 이 음식을 만들지 않는 경우의 답을 계산
    int ret = selectMenu(menu, food+1);

    // 이 음식을 만드는 경우의 답을 계산해서 더 작은 것을 취한다.
    menu.push_back(food);
    ret = std::min(ret, selectMenu(menu, food+1));
    menu.pop_back();
    return ret;
}