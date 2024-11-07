#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[201];
int robot[101];
int r_offset = 0;

int check_zeros() {
    int zeros = 0;
    for(int i=0; i<2*N; i++) {
        if(A[i] == 0)
            zeros++;
    }
    
    return zeros;
}

void check_offset() {
    for(int i=0; i<N; i++) {
        if(robot[i] == 1)
            r_offset = i;
    }
}

void move_convey() {
    int temp = A[2 * N - 1];
    for(int i=2*N-1; i>0; i--) {
        A[i] = A[i-1];
    }
    A[0] = temp;
    
    for(int i=r_offset; i>=0; i--) {
        if(!robot[i]) continue;
        
        if(i + 1 < N - 1)
            robot[i+1] = robot[i];
        robot[i] = 0;
    }
    
    check_offset();
}

void move_if_allow() {
    for(int i=r_offset; i>=0; i--) {
        // 그 자리에 로봇이 있다면
        // 그 다음 칸에 로봇이 없고 
        // 그 다음 칸이 내구도가 0이 아니어야한다.
        if(robot[i] && !robot[i+1] && A[i+1] != 0) {
            if(i + 1 < N - 1)
                robot[i + 1] = 1;
            robot[i] = 0;
            A[i+1]--;
        }
    }
}

void print_robot() {
    for(int i=0; i<N; i++) {
        printf("%d ", robot[i]);
    }
    printf("\n");
}

void print_convey() {
    for(int i=0; i<2*N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int solution() {
    int rounds = 0;
    while(true) {
        if(check_zeros() >= K)
            break;
        check_offset();
        
        // 먼저 칸이 움직이면서 로봇도 같이 움직인다. 2N은 1로 간다.
        // N에서 로봇은 내린다. 
        move_convey();
        // 로봇이 더 갈 수 없다면 움직이지 말아야한다.
        move_if_allow();

        // 1번 칸에서 로봇은 탄다.
        if(A[0] != 0) {
            robot[0] = 1;
            A[0]--;
        }
        
        rounds++;
        // print_robot();
        // print_convey();
    }
    
    return rounds;
}

int main() {
    scanf("%d %d", &N, &K);
    
    for(int i=0; i<2*N; i++) {
        scanf("%d", &A[i]);
    }
    
    int rounds = solution();
    printf("%d\n", rounds);
}
