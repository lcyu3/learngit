#ifndef DOUFEI_MULTIBITMAP_HEADER
#define DOUFEI_MULTIBITMAP_HEADER
#include <memory>
#define  BITS_ONE_INT 32
#define  SHIFT 5
#define  MASK 0x1F
class CMultiBitMap
{
public:
	CMultiBitMap(const size_t size = 0) ;
	~CMultiBitMap() ;

	inline bool setBit(size_t i, bool bitValue) ;//���õ�iλ��bitValue,true��ʾ1��false��ʾ0
	inline bool getBit(size_t i) ; //�жϵ�iλ�Ƿ���1
	inline void setAll(bool bitValue) ; //�������е�bit��1��0
	inline size_t oneCount() ; //ͳ��1�ĸ���

	void resize(size_t newSize) ; //���·����С��ԭ���Ŀռ䶼��ɾ��������ԭ�������ݲ����


private:
	int *bits ; //�洢���е�bits
	size_t bitSize ; //bitλ�ĸ���
};

inline bool CMultiBitMap :: setBit(size_t i, bool bitValue)
{
	if (i >= bitSize) return false ; //����ʧ�ܣ�������Χ
	if (bitValue)
		bits[i >> SHIFT] |= (1 << (i & MASK)) ;
	else
		bits[i >> SHIFT] &= ~(1 << (i & MASK)) ;
	return true ;
}

inline bool CMultiBitMap :: getBit(size_t i)
{
	 if (bits[i >> SHIFT] & (1 << (i & MASK)) )
		 return true ;
	 else
		  return false ;
}

inline void CMultiBitMap :: setAll(bool bitValue) 
{

	size_t intCount = bitSize >> SHIFT ;
	if (bitSize & MASK)
		intCount ++ ;

	if (bitValue)
		memset(bits, 0xFF, sizeof(int) * intCount) ;
	else
		memset(bits, 0x00, sizeof(int) * intCount) ;
}

inline size_t CMultiBitMap :: oneCount()
{
	size_t ret = 0 ;
	for (size_t i = 0; i < bitSize; ++ i)
		if (getBit(i)) ++ret;
	return ret ;
}
#endif