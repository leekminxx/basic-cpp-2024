#
# 



#include <iostream>
using namespace std;

int main()
{
	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;
	cout << "======================================" << endl;
	char ary[6] = { 'a' , 'b' , 'c' ,'d', 'e' };   // ���ڿ� Ÿ���� �迭 ����
	cout << ary << endl;
	printf("==================================\n");
	char ary1[] = { 'a' , 'b' ,'c','\0' , 'e' };   // �ι��� - ���ڿ��� ���� �˸���.
	cout << ary1 << endl;
	cout << sizeof(ary1) << endl;				   // ��ü ���� ũ��
	cout << strlen(ary1) << endl;				   // ��ü ���� ũ��
	printf("==================================\n");
	char str[] = "string";
	cout << str << endl;							// �ڵ����� �ι��ڰ� �ٴ´�
	cout << sizeof(str) << endl;
	cout << strlen(str) << endl;
	str[0] = 'S';

	printf("===================================\n");
	char str[] = "STRING";
	cout << str << endl;							// �ι��ڰ� ���Ե� ũ�Ⱑ ���ϵȴ�.
	cout << sizeof(str) << endl;
	cout << strlen(str) << endl;
	//pstr[0] = 's' ;                 ���ڿ��� �����ͷ� ����ϴ°��� ������ �Ұ����ϴ�.
	/*
	  C++ - style
	*/

	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl;
	//cout << strlen(s) << endl;
	cout << s.size() << endl;

	string s1 = "Hongkildon";
	cout << s1 << endl;
	cout << sizeof(s1) << endl;
	cout << s1.size() << endl;

	return 0;
}