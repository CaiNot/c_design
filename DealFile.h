/*
**����ȼƻ�ָ����������ݰ���һ���ĸ�ʽд���ļ�
*/

#include "Content.h"
/*
**@parameter year: ��ȼƻ���ͷָ��;
**@parameter pFile: ��ֻд��ʽ�򿪵��ļ�ָ��;
**
**@return value: 0 �ļ�ָ��ΪNULL
**				-1 ��������
**				 1 һ������
*/
int writeFile(Year *year, FILE *pFile);

/*
**@parameter year: Ҫд�����ȼƻ���ͷָ��;
**@parameter pFile: ��ֻ����ʽ�򿪵��ļ�ָ��;
**
**@return value: 0 �ļ�ָ��ΪNULL
**				-1 ��������
**				 1 һ������
*/
int readFile(Year* year, FILE *pFile);

