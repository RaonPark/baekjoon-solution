#include <bits/stdc++.h>
using namespace std;

int N, arr[500010];

int main() {
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    
    stack<int> st;
    for(int i=1; i<=N; i++) {
        bool flag = false;
        while(!st.empty()) {
            int idx = st.top(); st.pop();
            if(arr[idx] > arr[i]) {
                printf("%d ", idx);
                st.push(idx);
                flag = true;
                break;
            }
        }
        
        if(!flag && st.empty()) {
            printf("0 ");
        }
        
        st.push(i);
    }
    
    return 0;
}
