// 코드 6.8 시계 맞추기 문제를 해결하는 완전 탐색 알고리즘

#include <vector>

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] = 'x': i번 스위치와 j번 시계가 연결되어 있다.
// linked[i][j] = '.': i번 스위치와 j번 시계가 연결되어 있지 않다.
const char linked[SWITCHES][CLOCKS+1] = {
    // 123456789012345
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."};

// 모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const std::vector<int> clocks);

// swtch번 스위치를 누른다.
void push(std::vector<int>& clocks, int swtch) {
    for (int clock = 0; clock < CLOCKS; ++clock)
        if (linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if (clocks[clock] == 15) clocks[clock] = 3;
        }
}

// clocks: 현재 시계들의 상태
// swtch: 이번에 누를 스위치의 번호
// 가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다.
// 만약 불가능하다면 INF 이상의 큰 수를 반환한다.
int slove(std::vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

    // 이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ret = std::min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    // push(clocks, swtch)가 네 번 호출되었으니 clocks는 원래와 같은 경우가 된다.
    return ret;
}

// 느낀 점) slove 함수에서 마지막 for문을 주의 깊게 보자.
//        나는 시계 바늘을 옮겨주고 다시 원상태로 복귀시키고를 반복했었다.
//        그럴 필요없이 검사하고 한 칸 옮기고(세 시간)를 반복하면 더 효율적이다.
//
//        switch click = 0 -> 세 시간 이동 -> swtch click = 1
//        -> 세 시간 이동 -> switch click = 2 -> 세 시간 이동
//        -> switch = 3 -> 세 시간 이동 -> 원 상태로 복귀 + 재귀 종료