//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int main() {
//	vector<int> n1;
//	int num;
//	cout << "정수입력: " << endl;
//	cin >> num;
//	for (int i = 0; i < n1.size(); ++i) {
//		printf("v[%d]: %d\n", i, n1[i]);
//		printf("평균값:%d\n", n1);
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
		cout << "정수 한개 입력(0종료): ";
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

	cout << "프로그램을 종료합니다." << endl;
	return 0;
}