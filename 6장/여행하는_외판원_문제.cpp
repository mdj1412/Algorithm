#include <iostream>
#include <vector>

int n;
double dist[MAX][MAX];

double shortestPath(std::vector<double>& path, std::vector<bool>& visited, double currentLength) {
    double length, ret = 999999999;
    
    if (path.size() == n)
        return currentLength + dist[path.back()][path[0]];
    
    for ( int i=0; i<n; i++ ) {
        if (!visited[i]) {
            int here = path.back();
            visited[i] = true; path.push_back(i);
            length = dist[here][i] + shortestPath(path, visited, currentLength);
            visited[i] = false; path.pop_back();
            ret = (ret < length) ? ret : length;
        }
    }
    
    // 사실상 필요없음
    if (ret == 999999999)
        return currentLength;
    else
        return currentLength + ret;
}