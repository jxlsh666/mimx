#ifndef _H_LIBSDFAPI_H
#define _H_LIBSDFAPI_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma pack(1)

	typedef unsigned int        SGD_RV;
	typedef char                SGD_CHAR;
	typedef char                SGD_INT8;
	typedef short               SGD_INT16;
	typedef int                 SGD_INT32;
	typedef long long           SGD_INT64;
	typedef unsigned char       SGD_UCHAR;
	typedef unsigned char       SGD_UINT8;
	typedef unsigned short      SGD_UINT16;
	typedef unsigned int        SGD_UINT32;
	typedef unsigned long long  SGD_UINT64;
	typedef void*               SGD_OBJ;
	typedef int                 SGD_BOOL;
	typedef void*               SGD_HANDLE;
	typedef void*               HANDLE;
	/*---------------------------------------------------------------------------*/
	/* Error Code */

	//�����ɹ�
#define SDR_OK                  (0x00000000)
	//���������ֵ
#define SDR_BASE                (0x01000000)
	//δ֪����
#define SDR_UNKNOWERR           (SDR_BASE + 0x00000001)

#define SDR_GENERAL_ERROR       (SDR_BASE + 0x00000001)
	//��֧�ֵĽӿڵ���
#define SDR_NOTSUPPORT          (SDR_BASE + 0x00000002)
	//���豸ͨ��ʧ��
#define SDR_COMMFAIL            (SDR_BASE + 0x00000003)
	//����ģ������Ӧ
#define SDR_HARDFAIL            (SDR_BASE + 0x00000004)
	//���豸ʧ��
#define SDR_OPENDEVICE          (SDR_BASE + 0x00000005)
	//�����Ựʧ��
#define SDR_OPENSESSION         (SDR_BASE + 0x00000006)
	//��˽Կʹ��Ȩ
#define SDR_PARDENY             (SDR_BASE + 0x00000007)
	//�����ڵ���Կ����
#define SDR_KEYNOTEXIST         (SDR_BASE + 0x00000008)
	//��֧�ֵ��㷨����
#define SDR_ALGNOTSUPPORT       (SDR_BASE + 0x00000009)
	//��֧�ֵ��㷨ģʽ����
#define SDR_ALGMODNOTSUPPORT    (SDR_BASE + 0x0000000A)
	//��Կ����ʧ��
#define SDR_PKOPERR             (SDR_BASE + 0x0000000B)
	//˽Կ����ʧ��
#define SDR_SKOPERR             (SDR_BASE + 0x0000000C)
	//ǩ������ʧ��
#define SDR_SIGNERR             (SDR_BASE + 0x0000000D)
	//��֤ǩ��ʧ��
#define SDR_VERIFYERR           (SDR_BASE + 0x0000000E)
	//�Գ��㷨����ʧ��
#define SDR_SYMOPERR            (SDR_BASE + 0x0000000F)
	//�ಽ���㲽�����
#define SDR_STEPERR             (SDR_BASE + 0x00000010)
	//�ļ����ȳ�������
#define SDR_FILESIZEERR         (SDR_BASE + 0x00000011)
	//ָ���ļ�������
#define SDR_FILENOEXIST         (SDR_BASE + 0x00000012)
	//�ļ���ʼλ�ô���
#define SDR_FILEOFSERR          (SDR_BASE + 0x00000013)
	//��Կ���ʹ���
#define SDR_KEYTYPEERR          (SDR_BASE + 0x00000014)
	//��Կ����
#define SDR_KEYERR              (SDR_BASE + 0x00000015)
	//ECC�������ݴ���
#define SDR_ENCDATAERR          (SDR_BASE + 0x00000016)
	//���������ʧ��
#define SDR_RANDERR             (SDR_BASE + 0x00000017)
	//˽Կʹ��Ȩ��ȡʧ��
#define SDR_PRKRERR             (SDR_BASE + 0x00000018)
	//MAC����ʧ��
#define SDR_MACERR              (SDR_BASE + 0x00000019)
	//ָ���ļ��Ѵ���
#define SDR_FILEEXISTS          (SDR_BASE + 0x0000001A)
	//�ļ�д��ʧ��
#define SDR_FILEWERR            (SDR_BASE + 0x0000001B)
	//�洢�ռ䲻��
#define SDR_NOBUFFER            (SDR_BASE + 0x0000001C)
	//�����������
#define SDR_INARGERR            (SDR_BASE + 0x0000001D)
	//�����������
#define SDR_OUTARGERR           (SDR_BASE + 0x0000001E)
	//����Աδ��½
#define SDR_NOADMIN	            (SDR_BASE + 0x0000001F)
	//�û�δ��½
#define SDR_NOUSER	            (SDR_BASE + 0x00000020)
	//��Կ�Ѵ���
#define SDR_KEYEXISTS			(SDR_BASE + 0x00000021)

	//���������㷨��ʶ
#define SGD_SMS4_ECB  0x00000401 //SMS4�㷨ECB����ģʽ
#define SGD_SMS4_CBC  0x00000402
#define SGD_SMS4_CFB  0x00000404
#define SGD_SMS4_OFB  0x00000408
#define SGD_SMS4_MAC  0x00000410

	// asymmetric algorithms			
#define SGD_SM2			        (0x00020100)	//��Բ���������㷨
#define SGD_SM2_1		        (0x00020200)	//��Բ����ǩ���㷨
#define SGD_SM2_2		        (0x00020400)	//��Բ������Կ����Э��
#define SGD_SM2_3		        (0x00020800)	//��Բ���߼����㷨

	// hash algorithms
#define SGD_SM3                 (0x00000001)	//SM3�Ӵ��㷨

	typedef struct DeviceInfo_st {
		unsigned char IssuerName[40];
		unsigned char DeviceName[16];
		unsigned char DeviceSerial[16];
		unsigned int DeviceVersion;
		unsigned int StandardVersion;
		unsigned int AsymAlgAbility[2];
		unsigned int SymAlgAbility;
		unsigned int HashAlgAbility;
		unsigned int BufferSize;
	} DEVICEINFO;
