// Name        : leetcode.cpp
// Author      : Sadık EĞRİ
// Version     :
// Copyright   : Your copyright notice
// Description : Problems: https://leetcode.com/
//============================================================================
#include<iostream>
#include <vector> //vector lib enables push_back, pop_back, insert, erase funtions. useul for arrays;
#include<stack>
using namespace std;

class leetcode{
public:
	vector<int> two_sum(vector<int> numbers,int target){

		vector<int> res;
		int i,j;
		int lenght=std::size(numbers);
		int flag;
		for (i=0;i<lenght;i++){
			for(j=i+1;j<lenght;j++){
				if (numbers[i]+numbers[j]==target){
					flag=1;
					break;
				}
			}
			if (flag==true) {
				cout <<"indexes "<< i<<" and "<<j<<"\n";
				res.push_back(i);
				res.push_back(j);
				i=0;
				j=0;
				break;
			}
		}

		return res;
	}

	int lengthOfLongestSubstring(string s){	// pwwkew  // yapamayan
		if (s.empty()) return 0;
		int max=1;
		string lss;
		lss.push_back(s[0]); // p eklendi
		int i=0;
		bool flag=false,isAllDifferent=true;
		for(i=1;i<s.length();i++){

			// if new s[i] does not contain in lss[i] add else dont. and update max
			for(int j=0;j<lss.length();j++){
				if (s[i]==lss[j]){
					flag=true;
					if (max<lss.length()) max=lss.length();
					isAllDifferent=false;
					flag=true;
					lss.clear();
					i--;
					cout<<"aaaa\n";
					break;
				}
			}
			if (flag==false) {
				lss.push_back(s[i]); 
				flag=true;
				cout<<"lss: "<<lss<<endl;

			}
		}
		if (max<lss.length()) max=lss.length();

		if(isAllDifferent) return s.length();
		return max;
	}

	bool isvalid(string s){
		stack<char> stackOfParanthesis; 
		stackOfParanthesis.push('a');

		for(int i=0;i<s.length();i++){
			if (s[i]=='[') stackOfParanthesis.push('[');
			if (s[i]==']'){
				(stackOfParanthesis.top()=='[' ) ? stackOfParanthesis.pop(): stackOfParanthesis.push(']');
				}
			
			if (s[i]=='(') stackOfParanthesis.push('(');
			if(s[i]==')') {stackOfParanthesis.top()=='('  ? stackOfParanthesis.pop(): stackOfParanthesis.push(')');
			}

			if (s[i]=='{') stackOfParanthesis.push('{');
			if (s[i]=='}'){
				stackOfParanthesis.top()=='{'  ? stackOfParanthesis.pop(): stackOfParanthesis.push('}');
				}

		}
		return (stackOfParanthesis.top()=='a');
	}
	int maxProfit(vector<int>& prices) { // time problem use better algorithm using max() remove second loop
  
		int lenght = size(prices);
		int profit=0,highest;
		for (int i=0;i<lenght;i++){
			highest=prices[i];
			for(int j=i;j<lenght;j++){
				if (prices[j]>highest) highest=prices[j]; 
			}
			if (highest-prices[i]>profit) profit =highest-prices[i];

		}
		return profit;

    }
	double myPow(double x, int n) {
		
		double res=1;
        for (long int i=0;i<abs(n);i++){
			res*=x;
		}
		if (n>=0) return res;
		else return (1/res);
    }
};


	int main() {
		vector<int> prices = {5,6,4654,21};
		leetcode object1;

		cout<<"Max Profit: "<<object1.maxProfit(prices)<<endl;



		return 0;
	};
