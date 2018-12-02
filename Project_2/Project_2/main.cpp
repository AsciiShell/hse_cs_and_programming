#include "Hash.h"
#include "Counter.h"
int main(int argc, char *argv[])
{

	Counter<QString> c;
	for (int i = 0; i < 100; i++)
		c.addKey("qwe" + QString::number(i));
	return 0;
}