#define RSAref_MAX_BITS         (2048UL)
#define RSAref_MAX_LEN          ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS        ((RSAref_MAX_BITS + 1) /2)
#define RSAref_MAX_PLEN         ((RSAref_MAX_PBITS + 7) / 8)

	typedef struct RSArefPublicKeyEx_st {
		unsigned int bits;
		unsigned char m[RSAref_MAX_LEN];
		unsigned char e[RSAref_MAX_LEN];
	} RSArefPublicKey;

	typedef struct RSArefPrivateKeyEx_st {
		unsigned int bits;
		unsigned char m[RSAref_MAX_LEN];
		unsigned char e[RSAref_MAX_LEN];
		unsigned char d[RSAref_MAX_LEN];
		unsigned char prime[2][RSAref_MAX_PBITS];
		unsigned char pexp[2][RSAref_MAX_PBITS];
		unsigned char coef[RSAref_MAX_PBITS];
	} RSArefPrivateKey;

	// Elliptic Curve
#define ECCref_MAX_BITS     (512UL)
#define ECCref_MAX_LEN      ((ECCref_MAX_BITS+7) / 8)

	typedef struct ECCrefPublicKey_st {
		unsigned int bits;
		unsigned char x[ECCref_MAX_LEN];  // x coordinate
		unsigned char y[ECCref_MAX_LEN];  // y coordinate
	} ECCrefPublicKey, ECCPUBLICKEYBLOB;

	typedef struct ECCrefPrivateKey_st {
		unsigned int bits;
		unsigned char K[ECCref_MAX_LEN];  // private key
	} ECCrefPrivateKey;

	typedef struct ECCCipher_st {
		unsigned char x[ECCref_MAX_LEN];  //  point's x coordinate
		unsigned char y[ECCref_MAX_LEN];  //  point's x coordinate
		unsigned char M[32];  // reserved for MAC data
		unsigned int L;
		unsigned char C[1];  // encrypted data
	} ECCCipher,ECCCIPHERBLOB, *PECCCIPHERBLOB;

	typedef struct ECCSignature_st {
		unsigned char r[ECCref_MAX_LEN];  //r part of the signature
		unsigned char s[ECCref_MAX_LEN];  //s part of the signature
	} ECCSignature;
	typedef struct ECCCipher_st_c {
		unsigned char x[ECCref_MAX_LEN];  //  point's x coordinate
		unsigned char y[ECCref_MAX_LEN];  //  point's x coordinate
		unsigned char M[32];  // reserved for MAC data
		unsigned int L;
		unsigned char C[16];  // encrypted data
	} ECCCIPHER_C;
	typedef struct SDF_ENVELOPEDKEYBLOB {
		unsigned int ulAsymmAlgID;
		unsigned int ulSymmAlgID;
		ECCCIPHER_C ECCCipherBlob;
		ECCPUBLICKEYBLOB PubKey;
		unsigned char cbEncryptedKey[64];
	} ENVELOPEDKEYBLOB, *PENVELOPEDKEYBLOB;
#pragma pack() 

#define SGD_TRUE              1
#define SGD_FALSE             0

