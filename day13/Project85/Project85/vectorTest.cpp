//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int main() {
//	vector<int> n1;
//	int num;
//	cout << "�����Է�: " << endl;
//	cin >> num;
//	for (int i = 0; i < n1.size(); ++i) {
//		printf("v[%d]: %d\n", i, n1[i]);
//		printf("��հ�:%d\n", n1);
//	}
//	
//	return 0;
//}
//
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int inkey;
	int sum = 0;

	while (true) {
		cout << "���� �Ѱ� �Է�(0����): ";
		cin >> inkey;
		if (!inkey) {
			break;
		}
		v.push_back(inkey);
		for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << endl;
		}
		sum += inkey;
		cout << sum / v.size() << endl;
	}

	cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}