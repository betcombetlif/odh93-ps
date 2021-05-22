#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
해당 좌표의 방문 여부를 2차원 bool배열로 기록,
1. 방문한적 없는 좌표에 가면 dfs시작하면서 number_of_area + 1 
2. 현재 위치의 상하좌우 중에 dfs를 시작할 때의 picture값과 같으면 dfs 다음단계로 이동
3. dfs 진행시마다 max_size_of_one_area와 비교, 가장 큰 영역의 값을 갱신해준다.
함수 매개 변수로 사용되는 참조는 const일 수 있다. 이렇게 하면 복사본을 만들지 않고 인수에 접근할 수 있으며, 함수는 참조되는 값을 변경하지 못한다. -> const & 를 사용해서 시간을 줄인 원리
*/
int num_area=0;
int max_area=0;
int M,N;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
bool check[101][101];
int dfs(int y,int x,int num,const vector<vector<int>> &picture){
    check[y][x] = true;
    int cnt = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && nx>=0 && ny<M && nx<N && !check[ny][nx]){
            if(picture[ny][nx]!=num)
                continue;
            cnt += dfs(ny,nx,num,picture);
        }
    }
    return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m, N=n;
    num_area = 0, max_area = 0;
    memset(check,0,sizeof(check));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j] && picture[i][j] > 0){
                num_area+= 1;
                max_area = max(max_area,dfs(i,j,picture[i][j],picture));
            }
        }
    }
    vector<int> answer(2);
    answer[0] = num_area;
    answer[1] = max_area;
    return answer;
}
