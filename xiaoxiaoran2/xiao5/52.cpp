#include<bits/stdc++.h>
using namespace std;
int main(){
	map<char, int> m;
	int i, j;
	char G[15], a, b;
	scanf("%d %d",&i,&j);
	getchar();
	scanf("%s",G);
	getchar();
	while(j--) {
		scanf("%c%c",&a,&b);
		getchar();
		m[a]++;
		m[b]++;
	}
	cout<<m[G[0]];
	for(int k = 1; k < i; k++)
		cout<<' '<<m[G[k]];
	return 0;
}
/*
5 7
ABCDE
AB
AD
BC
BE
CD
CE
DE
*/
