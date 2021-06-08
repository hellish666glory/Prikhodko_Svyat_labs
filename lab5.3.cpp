#include <iostream>
#include <cstdio>

using namespace std;

void decoder(char* s, int* cstr, int n) {
	char str[100];
	int i;
	for (i = 0;i < n;i++) {
		str[i] = s[cstr[i]];
	}
	str[n] = '\0';
	cout << str << endl;
}
int main() {
	char s[] = "astfGhsarlkasojndjdfhpdemcace";
	int cstr[] = { 4,13,16 };
	decoder(s, cstr, 3);
	return 0;
}
