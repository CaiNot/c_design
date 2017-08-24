#include "Content.h"
#include "DealFile.h"

void main() {
	FILE *pFileToRead = fopen("d://test_2.txt", "r"), *pFileToWrite = fopen("d://test_3.txt", "w");
	Year *year=NULL;
	year = mallocYear(year);

	readFile(year, pFileToRead);
	fclose(pFileToRead);
	writeFile(year, pFileToWrite);
	fclose(pFileToWrite);
}