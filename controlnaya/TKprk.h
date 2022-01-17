#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
class TKprk {
private:
	int amount_num = 0;
	int amount_Kprk = 0;
	vector <int> num;
	vector <int> Kprk;
	vector <vector<int>> Matr;
	int reverse_num(int a, int length);
	void bubble_sort(vector <int> &a);
	bool check(int a);
public:
	TKprk(vector <string> input);
	TKprk() {
	cout << "Clas has been created" << endl;
	};
	TKprk(int a);
	void add_number(int a);
	void count_Kprk();
	~TKprk() {
		cout << "Class has been deleted" << endl;
	}
};