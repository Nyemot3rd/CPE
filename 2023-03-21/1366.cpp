#include<stdio.h>

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)&&n&&m){
		int a[n+1][m]={},b[n+1][m]={};
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&b[i][j]);
		for(int i=1;i<=n;++i)
			for(int j=0;j<m;++j){
				scanf("%d",&a[i][j]);
				a[i][j]+=a[i-1][j];
			}
		for(int i=n;i>0;--i)
			for(int j=0;j<m;++j)
				b[i-1][j]+=b[i][j];
		for(int i=0;i<=n;++i)
			for(int j=0;j<m;++j)
				a[i][j]+=b[i][j];
		for(int j=1;j<m;++j){
			int max=0;
			for(int i=0;i<=n;++i){
				max=max>a[i][j-1]?max:a[i][j-1];
				a[i][j]=a[i][j]+max;
			}
		}
		int ans=0;
		for(int i=0;i<=n;++i)
			ans=ans>a[i][m-1]?ans:a[i][m-1];
		printf("%d\n",ans);
	}
}
