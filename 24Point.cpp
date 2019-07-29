#include <iostream>
#include <string>
using namespace std;
char oper[4] = { '+','-','*','/' };
string getKey(int* iniNum);
double useOper(double a, int x, double b);

int main() {
	while (true)
	{
	int iniNum[4];
	//cin four numbres
	for (int i = 0; i < 4; i++){
		cin >> iniNum[i];
	}
	cout << "The key is : " << getKey(iniNum) << endl;
	}
	
	return 0;
}
string getKey(int* iniNum) {
	//Sequential test
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (k == i) continue;
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						if (m == k || m == i) continue;
						for (int n = 0; n < 4; n++) {
							for (int o = 0; o < 4; o++) {
								if (o == m || o == k || o == i) continue;
								if (useOper(useOper(useOper(iniNum[i], j, iniNum[k]), l, iniNum[m]), n, iniNum[o]) == 24) {
									return to_string(iniNum[i])+ oper[j]+ to_string(iniNum[k])
										+ oper[l]+ to_string(iniNum[m])+ oper[n]
										+ to_string(iniNum[o]);
								}
							}
						}
					}
				}
			}
		}
	}
	//If the sequence test does not find the result,run Two or two tests
	//Like "(3+3)*(13-9)"
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (k == i) continue;
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						if (m == k || m == i) continue;
						for (int n = 0; n < 4; n++) {
							for (int o = 0; o < 4; o++) {
								if (o == m || o == k || o == i) continue;
								if (useOper(useOper(iniNum[i],j,iniNum[k]),l,useOper(iniNum[m],n,iniNum[o])) == 24) {
									return "("+to_string(iniNum[i]) + oper[j] + to_string(iniNum[k])+")"
										+oper[l]+ "(" + to_string(iniNum[m]) + oper[n]
										+ to_string(iniNum[o])+")";
								}
							}
						}
					}
				}
			}
		}
	}
	return "error";
}
double useOper(double a,int x, double b) {
	double re;
	switch (x) {
	case 0:
		re = a + b;
		break;
	case 1:
		re = a - b;
		break;
	case 2:
		re = a * b;
		break;
	default:
		re = a / b;
		break;
	}
	return re;
}