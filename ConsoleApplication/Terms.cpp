/*#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

typedef map<string, int> terms;

terms term_union(terms &a, terms &b, int j){
	terms c = a;
	for (terms::iterator it = b.begin(); it != b.end(); it++){
		c[it->first] += j*it->second;
		if (!c[it->first])
			c.erase(it->first);
	}
	return c;
}

terms term_product(terms &a, terms &b){
	terms c;
	for (terms::iterator it1 = a.begin(); it1 != a.end(); it1++)
		for (terms::iterator it2 = b.begin(); it2 != b.end(); it2++){
			string s1 = it1->first;
			string s2 = it2->first;
			auto index1 = s1.find("/");
			string s1_up = s1;
			string s1_down = "";
			if (index1 != string::npos){
				s1_up = s1.substr(0, s1.find("/"));
				s1_down = s1.substr(s1.find("/") + 1, s1.length());
			}
			auto index2 = s2.find("/");
			string s2_up = s2;
			string s2_down = "";
			if (index2 != string::npos){
				s2_up = s2.substr(0, s2.find("/"));
				s2_down = s2.substr(s2.find("/") + 1, s2.length());
			}

			string s_up = s1_up + s2_up;
			string s_down = s1_down + s2_down;
			sort(s_up.begin(), s_up.end());
			sort(s_down.begin(), s_down.end());
			string s = s_up + "/" + s_down;
			
			c[s] += it1->second*it2->second;
			if (!c[s])
				c.erase(s);
		}
	return c;
}

terms term_div(terms &a, terms &b){
	terms c;
	for (terms::iterator it1 = a.begin(); it1 != a.end(); it1++)
		for (terms::iterator it2 = b.begin(); it2 != b.end(); it2++){
			string s1 = it1->first;
			string s2 = it2->first;
			auto index1 = s1.find("/");
			string s1_up = s1;
			string s1_down = "";
			if (index1 != string::npos){
				s1_up = s1.substr(0, s1.find("/"));
				s1_down = s1.substr(s1.find("/") + 1, s1.length());
			}
			auto index2 = s2.find("/");
			string s2_up = s2;
			string s2_down = "";
			if (index2 != string::npos){
				s2_up = s2.substr(0, s2.find("/"));
				s2_down = s2.substr(s2.find("/") + 1, s2.length());
			}
			
			string s_up = s1_up + s2_down;
			string s_down = s1_down + s2_up;
			sort(s_up.begin(), s_up.end());
			sort(s_down.begin(), s_down.end());
			string s = s_up + "/" + s_down;
			
			c[s] += it1->second*it2->second;
			if (!c[s])
				c.erase(s);
		}
	return c;
}

int in_val(char c){
	if (c == '+' || c == '-')	return 2;
	else if (c == '*' || c == '/')	return 4;
	else if (c == ')')	return 5;
	else if (c == '(')	return 0;
	else if (c == '#')	return -1;
	else return -2;
}

int out_val(char c){
	if (c == '+' || c == '-')	return 1;
	else if (c == '*' || c == '/')	return 3;
	else if (c == ')')	return 0;
	else if (c == '(')	return 5;
	else if (c == '#')	return -1;
	else return -2;
}

terms get_terms(string expr){
	expr += '#';
	remove_if(expr.begin(), expr.end(), isspace);

	terms Stack[100];
	int stop = -1;
	char Op[100] = "#";
	int optop = 0;

	int index = 0;
	while (optop >= 0){
		terms tmp;
		string s(1, expr[index]);
		if (isalpha(expr[index])){
			tmp[s] ++;
			Stack[++stop] = tmp;
			index++;
		}else if (isdigit(expr[index])){
			tmp[""] = expr[index] - '0';
			if(tmp[""] != 0)
				Stack[++stop] = tmp;
			index++;
		}else {
			if (in_val(Op[optop]) > out_val(expr[index])){
				if (Op[optop] == '+'){
					Stack[stop - 1] = term_union(Stack[stop - 1], Stack[stop], 1);
				}else if (Op[optop] == '-'){
					Stack[stop - 1] = term_union(Stack[stop - 1], Stack[stop], -1);
				}else if (Op[optop] == '*')
					Stack[stop - 1] = term_product(Stack[stop - 1], Stack[stop]);
				else if (Op[optop] == '/'){
					Stack[stop - 1] = term_div(Stack[stop - 1], Stack[stop]);
				}else {//if (Op[optop] == '#'){
					;
				}
				optop--;
				stop--;
			}else if(in_val(Op[optop]) == out_val(expr[index])){
				optop--;
				index++;
			}else{
				Op[++optop] = expr[index];
				index++;
			}
		}

	}
	return Stack[0];
}

void print(terms t){
	for (auto it : t)
		cout << it.first << " " << it.second << "\t";
	cout << endl;
}



int main(){
	int N;

	cin >> N;
	cin.ignore(1);
	string expr1, expr2;
	while (N--){
		getline(cin, expr1);
		getline(cin, expr2);
		
		terms term1 = get_terms(expr1);
		terms term2 = get_terms(expr2);
		print(term1);
		print(term2);
		cout << ((term1 == term2) ? "YES" : "NO") << endl;
	}
}*/