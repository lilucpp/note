#pragma once

extern "C" {

#include <openssl/evp.h>

	//SM3 �ӿ�ʾ��

	//1.����evp�ӿ�
	void evp_ec();

	//2.�򵥽ӿڵ���
	void evp_sm2();

	void createsm2();
	void test_readkeyfromfile();
	void testSignVrify();
	void testVrify();

	//3.�����з�ʽ,example
	//	#SM2��˽Կ��
	// ./gmssl ecparam -genkey -name sm2p256v1 -out sm2key.pem
	//	#ʹ��˽Կǩ��
	//	./gmssl pkeyutl -sign -pkeyopt ec_sign_algor:sm2 -inkey signkey.pem -in demo -out demo.sig
	//	#��˽Կ����ȡ��Կ
	//	./gmssl pkey -pubout -in sm2key.pem -out publicKey.pem
	//	#�ù�Կ��֤ǩ��
	//	./gmssl pkeyutl -verify -pkeyopt ec_sign_algor:sm2 -in demo -sigfile demo.sig -pubin -inkey vrfykey.pem
	//	#����
	// ./gmssl.exe pkeyutl -encrypt -in demo -pubin -pkeyopt ec_encrypt_algor:sm2 -inkey publicKey.pem -out demo.en
	// ./gmssl pkeyutl -decrypt -pkeyopt ec_encrypt_algor:sm2 -inkey sm2key.pem -in demo.en -out demo.de


	EVP_PKEY *genpkey(int curve_nid);
	int evp_pkey_encrypt_decrypt(EVP_PKEY *pkey);
	int evp_pkey_sign(EVP_PKEY *pkey);
	int evp_sign(EVP_PKEY *pkey, const EVP_MD *md);
}