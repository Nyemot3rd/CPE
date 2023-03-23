#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,prev,now,ans=1,rising=0;
		scanf("%d%d",&n,&prev);
		while(--n){
			scanf("%d",&now);
			if(rising?now>prev:now<prev){
				ans++;
				rising^=1;
			}
			prev=now;
		}
		printf("%d\n",ans);
	}
}
