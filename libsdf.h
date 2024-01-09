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

	//操作成功
#define SDR_OK                  (0x00000000)
	//错误码基础值
#define SDR_BASE                (0x01000000)
	//未知错误
#define SDR_UNKNOWERR           (SDR_BASE + 0x00000001)

#define SDR_GENERAL_ERROR       (SDR_BASE + 0x00000001)
	//不支持的接口调用
#define SDR_NOTSUPPORT          (SDR_BASE + 0x00000002)
	//与设备通信失败
#define SDR_COMMFAIL            (SDR_BASE + 0x00000003)
	//运算模块无响应
#define SDR_HARDFAIL            (SDR_BASE + 0x00000004)
	//打开设备失败
#define SDR_OPENDEVICE          (SDR_BASE + 0x00000005)
	//创建会话失败
#define SDR_OPENSESSION         (SDR_BASE + 0x00000006)
	//无私钥使用权
#define SDR_PARDENY             (SDR_BASE + 0x00000007)
	//不存在的密钥调用
#define SDR_KEYNOTEXIST         (SDR_BASE + 0x00000008)
	//不支持的算法调用
#define SDR_ALGNOTSUPPORT       (SDR_BASE + 0x00000009)
	//不支持的算法模式调用
#define SDR_ALGMODNOTSUPPORT    (SDR_BASE + 0x0000000A)
	//公钥运算失败
#define SDR_PKOPERR             (SDR_BASE + 0x0000000B)
	//私钥运算失败
#define SDR_SKOPERR             (SDR_BASE + 0x0000000C)
	//签名运算失败
#define SDR_SIGNERR             (SDR_BASE + 0x0000000D)
	//验证签名失败
#define SDR_VERIFYERR           (SDR_BASE + 0x0000000E)
	//对称算法运算失败
#define SDR_SYMOPERR            (SDR_BASE + 0x0000000F)
	//多步运算步骤错误
#define SDR_STEPERR             (SDR_BASE + 0x00000010)
	//文件长度超出限制
#define SDR_FILESIZEERR         (SDR_BASE + 0x00000011)
	//指定文件不存在
#define SDR_FILENOEXIST         (SDR_BASE + 0x00000012)
	//文件起始位置错误
#define SDR_FILEOFSERR          (SDR_BASE + 0x00000013)
	//密钥类型错误
#define SDR_KEYTYPEERR          (SDR_BASE + 0x00000014)
	//密钥错误
#define SDR_KEYERR              (SDR_BASE + 0x00000015)
	//ECC加密数据错误
#define SDR_ENCDATAERR          (SDR_BASE + 0x00000016)
	//随机数产生失败
#define SDR_RANDERR             (SDR_BASE + 0x00000017)
	//私钥使用权获取失败
#define SDR_PRKRERR             (SDR_BASE + 0x00000018)
	//MAC运算失败
#define SDR_MACERR              (SDR_BASE + 0x00000019)
	//指定文件已存在
#define SDR_FILEEXISTS          (SDR_BASE + 0x0000001A)
	//文件写入失败
#define SDR_FILEWERR            (SDR_BASE + 0x0000001B)
	//存储空间不足
#define SDR_NOBUFFER            (SDR_BASE + 0x0000001C)
	//输入参数错误
#define SDR_INARGERR            (SDR_BASE + 0x0000001D)
	//输出参数错误
#define SDR_OUTARGERR           (SDR_BASE + 0x0000001E)
	//管理员未登陆
#define SDR_NOADMIN	            (SDR_BASE + 0x0000001F)
	//用户未登陆
#define SDR_NOUSER	            (SDR_BASE + 0x00000020)
	//密钥已存在
#define SDR_KEYEXISTS			(SDR_BASE + 0x00000021)

	//分组密码算法标识
#define SGD_SMS4_ECB  0x00000401 //SMS4算法ECB加密模式
#define SGD_SMS4_CBC  0x00000402
#define SGD_SMS4_CFB  0x00000404
#define SGD_SMS4_OFB  0x00000408
#define SGD_SMS4_MAC  0x00000410

	// asymmetric algorithms			
