#include <iostream>
#include <fstream>

using namespace std;

int main(string inputFileName, string outputFileName) {

	//�Է������̸��� ������� �̸��� argument�� �̿��Ͽ� ���� �� �ֵ��� ������ ��
	ifstream input_file("inputFileName.txt");
	ofstream output_file("outputFileName.txt");

	char ch;
	while (!input_file.eof()) {//������ ���� �ƴҶ����� ������ �ݺ���
		//���鹮�� ���� ��� ���� �� ����(1byte)��ŭ ����
		input_file.get(ch);
		if (!input_file.good()) //�Է� ���� ��Ʈ���� ������Ʈ�� �����Ѵٸ� ������ �������� 
			break;
		if (ch == '\r')//ch �� LF('\r')�̶��
			output_file << '\r\n';
		else
			output_file << ch;
	}	
	input_file.close();
	output_file.close();


	return 0;
}