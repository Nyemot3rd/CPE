#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAX 5000000

bool cmp(long long a,long long b){return a>b;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long L[40],sum=0,*it=L;
		do scanf("%lld",it++); while(*(it-1)!=0);
		std::sort(L,it,cmp);
		while(it-->L){
			sum+=2*(long long)pow(*it,it-L+1);
			if(sum>MAX)break;
		}
		if(sum>MAX)printf("Too expensive\n");
		else printf("%lld\n",sum);
	}
}
