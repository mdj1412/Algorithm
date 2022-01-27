#include <iostream>

bool check[30][30];
int H, W;

bool inRange(int y, int x) {
    return (-1 < y) && (y < H) && (-1 < x) && (x < W);
}

int cover(void) {
    int ret = 0, remainY = 0, remainX = 0;
    
    while (true) {
        if (remainY == H) {
            remainX = W;
            break;
        }
        if (remainX == W) {
            remainY++; remainX = 0;
            continue;
        }
        if (check[remainY][remainX])
            break;
        
        remainX++;
    }
    
    if ((remainY == H) && (remainX == W))
        return 1;
    
    check[remainY][remainX] = false;
    
    if (inRange(remainY, remainX+1) && inRange(remainY+1, remainX+1) && check[remainY][remainX+1] && check[remainY+1][remainX+1]) {
        check[remainY][remainX+1] = check[remainY+1][remainX+1] = false;
        ret += cover();
        check[remainY][remainX+1] = check[remainY+1][remainX+1] = true;
    }
    
    if (inRange(remainY+1, remainX) && inRange(remainY+1, remainX-1) && check[remainY+1][remainX] && check[remainY+1][remainX-1]) {
        check[remainY+1][remainX] = check[remainY+1][remainX-1] = false;
        ret += cover();
        check[remainY+1][remainX] = check[remainY+1][remainX-1] = true;
    }
    
    if (inRange(remainY+1, remainX) && inRange(remainY+1, remainX+1) && check[remainY+1][remainX] && check[remainY+1][remainX+1]) {
        check[remainY+1][remainX] = check[remainY+1][remainX+1] = false;
        ret += cover();
        check[remainY+1][remainX] = check[remainY+1][remainX+1] = true;
    }
    
    if (inRange(remainY, remainX+1) && inRange(remainY+1, remainX) && check[remainY][remainX+1] && check[remainY+1][remainX]) {
        check[remainY][remainX+1] = check[remainY+1][remainX] = false;
        ret += cover();
        check[remainY][remainX+1] = check[remainY+1][remainX] = true;
    }
    
    check[remainY][remainX] = true;
    
    return ret;
}

int main(void) {
    int C;
    scanf("%d", &C);
    
    for (int i=0;i<C;i++) {
        int count = 0;
        scanf("%d %d", &H, &W);
        
        for (int j=0;j<H;j++) {
            char* s;
            scanf("%s", s);
            for (int k=0;k<W;k++) {
                if (s[k] == '#')
                    check[j][k] = false;
                else if (s[k] == '.') {
                    check[j][k] = true;
                    count++;
                }
            }
        }
        
        if (count % 3 != 0)
            printf("%d\n", 0);
        else
            printf("%d\n", cover());
    }
}


//3
//3 7
//#.....#
//#.....#
//##...##
//3 7
//#.....#
//#.....#
//##..###
//8 10
//##########
//#........#
//#........#
//#........#
//#........#
//#........#
//#........#
//##########