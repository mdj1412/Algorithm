#include <iostream>
#include <vector>

//int clocks[16] = {
//    3, 12, 6, 12,
//    12, 9, 3, 12,
//    3, 12, 6, 3,
//    12, 3, 12, 6
//};

std::vector<int> switchNumber[10] = {
    { 0, 1, 2 },
    { 3, 7, 9, 11 },
    { 4, 10, 14, 15 },
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15 },
    { 3, 14, 15 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 }
};

// type = 0, 1, 2, 3
void helpFunction(int* clock, int currentSwitch, int type) {
    std::size_t N = switchNumber[currentSwitch].size();
    for (int i=0;i<N;i++) {
        clock[switchNumber[currentSwitch][i]] += type * 3;
        
        if (clock[switchNumber[currentSwitch][i]] > 12)
            clock[switchNumber[currentSwitch][i]] -= 12;
        if (clock[switchNumber[currentSwitch][i]] <= 0)
            clock[switchNumber[currentSwitch][i]] += 12;
    }
}

// Exhaustive Search
bool recursiveFunction(int* clock, int currentSwitch, int& helpCount) {
    bool finish = true;
    
    for (int i=0;i<16;i++)
        if (clock[i] != 12) {
            finish = false;
            break;
        }
    
    // base case
    if (finish) return true;
    if (currentSwitch == 16) return false;
    
    bool exist = false;     // 해가 존재하는지
    int min = 99999999;     // 최솟값
    for (int type=0; type<4; type++) {
        int ret = type;
        
        helpFunction(clock, currentSwitch, type);
        // 해가 존재하고 기존에 저장되어 있던 min보다 작으면 조건문 실행
        if (recursiveFunction(clock, currentSwitch+1, ret) && ret <= min) {
            min = ret;
            exist = true;
        }
        helpFunction(clock, currentSwitch, -type);
    }
    
    if (exist)
        helpCount += min;
    return exist;
}

int main(void) {
    int C;
    int clock[16];
    scanf("%d", &C);
    
    for (int i=0;i<C;i++) {
        int count = 0;
        
        for (int j=0;j<16;j++)
            scanf("%d", &clock[j]);
        
        if (recursiveFunction(clock, 0, count))
            printf("%d\n", count);
        else
            printf("%d", -1);
    }
    
    return 0;
}

//2
//12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
//12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