#define SGD_SM2			        (0x00020100)	//椭圆曲线密码算法
#define SGD_SM2_1		        (0x00020200)	//椭圆曲线签名算法
#define SGD_SM2_2		        (0x00020400)	//椭圆曲线密钥交换协议
#define SGD_SM2_3		        (0x00020800)	//椭圆曲线加密算法

	// hash algorithms
#define SGD_SM3                 (0x00000001)	//SM3杂凑算法

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

	//设备管理函数共有8个
	/****************************************************************************************************/
	//打开设备
	//功能描述：打开密码设备
	//                 
	//参数：    
	//          phDeviceHandle     [OUT]      返回设备句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：    phDeviceHandle由函数初始化并填写内容
	DLL_PUBLIC SGD_RV SDF_OpenDevice( //
		OUT SGD_HANDLE *phDeviceHandle //
		);
	/****************************************************************************************************/
	//关闭设备
	//功能描述：关闭密码设备，并释放相关资源
	//                 
	//参数：    
	//          phDeviceHandle     [IN]      已打开的设备句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_CloseDevice( //
		IN SGD_HANDLE hDeviceHandle //
		);
	/****************************************************************************************************/
	//创建会话
	//功能描述：创建与密码设备的会话
	//                 
	//参数：    
	//          hDeviceHandle     [IN]      已打开的设备句柄
	//			phSessionHandle	  [OUT]		返回与密码设备建立的新会话句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_OpenSession( //
		IN SGD_HANDLE hDeviceHandle, //
		OUT SGD_HANDLE *phSessionHandle //
		);
	/****************************************************************************************************/
	//关闭会话
	//功能描述：关闭与密码设备已建立的会话，并释放相关资源
	//                 
	//参数：    
	//          hSessionHandle     [IN]      与密码设备已建立的会话句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_CloseSession( //
		IN SGD_HANDLE hSessionHandle //
		);
	/****************************************************************************************************/
	//获取设备信息
	//功能描述：获取密码设备能力描述
	//                 
	//参数：    
	//          hSessionHandle     [IN]      与密码设备已建立的会话句柄
	//			pstDeviceInfo	   [OUT]	 设备能力描述信息，内容与格式见设备信息定义
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GetDeviceInfo( //
		IN SGD_HANDLE hSessionHandle,
		OUT DEVICEINFO *pstDeviceInfo //
		);
	/****************************************************************************************************/
	//产生随机数
	//功能描述：获取指定长度的随机数
	//                 
	//参数：    
	//          hSessionHandle      [IN]         与密码设备已建立的会话句柄
	//			uiLength	        [IN]		 欲获取的随机数长度
	//			pucRandom			[OUT]		 缓冲区指针，用于存放获取的随机数
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GenerateRandom( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiLength, //
		OUT SGD_UCHAR *pucRandom //
		);
	/****************************************************************************************************/
	//获取私钥使用权限
	//功能描述：获取密码设备内部存储的指定索引私钥的使用权
	//                 
	//参数：    
	//          hSessionHandle      [IN]         与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		 密码设备存储私钥的索引值
	//			pucPassword			[IN]		 使用私钥权限的标识码
	//			uiPwdLength			[IN]		 私钥方位控制码长度，不少于8字节
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	本标准涉及密码设备存储的密钥对索引值的起始索引值为1，最大为n，密码设备的实际存储容量决定n值。
	DLL_PUBLIC SGD_RV SDF_GetPrivateKeyAccessRight( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucPassword, //
		IN SGD_UINT32 uiPwdLength //
		);
	/****************************************************************************************************/
	//释放私钥的使用权限
	//功能描述：释放密码设备存储的指定索引私钥的使用权授权。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储私钥的索引值
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ReleasePrivateKeyAccessRight( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex //
		);
	/*-----------------------------------------------------------------------------
	*  密钥管理类函数
	*/
	/****************************************************************************************************/
	//导出RSA签名公钥
	//功能描述：导出密码设备内部存储的指定索引位置的签名公钥。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储的RSA密钥对索引值
	//			pucPublicKey		[OUT]		RSA公钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ExportSignPublicKey_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		OUT RSArefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//导出RSA加密公钥
	//功能描述：导出密码设备内部存储的指定索引位置的加密公钥。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储的RSA密钥对索引值
	//			pucPublicKey		[OUT]		RSA公钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ExportEncPublicKey_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		OUT RSArefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//产生RSA密钥对并输出
	//功能描述：请求密码设备产生指定模长的RSA密钥对。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyBits	        [IN]		指定密钥模长
	//			pucPublicKey		[OUT]		RSA公钥结构
	//			pucPrivateKey		[OUT]		RSA私钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyPair_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		OUT RSArefPublicKey *pucPublicKey, //
		OUT RSArefPrivateKey *pucPrivateKey //
		);
	/****************************************************************************************************/
	//生成会话密钥并用内部RSA公钥加密输出
	//功能描述：生成会话密钥并用指定索引的内部加密公钥加密输出，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiIPKIndex	        [IN]		密码设备内部存储公钥的索引值
	//			uiKeyBits			[IN]		指定产生的会话密钥长度
	//			pucKey				[OUT]		缓冲区指针，用于存放返回的密钥密文
	//			puiKeyLength		[OUT]		返回的密钥密文长度
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	公钥加密数据时填充方式按照PKCS# V1.5的要求进行。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithIPK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiIPKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		OUT SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 *puiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//生成会话密钥并用外部RSA公钥加密输出
	//功能描述：生成会话密钥并用外部公钥加密输出，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyBits	        [IN]		指定产生的会话密钥长度
	//			pucPublicKey		[IN]		输入的外部RSA公钥结构
	//			pucKey				[OUT]		缓冲区指针，用于存放返回的密钥密文
	//			puiKeyLength		[OUT]		返回的密钥密文长度
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	公钥加密数据时填充方式按照PKCS# V1.5的要求进行。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithEPK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		IN RSArefPublicKey *pucPublicKey, //
		OUT SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 *puiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//导入会话密钥并用内部RSA私钥解密
	//功能描述：导入会话密钥并用内部私钥解密，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex	        [IN]		密码设备内部存储加密私钥的索引值，对应于加密时的公钥
	//			pucKey				[IN]		缓冲区指针，用于存放输入的密钥密文
	//			puiKeyLength		[OUT]		输入的密钥密文长度
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	填充方式与公钥加密时相同。
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithISK_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		IN SGD_UCHAR *pucKey, //
		OUT SGD_UINT32 uiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//基于RSA算法的数字信封转换
	//功能描述：将由内部加密公钥加密的会话密钥转换为由外部指定的公钥加密，可用于数字信封转换
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储的内如RSA密钥对索引值
	//			pucPublicKey		[IN]		外部RSA公钥结构
	//			pucDEInput  		[IN]		缓冲区指针，用于存放输入的会话密钥密文
	//			uiDELength			[IN]		输入的会话密钥密文长度
	//			pucDEOutput  		[OUT]		缓冲区指针，用于存放输出的会话密钥密文
	//			puiDELength			[OUT]		输出的会话密钥密文长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
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
	//导出ECC签名公钥
	//功能描述：导出密码设备内部存储的指定索引位置的签名公钥
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储的ECC密钥对索引值，取值范围0--9
	//			pucPublicKey		[OUT]		ECC公钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：密钥索引值从0开始，索引号为0的表示设备密钥，索引号从1开始表示用户密钥。
	DLL_PUBLIC SGD_RV SDF_ExportSignPublicKey_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiKeyIndex, //
		OUT ECCrefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//导出ECC加密公钥
	//功能描述：导出密码设备内部存储的指定索引位置的加密公钥
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex	        [IN]		密码设备存储的ECC密钥对索引值，取值范围0--9
	//			pucPublicKey		[OUT]		ECC公钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：密钥索引值从0开始，索引号为0的表示设备密钥，索引号从1开始表示用户密钥。
	DLL_PUBLIC SGD_RV SDF_ExportEncPublicKey_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiKeyIndex, //
		OUT ECCrefPublicKey *pucPublicKey //
		);
	/****************************************************************************************************/
	//产生ECC密钥对并输出
	//功能描述：请求密码设备产生指定类型和模长的ECC密钥对
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID		        [IN]		指定算法标识
	//			uiKeyBits	        [IN]		指定密钥长度
	//			pucPublicKey		[OUT]		ECC公钥结构
	//			pucPrivateKey		[OUT]		ECC私钥结构
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyPair_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiAlgID, //
		IN unsigned int uiKeyBits, //
		OUT ECCrefPublicKey *pucPublicKey, //
		OUT ECCrefPrivateKey *pucPrivateKey //
		);

	/****************************************************************************************************/
	//生成会话密钥并用内部ECC公钥加密输出
	//功能描述：生成会话密钥并用指定索引的内部ECC加密公钥加密输出，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiIPKIndex	        [IN]		密码设备内部存储公钥的索引值
	//			uiKeyBits			[IN]		指定产生的会话密钥长度
	//			pucKey				[OUT]		缓冲区指针，用于存放返回的密钥密文
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithIPK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiIPKIndex, //
		IN SGD_UINT32 uiKeyBits, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);


	/****************************************************************************************************/
	//生成会话密钥并用外部ECC公钥加密输出
	//功能描述：生成会话密钥并用外部ECC加密公钥加密输出，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyBits			[IN]		指定产生的会话密钥长度
	//			uiAlgID				[IN]		外边ECC公钥的算法标识
	//			pucPublicKey		[IN]		输入的外边ECC公钥结构
	//			pucKey				[OUT]		缓冲区指针，用于存放返回的密钥密文
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_GenerateKeyWithEPK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyBits, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//导入会话密钥并用内部ECC私钥解密
	//功能描述：导入会话密钥并用内部ECC加密私钥解密，同时返回密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		密码设备内部存储加密私钥的索引值，对应于加密时的公钥
	//			pucKey				[OUT]		缓冲区指针，用于存放输入的密钥密文
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithISK_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiISKIndex, //
		OUT ECCCipher *pucKey, //
		OUT SGD_HANDLE *phKeyHandle //
		);

	/****************************************************************************************************/
	//生成密钥协商参数并输出
	//功能描述：使用ECC密钥协商算法，为计算会话密钥而产生协商参数，同时返回指定索引位置的ECC公钥、临时ECC密钥对的公钥及协商句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		密码设备内部存储加密私钥的索引值，该私钥用于参与密钥协商
	//			uiKeyBits			[IN]		要求协商的密钥长度
	//			pucSponsorID		[IN]		参与密钥协商的发起方ID值
	//			uiSponsorIDLength	[IN]		发起方ID长度
	//			pucSponsorPublicKey	[OUT]		返回的发起方ECC公钥结构
	//			pucSponsorTmpPublicKey	[OUT]		返回的发起方临时ECC公钥结构
	//			phAgreementHandle		[OUT]		返回的协商句柄，用于计算协商密钥
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	为协商会话密钥，协商的发起方应首先调用本函数。
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
	//计算会话密钥
	//功能描述：使用ECC密钥协商算法，使用自身协商句柄和响应方的协商参数计算会话密钥，同时返回会话密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucSponsorID		[IN]		外部输入的响应方ID值
	//			uiSponsorIDLength	[IN]		外部输入的响应方ID长度
	//			pucResponsePublicKey	[IN]	外部输入的响应方ECC公钥结构
	//			pucResponseTmpPublicKey	[IN]	外部输入的响应方临时ECC公钥结构
	//			phAgreementHandle	[IN]		协商句柄，用于计算协商密钥
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	协商的发起方获得响应方的协商参数后调用本函数，计算会话密钥。使用SM2算法计算会话密钥的过程见GM/T 0009.
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
	//使用ECC密钥协商算法，产生协商参数并计算会话密钥，同时返回产生的协商参数和密钥句柄
	//功能描述：使用ECC密钥协商算法，使用自身协商句柄和响应方的协商参数计算会话密钥，同时返回会话密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		密码设备内部存储加密私钥的索引值，该私钥用于参与密钥协商
	//			uiKeyBits			[IN]		协商后要求输出的密钥长度
	//			pucResponseID		[IN]		响应方ID值
	//			uiResponseIDLength	[IN]		响应方ID长度
	//			pucSponsorID		[IN]		发起方ID值
	//			uiSponsorIDLength	[IN]		发起方ID长度
	//			pucSponsorPublicKey	[IN]		外部输入的发起方ECC公钥结构
	//			pucSponsorTmpPublicKey	[IN]	外部输入的发起方临时ECC公钥结构
	//			pucResponsePublicKey	[OUT]	返回的响应方ECC公钥结构
	//			pucResponseTmpPublicKey	[OUT]	返回的响应方临时ECC公钥结构
	//			phKeyHandle				[OUT]	返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	协商的发起方获得响应方的协商参数后调用本函数，计算会话密钥。使用SM2算法计算会话密钥的过程见GM/T 0009.
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
	//基于ECC算法的数字信封转换
	//功能描述：将由内部加密公钥加密的会话密钥转换为由外部指定的公钥加密，可用于数字信封转换。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex			[IN]		密码设备存储的ECC密钥对索引值
	//			uiAlgID				[IN]		外部ECC公钥的算法标识
	//			pucPublicKey		[IN]		外部ECC公钥结构
	//			pucEncDataIn		[IN]		缓冲区指针，用于存放输入的会话密钥密文
	//			pucEncDataOut		[OUT]		缓冲区指针，用于存放输出的会话密钥密文
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ExchangeDigitEnvelopeBaseOnECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN ECCCipher *pucEncDataIn, //
		OUT ECCCipher *pucEncDataOut //
		);
	/****************************************************************************************************/
	//生成会话密钥并用密钥加密密钥加密输出
	//功能描述：生成会话密钥并用密钥加密密钥加密输出，同时返回密钥句柄。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyBits			[IN]		指定产生的会话密钥长度
	//			uiAlgID				[IN]		算法标识，指定对称加密算法
	//			uiKEKIndex			[IN]		密码设备内部存储密钥加密密钥的索引值，密钥索引号为1--16
	//			pucKey				[OUT]		缓冲区指针，用于存放返回的密钥密文
	//			puiKeyLength		[OUT]		返回的密钥密文长度
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	加密模式采用ECB模式
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
	//导入会话密钥并用密钥加密密钥解密
	//功能描述：导入会话密钥并用密钥加密密钥解密，同时返回会话密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID				[IN]		算法标识，指定对称加密算法
	//			uiKEKIndex			[IN]		密码设备内部存储密钥加密密钥的索引值，密钥索引号为1--16
	//			pucKey				[IN]		缓冲区指针，用于存放输入的密钥密文
	//			puiKeyLength		[IN]		输入的密钥密文长度
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	加密模式采用ECB模式
	DLL_PUBLIC SGD_RV SDF_ImportKeyWithKEK( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN SGD_UINT32 uiKEKIndex, //
		IN SGD_UCHAR *pucKey, //
		IN SGD_UINT32 uiKeyLength, //
		OUT SGD_HANDLE *phKeyHandle //
		);
	/****************************************************************************************************/
	//销毁会话密钥
	//功能描述：销毁会话密钥，并释放为密钥句柄分配的内存等资源
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			hKeyHandle			[IN]		输入的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	在对称算法运算完成后，应调用本函数销毁会话密钥。
	DLL_PUBLIC SGD_RV SDF_DestroyKey( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_HANDLE hKeyHandle //
		);
	/****************************************************************************************************/
	//明文导入会话密钥，返回临时密钥句柄
	//功能描述：明文导入会话密钥，返回临时密钥句柄
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucKey				[IN]		明文密钥值
	//			uiKeyLength			[IN]		密钥长度，必须为16
	//			phKeyHandle			[OUT]		返回的密钥句柄
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
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
	* 非对称算法运算类函数
	*/
	/****************************************************************************************************/
	//外部公钥RSA运算
	//功能描述：指定使用外部公钥对数据进行运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucPublicKey		[IN]		外部RSA公钥结构
	//			pucDataInput		[IN]		缓冲区指针，用于存放输入的数据
	//			uiInputLength		[IN]		输入的数据长度
	//			pucDataOutput		[OUT]		缓冲区指针，用于存放输出的数据
	//			puiOutputLength		[OUT]		输出的数据长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	数据格式由应用层封装。
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
	//内部公钥RSA运算
	//功能描述：指定内部指定索引的公钥对数据进行运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex			[IN]		密码设备内部存储公钥的索引值
	//			pucDataInput		[IN]		缓冲区指针，用于存放输入的数据
	//			uiInputLength		[IN]		输入的数据长度
	//			pucDataOutput		[OUT]		缓冲区指针，用于存放输出的数据
	//			puiOutputLength		[OUT]		输出的数据长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	索引范围仅限于内部签名密钥对，数据格式由应用层封装。
	DLL_PUBLIC SGD_RV SDF_InternalPublicKeyOperation_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucDataInput, //
		IN SGD_UINT32 uiInputLength, //
		OUT SGD_UCHAR *pucDataOutput, //
		OUT SGD_UINT32 *puiOutputLength //
		);
	/****************************************************************************************************/
	//内部私钥RSA运算
	//功能描述：指定内部指定索引的私钥对数据进行运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiKeyIndex			[IN]		密码设备内部存储私钥的索引值
	//			pucDataInput		[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiInputLength		[IN]		输入的数据长度
	//			pucDataOutput		[OUT]		缓冲区指针，用于存放输出的数据
	//			puiOutputLength		[OUT]		输出的数据长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	索引范围仅限于内部签名密钥对，数据格式由应用层封装。
	DLL_PUBLIC SGD_RV SDF_InternalPrivateKeyOperation_RSA( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiKeyIndex, //
		IN SGD_UCHAR *pucDataInput, //
		IN SGD_UINT32 uiInputLength, //
		OUT SGD_UCHAR *pucDataOutput, //
		OUT SGD_UINT32 *puiOutputLength //
		);
	/****************************************************************************************************/
	//外部密钥ECC签名
	//功能描述：使用外部ECC公钥对ECC签名值进行验证运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID				[IN]		算法标识，指定使用的ECC算法
	//			pucPrivateKey		[IN]		外部ECC私钥结构
	//			pucData				[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiDataLength		[IN]		输入的数据长度
	//			pucSignature		[OUT]		缓冲区指针，用于存放输入的签名值数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	输入数据为待签数据的杂凑值。当使用SM2算法时，该输入数据为待签数据经过SM2签名预处理的结构，预处理过程见GM/T 0009.
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
	//外部密钥ECC验证
	//功能描述：使用外部ECC公钥对ECC签名值进行验证运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID				[IN]		算法标识，指定使用的ECC算法
	//			pucPublicKey		[IN]		外部ECC公钥结构
	//			pucDataInput		[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiInputLength		[IN]		输入的数据长度
	//			pucSignature		[IN]		缓冲区指针，用于存放输入的签名值数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	输入数据为待签数据的杂凑值。当使用SM2算法时，该输入数据为待签数据经过SM2签名预处理的结构，预处理过程见GM/T 0009.
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
	//内部密钥ECC签名
	//功能描述：使用内部ECC私钥对数据进行签名运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		密码设备内部存储的ECC签名私钥的索引值
	//			pucData				[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiDataLength		[IN]		输入的数据长度
	//			pucSignature		[OUT]		缓冲区指针，用于存放输出的签名值数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	输入数据为待签数据的杂凑值。当使用SM2算法时，该输入数据为待签数据经过SM2签名预处理的结果，预处理过程见GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_InternalSign_ECC( //
		IN SGD_HANDLE hSessionHandle, //
		IN unsigned int uiISKIndex, //
		IN unsigned char *pucData, //
		IN unsigned int uiDataLength, //
		OUT ECCSignature *pucSignature //
		);
	/****************************************************************************************************/
	//内部密钥ECC验证
	//功能描述：使用内部ECC公钥对ECC签名值进行验证运算
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		密码设备内部存储的ECC签名公钥的索引值
	//			pucDataInput		[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiInputLength		[IN]		输入的数据长度
	//			pucSignature		[IN]		缓冲区指针，用于存放输入的签名值数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	输入数据为待签数据的杂凑值。当使用SM2算法时，该输入数据为待签数据经过SM2签名预处理的结构，预处理过程见GM/T 0009.

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
	//外部密钥ECC公钥加密
	//功能描述：使用外部ECC公钥对数据进行加密运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID				[IN]		算法标识，指定使用的ECC算法
	//			pucPublicKey		[IN]		外部ECC公钥结构
	//			pucData				[IN]		缓冲区指针，用于存放外部输入的数据
	//			uiDataLength		[IN]		输入的数据长度
	//			pucEncData			[OUT]		缓冲区指针，用于存放输出的数据密文
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	输入数据为待签数据的杂凑值。当使用SM2算法时，该输入数据为待签数据经过SM2签名预处理的结果，预处理过程见GM/T 0009.

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
	*对称算法运算类函数
	*/
	/****************************************************************************************************/
	//对称加密
	//功能描述：使用指定的密钥句柄和IV对数据进行对称加密运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			hKeyHandle			[IN]		指定的密钥句柄
	//			uiAlgID				[IN]		算法标识，指定对称加密算法
	//			pucIV				[IN|OUT]	缓冲区指针，用于存放输入和返回的IV数据
	//			pucData				[IN]		缓冲区指针，用于存放输入的数据明文
	//			uiDataLength		[IN]		输入的数据明文长度
	//			pucEncData			[OUT]		缓冲区指针，用于存放输出的数据密文
	//			puiEncDataLength	[OUT]		输出的数据密文长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	此函数不对数据进行填充处理，输入的数据必须是指定算法分组长度的整数倍。

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
	//对称解密
	//功能描述：使用指定的密钥句柄和IV对数据进行对称解密运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			hKeyHandle			[IN]		指定的密钥句柄
	//			uiAlgID				[IN]		算法标识，指定对称加密算法
	//			pucIV				[IN|OUT]	缓冲区指针，用于存放输入和返回的IV数据
	//			pucEncData			[IN]		缓冲区指针，用于存放输入的数据密文
	//			uiEncDataLength		[IN]		输入的数据密文长度
	//			pucData				[OUT]		缓冲区指针，用于存放输出的数据明文
	//			puiDataLength		[OUT]		输出的数据明文长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	此函数不对数据进行填充处理，输入的数据必须是指定算法分组长度的整数倍。
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
	//计算MAC
	//功能描述：使用指定的密钥句柄和IV对数据进行MAC运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			hKeyHandle			[IN]		指定的密钥句柄
	//			uiAlgID				[IN]		算法标识，指定MAC加密算法
	//			pucIV				[IN|OUT]	缓冲区指针，用于存放输入和返回的IV数据
	//			pucData				[IN]		缓冲区指针，用于存放输入的数据明文
	//			uiDataLength		[IN]		输入的数据明文长度
	//			pucMAC				[OUT]		缓冲区指针，用于存放输出的MAC值
	//			puiMACLength		[OUT]		输出的MAC值长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	此函数不对数据进行分包处理，多包数据MAC运算由IV控制最后的MAC值
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
	//杂凑运算类函数
	/****************************************************************************************************/
	//杂凑运算初始化
	//功能描述：使用指定的密钥句柄和IV对数据进行MAC运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiAlgID				[IN]		指定杂凑算法标识
	//			pucPublicKey		[IN]		签名者公钥。当uiAlgID为SGD_SM3时有效。
	//			pucID				[IN]		签名者的ID值，当uiAlgID为SGD_SM3时有效。
	//			uiIDLength			[IN]		签名者ID的长度，当uiAlgID为SGD_SM3时有效。
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	//备注：	uiIDLength非零且uiAlgID为SGD_SM3时，函数执行SM2的预处理1操作，计算过程见GM/T 0009.
	DLL_PUBLIC SGD_RV SDF_HashInit( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UINT32 uiAlgID, //
		IN ECCrefPublicKey *pucPublicKey, //
		IN SGD_UCHAR *pucID, //
		IN SGD_UINT32 uiIDLength //
		);
	/****************************************************************************************************/
	//多包杂凑运算
	//功能描述：三步式数据杂凑运算第二步，对输入的明文进行杂凑运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucData				[IN]		缓冲区指针，用于存放输入的数据明文
	//			uiDataLength		[IN]		输入的数据明文长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_HashUpdate( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucData, //
		IN SGD_UINT32 uiDataLength //
		);
	/****************************************************************************************************/
	//杂凑运算结束
	//功能描述：三步式数据杂凑运算第三步，杂凑运算结束返回杂凑数据并清除中间数据。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucHash				[OUT]		缓冲区指针，用于存放输出的杂凑数据
	//			puiHashLength		[OUT]		返回的杂凑数据长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_HashFinal( //
		IN SGD_HANDLE hSessionHandle, //
		OUT SGD_UCHAR *pucHash, //
		OUT SGD_UINT32 *puiHashLength //
		);

	/*-----------------------------------------------------------------------------
	* 用户文件操作类函数
	*/
	/****************************************************************************************************/
	//创建文件
	//功能描述：在密码设备内部创建用于存储用户数据的文件。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucFileName			[IN]		缓冲区指针，用于存放输入的文件名，最大长度128字节
	//			uiNameLen			[IN]		文件名长度
	//			uiFileSize			[IN]		文件所占存储空间的长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_CreateFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiFileSize //
		);
	/****************************************************************************************************/
	//读取文件
	//功能描述：读取在密码设备内部存储用户数据的文件内容。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucFileName			[IN]		缓冲区指针，用于存放输入的文件名，最大长度128字节
	//			uiNameLen			[IN]		文件名长度
	//			uiOffset			[IN]		指定读取文件时的偏移值
	//			puiReadLength		[IN|OUT]	入参时指定读取文件内容的长度；出参时返回实际读取文件内容的长度
	//			pucBuffer			[OUT]		缓冲区指针，用于存放读取的文件数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_ReadFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiOffset, //
		IN OUT SGD_UINT32 *puiReadLength, //
		OUT SGD_UCHAR *pucBuffer //
		);
	/****************************************************************************************************/
	//写文件
	//功能描述：向密码设备内部存储用户数据的文件中写入内容。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucFileName			[IN]		缓冲区指针，用于存放输入的文件名，最大长度128字节
	//			uiNameLen			[IN]		文件名长度
	//			uiOffset			[IN]		指定写入文件时的偏移值
	//			uiFileLength		[IN]		指定写入文件内容的长度
	//			pucBuffer			[IN]		缓冲区指针，用于存放输入的写文件数据
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_WriteFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen, //
		IN SGD_UINT32 uiOffset, //
		IN SGD_UINT32 uiFileLength, //
		IN SGD_UCHAR *pucBuffer //
		);
	/****************************************************************************************************/
	//删除文件
	//功能描述：删除指定文件名的密码设备内部存储用户数据的文件。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			pucFileName			[IN]		缓冲区指针，用于存放输入的文件名，最大长度128字节
	//			uiNameLen			[IN]		文件名长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_DeleteFile( //
		IN SGD_HANDLE hSessionHandle, //
		IN SGD_UCHAR *pucFileName, //
		IN SGD_UINT32 uiNameLen //
		);
	/****************************************************************************************************/
	//内部ECC私钥解密
	//功能描述：使用内部ECC私钥对数据进行解密运算。
	//                 
	//参数：    
	//          hSessionHandle      [IN]        与密码设备已建立的会话句柄
	//			uiISKIndex			[IN]		内部ECC加密密钥ID
	//			uiAlgID				[IN]		算法标识，指定使用的ECC算法
	//			pucEncData			[IN]		缓冲区指针，用于存放外部输入的密文数据
	//			pucData				[OUT]		缓冲区指针，用于存放输出的数据
	//			uiDataLength		[OUT]		输出的数据长度
	//返回值：  0 成功
	//			非0 失败，返回错误代码。
	DLL_PUBLIC SGD_RV SDF_InternalDecrypt_ECC(IN SGD_HANDLE hSessionHandle,	IN SGD_UINT32 uiISKIndex,unsigned int uiAlgID,ECCCipher *pucEncData,unsigned char *pucData,unsigned int *uiDataLength);
	//指定内部对称密钥加密
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
	//指定内部对称密钥解密
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
