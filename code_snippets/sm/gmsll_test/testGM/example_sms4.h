#pragma once

	//SMS4 �ӿ�ʾ��

	//1.�򵥵ļ��ܷ�ʽ
	//		����sms4_encrypt��sms4_decrypt
	int evp_sms4();

	//2.SMS4��EVP_sms4_cbc()��EVP_CIPHER����Ӧ�ÿ���ͨ��EVP_EncryptInit/Update/Final()�������ʣ�������÷�����ο�EVP_EncryptInit(3)�ֲ�ҳ
	int evp_sms4_cbc();

	//3.�����з�ʽ,example
	//		echo hello | gmssl enc -sms4-cbc > ciphertext.bin
	//		cat cipehrtext.bin | gmssl enc -sms4-cbc -d