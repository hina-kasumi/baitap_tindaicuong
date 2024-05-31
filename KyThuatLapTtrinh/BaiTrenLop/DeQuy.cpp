#include<stdio.h>
int step = 0;

void solve(int n, char a, char b, char c){
	if(n < 1)
		return;
	solve(n - 1, a, c, b);
	step++;
	printf("%d: %c -> %c\n",step, a, c);
	solve(n - 1, b, a, c);
}


int main(){
    int n;
	scanf("%d", &n);
	solve(n, 'a', 'b', 'c');
}