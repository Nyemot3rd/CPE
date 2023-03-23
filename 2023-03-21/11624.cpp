#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

int main(){
	int t;
	char m[1001][1001];//maze
	pair<int,int> move[4]={{1,0},{-1,0},{0,1},{0,-1}};
	scanf("%d",&t);
	while(t--){
		int r,c;
		queue<pair<int,int>> joe, fire;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;++i){
			scanf("%*c");
			for(int j=0;j<c;++j){
				scanf("%c",&m[i][j]);
				if(m[i][j]=='F')
					fire.push(pair<int,int>(i,j));
				else if(joe.empty()&&m[i][j]=='J')
					joe.push(pair<int,int>(i,j));
			}
		}
		int ans=0;
		bool outside=false;
		while(!outside){
			int size=fire.size();
			while(size--){
				pair<int,int> x=fire.front();
				fire.pop();
				for(int i=0;i<4;++i){
					int v=x.first+move[i].first,h=x.second+move[i].second;
					if(m[v][h]=='.'||m[v][h]=='J'){
						m[v][h]='F';
						fire.push(pair<int,int>(v,h));
					}
				}
			}
			ans++;
			size=joe.size();
			if(!size)break;
			while(size--){
				pair<int,int> x=joe.front();
				if((x.first==0||x.first==r-1||x.second==0||x.second==c-1)){
					outside=1;
					break;
				}
				joe.pop();
				for(int i=0;i<4;++i){
					int v=x.first+move[i].first,h=x.second+move[i].second;
					if(m[v][h]=='.'){
						m[v][h]='J';
						joe.push(pair<int,int>(v,h));
					}
				}
			}
		}
		if(outside)printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
}
