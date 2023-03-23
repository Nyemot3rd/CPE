#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	vector<string> name;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		if(s[0]=='S'&&cin>>s){
			name.push_back(s);
		}else if(s[0]=='K'){
			if(!name.empty())name.pop_back();
		}else if(name.empty()){
			cout<<"Not in a dream\n";
		}else{
			cout<<name.back()<<'\n';
		}
	}
}
