#include<stdio.h>

int main(){
	int not_prime[105]={1,1},prime[26]={},n=0;
	for(int i=2;i<=11;++i)if(!not_prime[i])for(int j=i*i;j<105;j+=i)not_prime[j]=1;//sieve
	for(int i=0;i<105;++i)if(!not_prime[i])prime[n++]=i;//prime array
	int a[101][101]={};//ans[i] = answer for n=i
	for(int i=2;i<=100;++i){
		for(int *j=prime;*j<=i;++j)
			a[i][*j]=a[i-1][*j];
		for(int *j=prime,tmp=i;*j<=i;++j)
			while(tmp%*j==0){
				a[i][*j]++;
				tmp/=*j;
			}
	}
	while(scanf("%d",&n)&&n){
		printf("%3d! =",n);
		for(int *j=prime;*j<=n;++j){
			if(j-prime==15)
				printf("\n      ");
			printf("%3d",a[n][*j]);
		}
		printf("\n");
	}
}
