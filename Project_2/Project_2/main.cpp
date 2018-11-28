#include "Hash.h"
#include "Counter.h"
int main(int argc, char *argv[])
{

	for (int i = 1; i != 0; i *= 2)
		printf("%d\t%d\n", i, hash(i));
	printf("%d\t%d\n", 0, hash(0));
	for (int i = -1; i != 0; i *= 2)
		printf("%d\t%d\n", i, hash(i));
	for (float i = 1.0; i < 1000; i *= 2.0)
		printf("%f\t%d\n", i, hash(i));
	for (double i = 1.0; i < 1000; i *= 2.0)
		printf("%f\t%d\n", i, hash(i));
	printf("\n=========\n");
	printf("%d\n", hash(QString("HER")));
	printf("%d\n", hash(QString("HERA")));
	printf("%d\n", hash(QString("HERB")));
	printf("%d\n", hash(QString("HERb")));

	printf("%d\n", hash<QString>(QString("HER")));
	printf("%d\n", hash<QString>(QString("HERA")));
	printf("%d\n", hash<QString>(QString("HERB")));
	printf("%d\n", hash<QString>(QString("HERb")));
	Counter<int> c;
	return 0;
}