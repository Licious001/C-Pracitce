#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

bool isOperator(char c){
	if (c == '+' || c == '-')	return 1;
	else if (c == '*' || c == '/' || c == '%')	return 1;
	else if (c == ')')	return 1;
	else if (c == '(')	return 1;
	else return false;
}

vector<Term> createTerms(string s){
	
	vector<Term> result;
	string temp_pre = "";
	int type_pre = -1;
	
	for (int i = 0; i < s.size(); i++){
		
		if (isdigit(s[i])){
			if (temp_pre == ""){
				temp_pre += s[i];
				type_pre = 0;
			}
			else{
				
			}
		}
		else if(isOperator(s[i])){
			
		}
		else{
			if (type == -1){
				type = 0;
				continue;
			}
			//Term t(1, s[i]);
		}
	}
	return result;
}
struct Term{
	int type;   //0->num 1->op, 2->var
	union {
		int num;
		char op;
		char var[10];
	}val;
	Term(int t, string s){
		if (t == 0){
		}
		else if (t == 1){
		}
		else{
		}
	}
};




int main(){
	vector<Term> expr1;
	vector<Term> expr2;
	
	string s1;
	cin >> s1;
	expr1 = createTerms(s1);
	
	return 0;
}