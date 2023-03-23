#include<stdio.h>

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)&&(a||b)){
		int count=0,carry=0;
		do
			if(carry=a%10+b%10+carry>=10)
				count++;
		while((a/=10)|(b/=10));
		if(!count)printf("No carry operation.\n");
		else if(count==1)printf("1 carry operation.\n");
		else printf("%d carry operations.\n",count);
	}
}
