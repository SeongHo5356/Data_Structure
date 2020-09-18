#include <iostream>
#include <fstream>

using namespace std;

int main(string inputFileName, string outputFileName) {

	//입력파일이름과 출력파일 이름은 argument를 이용하여 받을 수 있도록 변경할 것
	ifstream input_file("inputFileName.txt");
	ofstream output_file("outputFileName.txt");

	char ch;
	while (!input_file.eof()) {//파일의 끝이 아닐때까지 루프를 반복함
		//공백문자 여부 상관 없이 한 문자(1byte)만큼 읽음
		input_file.get(ch);
		if (!input_file.good()) //입력 파일 스트림에 에러비트가 존재한다면 루프를 빠져나감 
			break;
		if (ch == '\r')//ch 가 LF('\r')이라면
			output_file << '\r\n';
		else
			output_file << ch;
	}	
	input_file.close();
	output_file.close();


	return 0;
}