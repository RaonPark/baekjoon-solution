#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[15], result[15];
bool check[15] = { false };

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool checking() {
	int vo = 0, con = 0;
	for(int i=0; i<L; i++) {
		if(isVowel(result[i])) {
			vo++;
		} else {
			con++;
		}
	}
	
	return (con >= 2 && vo >= 1);
}

void backtracking(int cnt, char prev) {
	if(cnt == L && checking()) {
		for(int i=0; i<L; i++)
			cout << result[i];
		cout << '\n';
		return;
	}
	
	char last = 0;
	for(int i=0; i<C; i++) {
		if(!check[i] && last != arr[i] && prev <= arr[i]) {
			result[cnt] = arr[i];
			last = result[cnt];
			check[i] = true;
			backtracking(cnt + 1, last);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> L >> C;
	
	for(int i=0; i<C; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+C);
	
	backtracking(0, 0);
	
	return 0;
}
