#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n;
	stack<string> name;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		if(s[0]=='S'){
			cin>>s;
			name.push(s);
		}else if(s[0]=='K'){
			if(!name.empty())
				name.pop();
		}else if(name.empty()){
			cout<<"Not in a dream\n";
		}else{
			cout<<name.top()<<'\n';
		}
	}
}
