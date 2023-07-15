#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	cin.ignore();
	for(int i=0;i<t;i++){
	    vector <int> ch(27,0);
	    string s;
	    getline(cin,s);
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='.'){
	            continue;
	        }
	        if(s[i]==' '){
	            if(ch[26]==1){
	                ch[26]=0;
	                s.erase(s.begin()+i);
	                --i;
	                continue;
	            }
	            ch[26]=1;
	        }
	        else if(int(s[i])-65<26){
	            if(ch[int(s[i])-65]==1){
	                ch[int(s[i])-65]=0;
	                s.erase(s.begin()+i);
	                --i;
	                continue;
	            }
	            ch[int(s[i])-65]=1;
	        }
	        else{
	            if(ch[int(s[i])-97]==1){
	                ch[int(s[i])-97]=0;
	                s.erase(s.begin()+i);
	                --i;
	                continue;
	            }
	            ch[int(s[i])-97]=1;
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}