#define IN
#define OUT
#define DLL_PUBLIC __attribute__ ((visibility("default")))    
#define DLL_LOCAL  __attribute__ ((visibility("hidden")))

	//�豸����������8��
	/****************************************************************************************************/
	//���豸
	//�����������������豸
	//                 
	//������    
	//          phDeviceHandle     [OUT]      �����豸���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��    phDeviceHandle�ɺ�����ʼ������д����
	DLL_PUBLIC SGD_RV SDF_OpenDevice( //
		OUT SGD_HANDLE *phDeviceHandle //
		);
	/****************************************************************************************************/
	//�ر��豸
	//�����������ر������豸�����ͷ������Դ
	//                 
	//������    
	//          phDeviceHandle     [IN]      �Ѵ򿪵��豸���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_CloseDevice( //
		IN SGD_HANDLE hDeviceHandle //
		);
	/****************************************************************************************************/
	//�����Ự
	//���������������������豸�ĻỰ
	//                 
	//������    
	//          hDeviceHandle     [IN]      �Ѵ򿪵��豸���
	//			phSessionHandle	  [OUT]		�����������豸�������»Ự���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_OpenSession( //
		IN SGD_HANDLE hDeviceHandle, //
		OUT SGD_HANDLE *phSessionHandle //
		);
	/****************************************************************************************************/
	//�رջỰ
	//�����������ر��������豸�ѽ����ĻỰ�����ͷ������Դ
	//                 
	//������    
	//          hSessionHandle     [IN]      �������豸�ѽ����ĻỰ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_CloseSession( //
		IN SGD_HANDLE hSessionHandle //
		);
	/****************************************************************************************************/
	//��ȡ�豸��Ϣ
	//������������ȡ�����豸��������
	//                 
	//������    
	//          hSessionHandle     [IN]      �������豸�ѽ����ĻỰ���
	//			pstDeviceInfo	   [OUT]	 �豸����������Ϣ���������ʽ���豸��Ϣ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GetDeviceInfo( //
		IN SGD_HANDLE hSessionHandle,
		OUT DEVICEINFO *pstDeviceInfo //
		);
	/****************************************************************************************************/
	//���������
	//������������ȡָ�����ȵ������
	//                 
	//������    
	//          hSessionHandle      [IN]         �������豸�ѽ����ĻỰ���
	//			uiLength	        [IN]		 ����ȡ�����������
	//			pucRandom			[OUT]		 ������ָ�룬���ڴ�Ż�ȡ�������
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GenerateRandom( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiLength, //
		OUT SGD_UCHAR *pucRandom //
		);
	/****************************************************************************************************/
	//��ȡ˽Կʹ��Ȩ��
	//������������ȡ�����豸�ڲ��洢��ָ������˽Կ��ʹ��Ȩ
	//                 
	//������    
	//          hSessionHandle      [IN]         �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		 �����豸�洢˽Կ������ֵ
	//			pucPassword			[IN]		 ʹ��˽ԿȨ�޵ı�ʶ��
	//			uiPwdLength			[IN]		 ˽Կ��λ�����볤�ȣ�������8�ֽ�
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	����׼�漰�����豸�洢����Կ������ֵ����ʼ����ֵΪ1�����Ϊn�������豸��ʵ�ʴ洢��������nֵ��
	DLL_PUBLIC SGD_RV SDF_GetPrivateKeyAccessRight( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucPassword, //
		IN SGD_UINT32 uiPwdLength //
		);
	/****************************************************************************************************/
	//�ͷ�˽Կ��ʹ��Ȩ��
	//�����������ͷ������豸�洢��ָ������˽Կ��ʹ��Ȩ��Ȩ��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢˽Կ������ֵ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ReleasePrivateKeyAccessRight( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex //
		);
	/*-----------------------------------------------------------------------------
	*  ��Կ�����ຯ��
	*/
	/****************************************************************************************************/
	//����RSAǩ����Կ
	//�������������������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢��RSA��Կ������ֵ
	//			pucPublicKey		[OUT]		RSA��Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ExportSignPublicKey_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		OUT RSArefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//����RSA���ܹ�Կ
	//�������������������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢��RSA��Կ������ֵ
	//			pucPublicKey		[OUT]		RSA��Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ExportEncPublicKey_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		OUT RSArefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//����RSA��Կ�Բ����
	//�������������������豸����ָ��ģ����RSA��Կ�ԡ�
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyBits	        [IN]		ָ����Կģ��
	//			pucPublicKey		[OUT]		RSA��Կ�ṹ
	//			pucPrivateKey		[OUT]		RSA˽Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GenerateKeyPair_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		OUT RSArefPublicKey *pucPublicKey, //
		OUT RSArefPrivateKey *pucPrivateKey //
		);
	/****************************************************************************************************/
	//���ɻỰ��Կ�����ڲ�RSA��Կ�������
	//�������������ɻỰ��Կ����ָ���������ڲ����ܹ�Կ���������ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiIPKIndex	        [IN]		�����豸�ڲ��洢��Կ������ֵ
	//			uiKeyBits			[IN]		ָ�������ĻỰ��Կ����
	//			pucKey				[OUT]		������ָ�룬���ڴ�ŷ��ص���Կ����
	//			puiKeyLength		[OUT]		���ص���Կ���ĳ���
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��Կ��������ʱ��䷽ʽ����PKCS# V1.5��Ҫ����С�
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithIPK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiIPKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		OUT SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 *puiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//���ɻỰ��Կ�����ⲿRSA��Կ�������
	//�������������ɻỰ��Կ�����ⲿ��Կ���������ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyBits	        [IN]		ָ�������ĻỰ��Կ����
	//			pucPublicKey		[IN]		������ⲿRSA��Կ�ṹ
	//			pucKey				[OUT]		������ָ�룬���ڴ�ŷ��ص���Կ����
	//			puiKeyLength		[OUT]		���ص���Կ���ĳ���
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��Կ��������ʱ��䷽ʽ����PKCS# V1.5��Ҫ����С�
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithEPK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		IN RSArefPublicKey *pucPublicKey, //
		OUT SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 *puiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//����Ự��Կ�����ڲ�RSA˽Կ����
	//��������������Ự��Կ�����ڲ�˽Կ���ܣ�ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex	        [IN]		�����豸�ڲ��洢����˽Կ������ֵ����Ӧ�ڼ���ʱ�Ĺ�Կ
	//			pucKey				[IN]		������ָ�룬���ڴ���������Կ����
	//			puiKeyLength		[OUT]		�������Կ���ĳ���
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��䷽ʽ�빫Կ����ʱ��ͬ��
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithISK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		IN SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 uiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//����RSA�㷨�������ŷ�ת��
	//���������������ڲ����ܹ�Կ���ܵĻỰ��Կת��Ϊ���ⲿָ���Ĺ�Կ���ܣ������������ŷ�ת��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢������RSA��Կ������ֵ
	//			pucPublicKey		[IN]		�ⲿRSA��Կ�ṹ
	//			pucDEInput  		[IN]		������ָ�룬���ڴ������ĻỰ��Կ����
	//			uiDELength			[IN]		����ĻỰ��Կ���ĳ���
	//			pucDEOutput  		[OUT]		������ָ�룬���ڴ������ĻỰ��Կ����
	//			puiDELength			[OUT]		����ĻỰ��Կ���ĳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ExchangeDigitEnvelopeBaseOnRSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN RSArefPublicKey *pucPublicKey, //
		IN SGD_UCHAR *pucDEInput, //
		IN SGD_UINT32 uiDELength, //
		OUT SGD_UCHAR *pucDEOutput, //
		OUT SGD_UINT32 *puiDELength //
		);
	/****************************************************************************************************/
	//����ECCǩ����Կ
	//�������������������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢��ECC��Կ������ֵ��ȡֵ��Χ0--9
	//			pucPublicKey		[OUT]		ECC��Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע����Կ����ֵ��0��ʼ��������Ϊ0�ı�ʾ�豸��Կ�������Ŵ�1��ʼ��ʾ�û���Կ��
	DLL_PUBLIC SGD_RV SDF_ExportSignPublicKey_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiKeyIndex, //
		OUT ECCrefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//����ECC���ܹ�Կ
	//�������������������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex	        [IN]		�����豸�洢��ECC��Կ������ֵ��ȡֵ��Χ0--9
	//			pucPublicKey		[OUT]		ECC��Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע����Կ����ֵ��0��ʼ��������Ϊ0�ı�ʾ�豸��Կ�������Ŵ�1��ʼ��ʾ�û���Կ��
	DLL_PUBLIC SGD_RV SDF_ExportEncPublicKey_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiKeyIndex, //
		OUT ECCrefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//����ECC��Կ�Բ����
	//�������������������豸����ָ�����ͺ�ģ����ECC��Կ��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID		        [IN]		ָ���㷨��ʶ
	//			uiKeyBits	        [IN]		ָ����Կ����
	//			pucPublicKey		[OUT]		ECC��Կ�ṹ
	//			pucPrivateKey		[OUT]		ECC˽Կ�ṹ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GenerateKeyPair_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiAlgID, //
		IN unsigned int uiKeyBits, //
		OUT ECCrefPublicKey *pucPublicKey, //
		OUT ECCrefPrivateKey *pucPrivateKey //
		);

	/****************************************************************************************************/
	//���ɻỰ��Կ�����ڲ�ECC��Կ�������
	//�������������ɻỰ��Կ����ָ���������ڲ�ECC���ܹ�Կ���������ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiIPKIndex	        [IN]		�����豸�ڲ��洢��Կ������ֵ
	//			uiKeyBits			[IN]		ָ�������ĻỰ��Կ����
	//			pucKey				[OUT]		������ָ�룬���ڴ�ŷ��ص���Կ����
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithIPK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiIPKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);


	/****************************************************************************************************/
	//���ɻỰ��Կ�����ⲿECC��Կ�������
	//�������������ɻỰ��Կ�����ⲿECC���ܹ�Կ���������ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyBits			[IN]		ָ�������ĻỰ��Կ����
	//			uiAlgID				[IN]		���ECC��Կ���㷨��ʶ
	//			pucPublicKey		[IN]		��������ECC��Կ�ṹ
	//			pucKey				[OUT]		������ָ�룬���ڴ�ŷ��ص���Կ����
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithEPK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//����Ự��Կ�����ڲ�ECC˽Կ����
	//��������������Ự��Կ�����ڲ�ECC����˽Կ���ܣ�ͬʱ������Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�����豸�ڲ��洢����˽Կ������ֵ����Ӧ�ڼ���ʱ�Ĺ�Կ
	//			pucKey				[OUT]		������ָ�룬���ڴ���������Կ����
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithISK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);

	/****************************************************************************************************/
	//������ԿЭ�̲��������
	//����������ʹ��ECC��ԿЭ���㷨��Ϊ����Ự��Կ������Э�̲�����ͬʱ����ָ������λ�õ�ECC��Կ����ʱECC��Կ�ԵĹ�Կ��Э�̾��
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�����豸�ڲ��洢����˽Կ������ֵ����˽Կ���ڲ�����ԿЭ��
	//			uiKeyBits			[IN]		Ҫ��Э�̵���Կ����
	//			pucSponsorID		[IN]		������ԿЭ�̵ķ���IDֵ
	//			uiSponsorIDLength	[IN]		����ID����
	//			pucSponsorPublicKey	[OUT]		���صķ���ECC��Կ�ṹ
	//			pucSponsorTmpPublicKey	[OUT]		���صķ�����ʱECC��Կ�ṹ
	//			phAgreementHandle		[OUT]		���ص�Э�̾�������ڼ���Э����Կ
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	ΪЭ�̻Ự��Կ��Э�̵ķ���Ӧ���ȵ��ñ�������
	DLL_PUBLIC SGD_RV SDF_GenerateAgreementDataWithECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		IN SGD_UCHAR *pucSponsorID, //
		IN SGD_UINT32 uiSponsorIDLength, //
		OUT ECCrefPublicKey *pucSponsorPublicKey, //
		OUT ECCrefPublicKey *pucSponsorTmpPublicKey, //
		OUT SGD_HANDLE *phAgreementHandle //
		);
	/****************************************************************************************************/
	//����Ự��Կ
	//����������ʹ��ECC��ԿЭ���㷨��ʹ������Э�̾������Ӧ����Э�̲�������Ự��Կ��ͬʱ���ػỰ��Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucSponsorID		[IN]		�ⲿ�������Ӧ��IDֵ
	//			uiSponsorIDLength	[IN]		�ⲿ�������Ӧ��ID����
	//			pucResponsePublicKey	[IN]	�ⲿ�������Ӧ��ECC��Կ�ṹ
	//			pucResponseTmpPublicKey	[IN]	�ⲿ�������Ӧ����ʱECC��Կ�ṹ
	//			phAgreementHandle	[IN]		Э�̾�������ڼ���Э����Կ
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	Э�̵ķ��𷽻����Ӧ����Э�̲�������ñ�����������Ự��Կ��ʹ��SM2�㷨����Ự��Կ�Ĺ��̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucResponseID, //
		IN SGD_UINT32 uiResponseIDLength, //
		IN ECCrefPublicKey *pucResponsePublicKey, //
		IN ECCrefPublicKey *pucResponseTmpPublicKey, //
		IN SGD_HANDLE phAgreementHandle, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ��ͬʱ���ز�����Э�̲�������Կ���
	//����������ʹ��ECC��ԿЭ���㷨��ʹ������Э�̾������Ӧ����Э�̲�������Ự��Կ��ͬʱ���ػỰ��Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�����豸�ڲ��洢����˽Կ������ֵ����˽Կ���ڲ�����ԿЭ��
	//			uiKeyBits			[IN]		Э�̺�Ҫ���������Կ����
	//			pucResponseID		[IN]		��Ӧ��IDֵ
	//			uiResponseIDLength	[IN]		��Ӧ��ID����
	//			pucSponsorID		[IN]		����IDֵ
	//			uiSponsorIDLength	[IN]		����ID����
	//			pucSponsorPublicKey	[IN]		�ⲿ����ķ���ECC��Կ�ṹ
	//			pucSponsorTmpPublicKey	[IN]	�ⲿ����ķ�����ʱECC��Կ�ṹ
	//			pucResponsePublicKey	[OUT]	���ص���Ӧ��ECC��Կ�ṹ
	//			pucResponseTmpPublicKey	[OUT]	���ص���Ӧ����ʱECC��Կ�ṹ
	//			phKeyHandle				[OUT]	���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	Э�̵ķ��𷽻����Ӧ����Э�̲�������ñ�����������Ự��Կ��ʹ��SM2�㷨����Ự��Կ�Ĺ��̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_GenerateAgreementDataAndKeyWithECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		IN SGD_UCHAR *pucResponseID, //
		IN SGD_UINT32 uiResponseIDLength, //
		IN SGD_UCHAR *pucSponsorID, //
		IN SGD_UINT32 uiSponsorIDLength, //
		IN ECCrefPublicKey *pucSponsorPublicKey, //
		IN ECCrefPublicKey *pucSponsorTmpPublicKey, //
		OUT ECCrefPublicKey *pucResponsePublicKey, //
		OUT ECCrefPublicKey *pucResponseTmpPublicKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//����ECC�㷨�������ŷ�ת��
	//���������������ڲ����ܹ�Կ���ܵĻỰ��Կת��Ϊ���ⲿָ���Ĺ�Կ���ܣ������������ŷ�ת����
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex			[IN]		�����豸�洢��ECC��Կ������ֵ
	//			uiAlgID				[IN]		�ⲿECC��Կ���㷨��ʶ
	//			pucPublicKey		[IN]		�ⲿECC��Կ�ṹ
	//			pucEncDataIn		[IN]		������ָ�룬���ڴ������ĻỰ��Կ����
	//			pucEncDataOut		[OUT]		������ָ�룬���ڴ������ĻỰ��Կ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ExchangeDigitEnvelopeBaseOnECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN ECCCipher *pucEncDataIn, //
		OUT ECCCipher *pucEncDataOut //
		);
	/****************************************************************************************************/
	//���ɻỰ��Կ������Կ������Կ�������
	//�������������ɻỰ��Կ������Կ������Կ���������ͬʱ������Կ�����
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyBits			[IN]		ָ�������ĻỰ��Կ����
	//			uiAlgID				[IN]		�㷨��ʶ��ָ���ԳƼ����㷨
	//			uiKEKIndex			[IN]		�����豸�ڲ��洢��Կ������Կ������ֵ����Կ������Ϊ1--16
	//			pucKey				[OUT]		������ָ�룬���ڴ�ŷ��ص���Կ����
	//			puiKeyLength		[OUT]		���ص���Կ���ĳ���
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	����ģʽ����ECBģʽ
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithKEK( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		IN SGD_UINT32 uiAlgID, //
		IN SGD_UINT32 uiKEKIndex, //
		OUT SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 *puiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//����Ự��Կ������Կ������Կ����
	//��������������Ự��Կ������Կ������Կ���ܣ�ͬʱ���ػỰ��Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ���ԳƼ����㷨
	//			uiKEKIndex			[IN]		�����豸�ڲ��洢��Կ������Կ������ֵ����Կ������Ϊ1--16
	//			pucKey				[IN]		������ָ�룬���ڴ���������Կ����
	//			puiKeyLength		[IN]		�������Կ���ĳ���
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	����ģʽ����ECBģʽ
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithKEK( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN SGD_UINT32 uiKEKIndex, //
		IN SGD_UCHAR *pucKey, //
		IN SGD_UINT32 uiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//���ٻỰ��Կ
	//�������������ٻỰ��Կ�����ͷ�Ϊ��Կ���������ڴ����Դ
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			hKeyHandle			[IN]		�������Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	�ڶԳ��㷨������ɺ�Ӧ���ñ��������ٻỰ��Կ��
	DLL_PUBLIC SGD_RV SDF_DestroyKey( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_HANDLE hKeyHandle //
		);
	/****************************************************************************************************/
	//���ĵ���Ự��Կ��������ʱ��Կ���
	//�������������ĵ���Ự��Կ��������ʱ��Կ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucKey				[IN]		������Կֵ
	//			uiKeyLength			[IN]		��Կ���ȣ�����Ϊ16
	//			phKeyHandle			[OUT]		���ص���Կ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ImportKey( //
		SGD_HANDLE hSessionHandle, //
		SGD_UCHAR *pucKey, //
		SGD_UINT32 uiKeyLength, //
		SGD_HANDLE *phKeyHandle //
		);

	DLL_PUBLIC SGD_RV SDF_GetKeyStatus( //
		SGD_HANDLE hSessionHandle, //
		SGD_UINT32 uiKeyType, //
		SGD_UINT32 *puiKeyStatus, //
		SGD_UINT32 *puiKeyCount //
		);

	/*-----------------------------------------------------------------------------
	* �ǶԳ��㷨�����ຯ��
	*/
	/****************************************************************************************************/
	//�ⲿ��ԿRSA����
	//����������ָ��ʹ���ⲿ��Կ�����ݽ�������
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucPublicKey		[IN]		�ⲿRSA��Կ�ṹ
	//			pucDataInput		[IN]		������ָ�룬���ڴ�����������
	//			uiInputLength		[IN]		��������ݳ���
	//			pucDataOutput		[OUT]		������ָ�룬���ڴ�����������
	//			puiOutputLength		[OUT]		��������ݳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	���ݸ�ʽ��Ӧ�ò��װ��
	DLL_PUBLIC SGD_RV SDF_ExternalPublicKeyOperation_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN RSArefPublicKey *pucPublicKey, //
		IN SGD_UCHAR *pucDataInput, //
		IN SGD_UINT32 uiInputLength, //
		OUT SGD_UCHAR *pucDataOutput, //
		OUT SGD_UINT32 *puiOutputLength //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalPrivateKeyOperation_RSA( //
		SGD_HANDLE hSessionHandle, //
		RSArefPrivateKey *pucPrivateKey, //
		SGD_UCHAR *pucDataInput, //
		SGD_UINT32 uiInputLength, //
		SGD_UCHAR *pucDataOutput, //
		SGD_UINT32 *puiOutputLength //
		);
	/****************************************************************************************************/
	//�ڲ���ԿRSA����
	//����������ָ���ڲ�ָ�������Ĺ�Կ�����ݽ�������
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex			[IN]		�����豸�ڲ��洢��Կ������ֵ
	//			pucDataInput		[IN]		������ָ�룬���ڴ�����������
	//			uiInputLength		[IN]		��������ݳ���
	//			pucDataOutput		[OUT]		������ָ�룬���ڴ�����������
	//			puiOutputLength		[OUT]		��������ݳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	������Χ�������ڲ�ǩ����Կ�ԣ����ݸ�ʽ��Ӧ�ò��װ��
	DLL_PUBLIC SGD_RV SDF_InternalPublicKeyOperation_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucDataInput, //
		IN SGD_UINT32 uiInputLength, //
		OUT SGD_UCHAR *pucDataOutput, //
		OUT SGD_UINT32 *puiOutputLength //
		);
	/****************************************************************************************************/
	//�ڲ�˽ԿRSA����
	//����������ָ���ڲ�ָ��������˽Կ�����ݽ�������
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiKeyIndex			[IN]		�����豸�ڲ��洢˽Կ������ֵ
	//			pucDataInput		[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiInputLength		[IN]		��������ݳ���
	//			pucDataOutput		[OUT]		������ָ�룬���ڴ�����������
	//			puiOutputLength		[OUT]		��������ݳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	������Χ�������ڲ�ǩ����Կ�ԣ����ݸ�ʽ��Ӧ�ò��װ��
	DLL_PUBLIC SGD_RV SDF_InternalPrivateKeyOperation_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucDataInput, //
		IN SGD_UINT32 uiInputLength, //
		OUT SGD_UCHAR *pucDataOutput, //
		OUT SGD_UINT32 *puiOutputLength //
		);
	/****************************************************************************************************/
	//�ⲿ��ԿECCǩ��
	//����������ʹ���ⲿECC��Կ��ECCǩ��ֵ������֤����
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ��ʹ�õ�ECC�㷨
	//			pucPrivateKey		[IN]		�ⲿECC˽Կ�ṹ
	//			pucData				[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiDataLength		[IN]		��������ݳ���
	//			pucSignature		[OUT]		������ָ�룬���ڴ�������ǩ��ֵ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��������Ϊ��ǩ���ݵ��Ӵ�ֵ����ʹ��SM2�㷨ʱ������������Ϊ��ǩ���ݾ���SM2ǩ��Ԥ����Ľṹ��Ԥ������̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_ExternalSign_ECC( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		ECCrefPrivateKey *pucPrivateKey, //
		unsigned char *pucData, //
		unsigned int uiDataLength, //
		ECCSignature *pucSignature //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalSign_RSA( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		RSArefPrivateKey *pucPrivateKey, //
		unsigned char *pucData, //
		unsigned int uiDataLength, //
		unsigned char *pucSignature, //
		unsigned int *puiSignatureLength //
		);
	/****************************************************************************************************/
	//�ⲿ��ԿECC��֤
	//����������ʹ���ⲿECC��Կ��ECCǩ��ֵ������֤����
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ��ʹ�õ�ECC�㷨
	//			pucPublicKey		[IN]		�ⲿECC��Կ�ṹ
	//			pucDataInput		[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiInputLength		[IN]		��������ݳ���
	//			pucSignature		[IN]		������ָ�룬���ڴ�������ǩ��ֵ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��������Ϊ��ǩ���ݵ��Ӵ�ֵ����ʹ��SM2�㷨ʱ������������Ϊ��ǩ���ݾ���SM2ǩ��Ԥ����Ľṹ��Ԥ������̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_ExternalVerify_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN unsigned char *pucDataInput, //
		IN unsigned int uiInputLength, //
		IN ECCSignature *pucSignature //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalVerify_RSA( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		RSArefPublicKey *pucPublicKey, //
		unsigned char *pucData, //
		unsigned int uiDataLength, //
		unsigned char *pucSignature, //
		unsigned int uiSignatureLength //
		);
	/****************************************************************************************************/
	//�ڲ���ԿECCǩ��
	//����������ʹ���ڲ�ECC˽Կ�����ݽ���ǩ�����㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�����豸�ڲ��洢��ECCǩ��˽Կ������ֵ
	//			pucData				[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiDataLength		[IN]		��������ݳ���
	//			pucSignature		[OUT]		������ָ�룬���ڴ�������ǩ��ֵ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��������Ϊ��ǩ���ݵ��Ӵ�ֵ����ʹ��SM2�㷨ʱ������������Ϊ��ǩ���ݾ���SM2ǩ��Ԥ����Ľ����Ԥ������̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_InternalSign_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiISKIndex, //
		IN unsigned char *pucData, //
		IN unsigned int uiDataLength, //
		OUT ECCSignature *pucSignature //
		);
	/****************************************************************************************************/
	//�ڲ���ԿECC��֤
	//����������ʹ���ڲ�ECC��Կ��ECCǩ��ֵ������֤����
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�����豸�ڲ��洢��ECCǩ����Կ������ֵ
	//			pucDataInput		[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiInputLength		[IN]		��������ݳ���
	//			pucSignature		[IN]		������ָ�룬���ڴ�������ǩ��ֵ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��������Ϊ��ǩ���ݵ��Ӵ�ֵ����ʹ��SM2�㷨ʱ������������Ϊ��ǩ���ݾ���SM2ǩ��Ԥ����Ľṹ��Ԥ������̼�GM/T 0009.

	DLL_PUBLIC SGD_RV SDF_InternalVerify_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiISKIndex, //
		IN unsigned char *pucData, //
		IN unsigned int uiDataLength, //
		IN ECCSignature *pucSignature //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalEncrypt_RSA( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		ECCrefPublicKey *pucPublicKey, //
		unsigned char *pucData, //
		unsigned int uiDataLength, //
		ECCCipher *pucEncData //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalDecrypt_RSA( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		ECCrefPrivateKey *pucPrivateKey, //
		ECCCipher *pucEncData, //
		unsigned char *pucData, //
		unsigned int *puiDataLength //
		);
	/****************************************************************************************************/
	//�ⲿ��ԿECC��Կ����
	//����������ʹ���ⲿECC��Կ�����ݽ��м������㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ��ʹ�õ�ECC�㷨
	//			pucPublicKey		[IN]		�ⲿECC��Կ�ṹ
	//			pucData				[IN]		������ָ�룬���ڴ���ⲿ���������
	//			uiDataLength		[IN]		��������ݳ���
	//			pucEncData			[OUT]		������ָ�룬���ڴ���������������
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	��������Ϊ��ǩ���ݵ��Ӵ�ֵ����ʹ��SM2�㷨ʱ������������Ϊ��ǩ���ݾ���SM2ǩ��Ԥ����Ľ����Ԥ������̼�GM/T 0009.

	DLL_PUBLIC SGD_RV SDF_ExternalEncrypt_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN unsigned char *pucData, //
		IN unsigned int uiDataLength, //
		OUT ECCCipher *pucEncData //
		);

	DLL_PUBLIC SGD_RV SDF_ExternalDecrypt_ECC( //
		SGD_HANDLE hSessionHandle, //
		unsigned int uiAlgID, //
		ECCrefPrivateKey *pucPrivateKey, //
		ECCCipher *pucEncData, //
		unsigned char *pucData, //
		unsigned int *puiDataLength //
		);

	/*-----------------------------------------------------------------------------
	*�Գ��㷨�����ຯ��
	*/
	/****************************************************************************************************/
	//�ԳƼ���
	//����������ʹ��ָ������Կ�����IV�����ݽ��жԳƼ������㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			hKeyHandle			[IN]		ָ������Կ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ���ԳƼ����㷨
	//			pucIV				[IN|OUT]	������ָ�룬���ڴ������ͷ��ص�IV����
	//			pucData				[IN]		������ָ�룬���ڴ���������������
	//			uiDataLength		[IN]		������������ĳ���
	//			pucEncData			[OUT]		������ָ�룬���ڴ���������������
	//			puiEncDataLength	[OUT]		������������ĳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	�˺����������ݽ�����䴦����������ݱ�����ָ���㷨���鳤�ȵ���������

	DLL_PUBLIC SGD_RV SDF_Encrypt( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_HANDLE hKeyHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN OUT SGD_UCHAR *pucIV, //
		IN SGD_UCHAR *pucData, //
		IN SGD_UINT32 uiDataLength, //
		OUT SGD_UCHAR *pucEncData, //
		OUT SGD_UINT32 *puiEncDataLength //
		);
	/****************************************************************************************************/
	//�Գƽ���
	//����������ʹ��ָ������Կ�����IV�����ݽ��жԳƽ������㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			hKeyHandle			[IN]		ָ������Կ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ���ԳƼ����㷨
	//			pucIV				[IN|OUT]	������ָ�룬���ڴ������ͷ��ص�IV����
	//			pucEncData			[IN]		������ָ�룬���ڴ���������������
	//			uiEncDataLength		[IN]		������������ĳ���
	//			pucData				[OUT]		������ָ�룬���ڴ���������������
	//			puiDataLength		[OUT]		������������ĳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	�˺����������ݽ�����䴦����������ݱ�����ָ���㷨���鳤�ȵ���������
	DLL_PUBLIC SGD_RV SDF_Decrypt( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_HANDLE hKeyHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN OUT SGD_UCHAR *pucIV, //
		IN SGD_UCHAR *pucEncData, //
		IN SGD_UINT32 uiEncDataLength, //
		OUT SGD_UCHAR *pucData, //
		OUT SGD_UINT32 *puiDataLength //
		);
	/****************************************************************************************************/
	//����MAC
	//����������ʹ��ָ������Կ�����IV�����ݽ���MAC���㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			hKeyHandle			[IN]		ָ������Կ���
	//			uiAlgID				[IN]		�㷨��ʶ��ָ��MAC�����㷨
	//			pucIV				[IN|OUT]	������ָ�룬���ڴ������ͷ��ص�IV����
	//			pucData				[IN]		������ָ�룬���ڴ���������������
	//			uiDataLength		[IN]		������������ĳ���
	//			pucMAC				[OUT]		������ָ�룬���ڴ�������MACֵ
	//			puiMACLength		[OUT]		�����MACֵ����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	�˺����������ݽ��зְ������������MAC������IV��������MACֵ
	DLL_PUBLIC SGD_RV SDF_CalculateMAC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_HANDLE hKeyHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN OUT SGD_UCHAR *pucIV, //
		IN SGD_UCHAR *pucData, //
		IN SGD_UINT32 uiDataLength, //
		OUT SGD_UCHAR *pucMAC, //
		OUT SGD_UINT32 *puiMACLength //
		);
	//�Ӵ������ຯ��
	/****************************************************************************************************/
	//�Ӵ������ʼ��
	//����������ʹ��ָ������Կ�����IV�����ݽ���MAC���㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiAlgID				[IN]		ָ���Ӵ��㷨��ʶ
	//			pucPublicKey		[IN]		ǩ���߹�Կ����uiAlgIDΪSGD_SM3ʱ��Ч��
	//			pucID				[IN]		ǩ���ߵ�IDֵ����uiAlgIDΪSGD_SM3ʱ��Ч��
	//			uiIDLength			[IN]		ǩ����ID�ĳ��ȣ���uiAlgIDΪSGD_SM3ʱ��Ч��
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	//��ע��	uiIDLength������uiAlgIDΪSGD_SM3ʱ������ִ��SM2��Ԥ����1������������̼�GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_HashInit( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN SGD_UCHAR *pucID, //
		IN SGD_UINT32 uiIDLength //
		);
	/****************************************************************************************************/
	//����Ӵ�����
	//��������������ʽ�����Ӵ�����ڶ���������������Ľ����Ӵ����㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucData				[IN]		������ָ�룬���ڴ���������������
	//			uiDataLength		[IN]		������������ĳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_HashUpdate( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucData, //
		IN SGD_UINT32 uiDataLength //
		);
	/****************************************************************************************************/
	//�Ӵ��������
	//��������������ʽ�����Ӵ�������������Ӵ�������������Ӵ����ݲ�����м����ݡ�
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucHash				[OUT]		������ָ�룬���ڴ��������Ӵ�����
	//			puiHashLength		[OUT]		���ص��Ӵ����ݳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_HashFinal( //
		IN SGD_HANDLE hSessionHandle, //
		OUT SGD_UCHAR *pucHash, //
		OUT SGD_UINT32 *puiHashLength //
		);

	/*-----------------------------------------------------------------------------
	* �û��ļ������ຯ��
	*/
	/****************************************************************************************************/
	//�����ļ�
	//�����������������豸�ڲ��������ڴ洢�û����ݵ��ļ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucFileName			[IN]		������ָ�룬���ڴ��������ļ�������󳤶�128�ֽ�
	//			uiNameLen			[IN]		�ļ�������
	//			uiFileSize			[IN]		�ļ���ռ�洢�ռ�ĳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_CreateFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiFileSize //
		);
	/****************************************************************************************************/
	//��ȡ�ļ�
	//������������ȡ�������豸�ڲ��洢�û����ݵ��ļ����ݡ�
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucFileName			[IN]		������ָ�룬���ڴ��������ļ�������󳤶�128�ֽ�
	//			uiNameLen			[IN]		�ļ�������
	//			uiOffset			[IN]		ָ����ȡ�ļ�ʱ��ƫ��ֵ
	//			puiReadLength		[IN|OUT]	���ʱָ����ȡ�ļ����ݵĳ��ȣ�����ʱ����ʵ�ʶ�ȡ�ļ����ݵĳ���
	//			pucBuffer			[OUT]		������ָ�룬���ڴ�Ŷ�ȡ���ļ�����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_ReadFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiOffset, //
		IN OUT SGD_UINT32 *puiReadLength, //
		OUT SGD_UCHAR *pucBuffer //
		);
	/****************************************************************************************************/
	//д�ļ�
	//�����������������豸�ڲ��洢�û����ݵ��ļ���д�����ݡ�
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucFileName			[IN]		������ָ�룬���ڴ��������ļ�������󳤶�128�ֽ�
	//			uiNameLen			[IN]		�ļ�������
	//			uiOffset			[IN]		ָ��д���ļ�ʱ��ƫ��ֵ
	//			uiFileLength		[IN]		ָ��д���ļ����ݵĳ���
	//			pucBuffer			[IN]		������ָ�룬���ڴ�������д�ļ�����
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_WriteFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiOffset, //
		IN SGD_UINT32 uiFileLength, //
		IN SGD_UCHAR *pucBuffer //
		);
	/****************************************************************************************************/
	//ɾ���ļ�
	//����������ɾ��ָ���ļ����������豸�ڲ��洢�û����ݵ��ļ���
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			pucFileName			[IN]		������ָ�룬���ڴ��������ļ�������󳤶�128�ֽ�
	//			uiNameLen			[IN]		�ļ�������
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_DeleteFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen //
		);
	/****************************************************************************************************/
	//�ڲ�ECC˽Կ����
	//����������ʹ���ڲ�ECC˽Կ�����ݽ��н������㡣
	//                 
	//������    
	//          hSessionHandle      [IN]        �������豸�ѽ����ĻỰ���
	//			uiISKIndex			[IN]		�ڲ�ECC������ԿID
	//			uiAlgID				[IN]		�㷨��ʶ��ָ��ʹ�õ�ECC�㷨
	//			pucEncData			[IN]		������ָ�룬���ڴ���ⲿ�������������
	//			pucData				[OUT]		������ָ�룬���ڴ�����������
	//			uiDataLength		[OUT]		��������ݳ���
	//����ֵ��  0 �ɹ�
	//			��0 ʧ�ܣ����ش�����롣
	DLL_PUBLIC SGD_RV SDF_InternalDecrypt_ECC(IN SGD_HANDLE hSessionHandle,	IN SGD_UINT32 uiISKIndex,unsigned int uiAlgID,ECCCipher *pucEncData,unsigned char *pucData,unsigned int *uiDataLength);
	//ָ���ڲ��Գ���Կ����
	DLL_PUBLIC unsigned int SDF_EncryptEx( 
		void* hSessionHandle, 
		unsigned int uiKeyIndex, 
		unsigned int uiAlgID, 
		unsigned char *pucIV, 
		unsigned char *pucData, 
		unsigned int uiDataLength, 
		unsigned char *pucEncData, 
		unsigned int *puiEncDataLength 
		);
	//ָ���ڲ��Գ���Կ����
	DLL_PUBLIC unsigned int SDF_DecryptEx( 
		void* hSessionHandle, 
		unsigned int uiKeyIndex, 
		unsigned int uiAlgID, 
		unsigned char *pucIV, 
		unsigned char *pucEncData, 
		unsigned int uiEncDataLength, 
		unsigned char *pucData, 
		unsigned int *puiDataLength 
		);
#ifdef __cplusplus
};
#endif
#endif
