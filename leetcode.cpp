// Name        : leetcode.cpp
// Author      : Sadık EĞRİ
// Version     :
// Copyright   : Your copyright notice
// Description : Problems: https://leetcode.com/
//============================================================================

/*
Arrays:

C++ Arrays: Standard C++ arrays are built-in and don't require any additional libraries.
std::array: A fixed-size array with a more modern interface.
Linked Lists:

std::list: Doubly-linked list implementation in the C++ Standard Library.
Stacks:

std::stack: A stack container adapter in the C++ Standard Library.
Queues:

std::queue: A queue container adapter in the C++ Standard Library.
std::deque: Double-ended queue implementation.
Trees:

Binary Search Trees (BSTs) can be implemented using custom code or libraries.
Heaps:

std::priority_queue: A priority queue container adapter in the C++ Standard Library.
Graphs:

Graphs are usually implemented using custom code. You can use std::vector or std::map to represent adjacency lists or matrices.
Tries:

Custom implementation is often used for tries.
Hash Maps (Dictionaries):

std::unordered_map: Hash map implementation in the C++ Standard Library.
std::unordered_set: Hash set implementation in the C++ Standard Library.
Sets:

std::set: Binary search tree-based set in the C++ Standard Library.
Deques:

std::deque: Double-ended queue implementation in the C++ Standard Library.
*/
#include<iostream>
#include <vector> //vector lib enables push_back, pop_back, insert, erase funtions. useul for arrays;
#include<stack>
#include<algorithm>
#include <unordered_set> // hash table
#include<list> // linked list
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class leetcode{
public:
	vector<int> two_sum(vector<int> numbers,int target){

		vector<int> res;
		int i,j;
		int lenght=size(numbers);
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
	bool isPalindrome(int x) {
		string s;
		string rs;
		try
		{
			s=to_string(x);
			rs=s;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		reverse(rs.begin(),rs.end());
		cout<<rs<<endl;
		if (s==rs) return true;
		else return false;
    }

	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> numSet;	// ♥ hash tables ♥
		for (int num:nums){
			if(numSet.count(num)>0) return true;
			numSet.insert(num);
		}
		return false;
    }
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
		int n = matrix[0].size();

		int left = 0;
		int right = m * n - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			int midValue = matrix[mid / n][mid % n];

			if (midValue == target) {
				return true;
			} else if (midValue < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return false;
    }
   
};


	int main() {
		leetcode object1;
		std::vector<std::vector<int>> matrix = {{1,1}};
    	int target = 3;


    	bool result = object1.searchMatrix(matrix, target);
    	std::cout << "Output: " << (result ? "true" : "false") << std::endl;
		return 0;
	};
