#include <iostream>

const int coverType[4][3][2] = {
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};
bool check[30][30];
int H, W;

bool inRange(int y, int x) {
    return (-1 < y) && (y < H) && (-1 < x) && (x < W);
}

int cover(int startY, int startX) {
    bool finish = true;
    int remainY, remainX;
    
    for (remainY = startY; remainY<H; remainY++) {
        for (remainX = 0; remainX<W; remainX++)
            if (check[remainY][remainX]) {
                finish = false; break;
            }
        if (!finish)
            break;
    }
    
    if (finish)
        return 1;
    
    int ret = 0;
    for (int i=0;i<4;i++) {
        bool ok = true;
        int ny, nx;
        
        for (int j=1;j<3;j++) {
            ny = remainY + coverType[i][j][0];
            nx = remainX + coverType[i][j][1];
            
            if (inRange(ny, nx) && check[ny][nx])
                continue;
            else
                ok = false; break;
        }
        
        if (ok) {
            for (int j=0;j<3;j++) {
                ny = remainY + coverType[i][j][0];
                nx = remainX + coverType[i][j][1];
                
                check[ny][nx] = false;
            }
            
            ret += cover(remainY, remainX);
            
            for (int j=0;j<3;j++) {
                ny = remainY + coverType[i][j][0];
                nx = remainX + coverType[i][j][1];
                
                check[ny][nx] = true;
            }
        }
    }
    
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
            printf("%d\n", cover(0, 0));
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