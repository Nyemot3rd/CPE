#include<stdio.h>
int main(){
	for(int n,a[2],idx,ans=1,rising=scanf("%*d");scanf("%d%d",&n,&a[idx=0])==2;printf("%d\n",ans))
		for(ans=1,rising=0;--n&&scanf("%d",&a[idx^=1]);)
			if((rising?a[idx]>a[idx^1]:a[idx]<a[idx^1])&&ans++&&(rising^=1));
}
