#include "wc_devoir.h"
int main(int argc, char* argv[])
{
	int n;
	FILE* file=NULL;
	open(&file);
	n=options(file,argv);
	affichage(n);
	fclose(file);
	return 0;
}
