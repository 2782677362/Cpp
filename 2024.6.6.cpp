#include <iostream>

using namespace std;


//������ǰ��� extern "C" �����ú�������C���Եķ�ʽ��࣬����C�����C++�����ܵ��ô˺���
extern "C" int add(int x, int y)
{
	return x + y;
}



int main()
{
	//����
	int a = 2;
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;
	//��ʱ,a��ra1��ra2��ra3����ʾͬһ����ַ�������൱��ͬһ���ռ�ı���

	const int i = 1;
	//int& ri = i;//���벻ͨ������Ϊi�ǿɶ���д�ģ���riΪֻ����������ȡ����ʱ�������ķ���Ȩ�޲��ܷŴ󣬵�������С
	const int& ri = i;//�����ǿ��Եģ���ΪiΪֻ����riҲ��ֻ��

	int j = 0;
	const int& rj = j;//���У�jΪ�ɶ���д��rjΪֻ���������ķ���Ȩ����С

	int d = 3;
	double db = d;//���﷢����ʽ����ת��:�Ƚ�dת��Ϊһ��ֻ��double���͵ı������ٽ���ת����ı�����ֵ��db
	//double& rd = d;//���벻ͨ������Ϊ��ʱdת��Ϊһ��ֻ����double���͵ı�������rdΪ�ɶ���д������Ȩ�޷Ŵ�
	//long& rd1 = d;//���벻ͨ��������ͬ�ϡ�   ֵ��ע����ǣ����벻ͨ�������͵ĳ����Ƿ�����޹�

	const double& rd2 = d;//����
	const long& rd2 = d; //����

	return 0;
}