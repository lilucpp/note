//#include <openssl/applink.c>
#include "example_sms4.h"
#include "example_sm3.h"
#include "example_sm2.h"



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>


// ��ʮ�������ַ���ת��Ϊ�޷����ַ�����
std::vector<unsigned char> hexStringToUnsignedCharArray(const std::string& hexString) {
  std::vector<unsigned char> result;
  for (size_t i = 0; i < hexString.length(); i += 2) {
    std::string byteString = hexString.substr(i, 2);
    unsigned int byteValue;
    std::istringstream(byteString) >> std::hex >> byteValue;
    result.push_back(static_cast<unsigned char>(byteValue));
  }
  return result;
}

// ���޷����ַ����鱣�浽�ļ���
void saveBytesToFile(const std::vector<unsigned char>& bytes, const std::string& filename) {
  std::ofstream file(filename, std::ios::binary);
  if (file.is_open()) {
    file.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
    file.close();
    std::cout << "File saved successfully: " << filename << std::endl;
  }
  else {
    std::cerr << "Error opening file for writing: " << filename << std::endl;
  }
}

int convxx() {
  // ʮ�������ַ���
  std::string hexString = "a3f9d1c175462d86f50c8372fbf91022664247661f7105fddfed942c54d0b1b6d58839a1e40a0a759231605a92cf6899720881599c28d6d551bfd19abe65c8d8"; // "Hello World" ��ʮ�����Ʊ�ʾ

  // ��ʮ�������ַ���ת��Ϊ�޷����ַ�����
  std::vector<unsigned char> bytes = hexStringToUnsignedCharArray(hexString);

  // ���޷����ַ����鱣�浽�ļ���
  saveBytesToFile(bytes, "sin.bin");

  return 0;
}


//Ϊ�˴����������ˣ�ʾ������û������ȫ��顣
//ʵ�ʿ��������У�Ҫ����ȫ��顢������ش��󡢴�ӡ�����Ϣ��
int main(int arc, char *argv[])
{

  convxx();

  return 0;
	//createsm2();

	//printf("read key..................\n");
	//test_readkeyfromfile();

	testVrify();

	//testSignVrify();


	return 0;

	//SM2
	printf("------------------------sm2------------------------\n");
	evp_ec();
	evp_sm2();

	//SM3
	printf("------------------------sm3------------------------\n");
	//evp_sm3();
	//evp_digest();
		
	//SM4
	printf("------------------------sm4------------------------\n");
	//evp_sms4();
	//evp_sms4_cbc();

	return 1;
}