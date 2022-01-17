#include "TKprk.h"
using namespace std;
void TKprk::add_number(int a) {
	num.push_back(a);
	amount_num++;
}
void TKprk::bubble_sort(vector <int>& a) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
int TKprk::reverse_num(int a, int length) {
    if (!a) {
        return a;
    }
    return a % 10 * pow(10, len) + reverse(a / 10, len - 1);
 }
bool TKprk::check(int a) {
	if (a < 1000 || a>9999) {
		return false;
	}
	int b = a;
	int a1 = b % 10;
	b /= 10;
	int a2 = b % 10;
	b /= 10;
	int a3 = b % 10;
	b /= 10;
	int a4 = b;
	if (a1 != a2 || a1 != a3 || a1 != a4) {
		return true;
	}
	else {
		return false;
	}
}
void TKprk:: count_Kprk() {
	for (auto item : num) {
		if (check(item)) {
			Kprk.push_back(item);
			amount_Kprk++;
		}
	}
}
TKprk::TKprk(vector <string> input) {
	for (string s : input) {
		char* pch = strtok(s, " ,.:;");
		while (pch != NULL)
		{
			num.push_back(stoi(pch));
			pch = strtok(NULL, " ,.;:");
		}
	}
}