#pragma once

	//SM3 �ӿ�ʾ��

	//1.ֱ�ӵ��ú���EVP_Digest()
	void evp_sm3();

	//2.�ṩ��EVP_sm3()  EVP_MD����Ӧ�ó������ͨ����׼��EVP API����SM3�Ӵ�ֵ������ӿڵ��÷�ʽ�ɲο�man EVP_DigestInit
	void evp_digest();

	//3.�����з�ʽ,example
	//		echo -n abc | gmssl dgst -sm3