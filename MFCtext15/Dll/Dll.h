// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// �����Ǵ� Dll.dll ������
class DLL_API CDll {
public:
	CDll(void);
	// TODO: �ڴ�������ķ�����
};
class DLL_API FACD{
	public:
	FACD(){}
	float convert(float deg);
};
extern DLL_API int nDll;

DLL_API int fnDll(void);

DLL_API int factorial_1(int n);
