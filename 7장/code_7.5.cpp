// 코드 7.5 쿼드 트리 압축을 해제하는 재귀 호출 알고리즘

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(std::string::iterator& it, int y, int x, int size) {
    // 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
    char head = *(it++);

    // 기저 사례: 첫 글자가 b 또는 w인 경우
    if ((head == 'b') || (head == 'w')) {
        for (int dy = 0; dy < size; ++dy)
            for (int dx = 0; dx < size; ++dx)
                decompressed[y+dy][x+dx] = head;
    }

    else {
        // 네 부분을 각각 순서대로 압축 해체한다.
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}

// 만약 쿼드 트리를 압축하면서 문제에서 원하는 방향으로 뒤집어질려면 위 코드에서
// else에 재귀 함수를 다음과 같이 수정하면 될까?

// decompress(it, y+half, x, half);
// decompress(it, y+half, x+half, half);
// decompress(it, y, x, half);
// decompress(it, y, x+half, half);