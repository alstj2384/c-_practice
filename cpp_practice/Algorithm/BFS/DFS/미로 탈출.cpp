#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[100][100];

//방향설정
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    //큐가 빌 때까지 반복
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //현재 위치에서 4가지 방향으로 위치를 확인
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //미로찾기가 공간을 벗어난 경우 무시
            if(nx<0 || nx>= n || ny < 0 || ny >= m) continue;
            if(graph[nx][ny] == 0) continue;
            if(graph[nx][ny] == 1){
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    return graph[n-1][m-1];
}
int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    cout << bfs(0,0) << '\n';


    return 0;
}