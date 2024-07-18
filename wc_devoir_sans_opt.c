#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void open(FILE* file);
int count_line(FILE* file);
int countWord(FILE* file);
int count_char(FILE* file);
//void affichage(int n, int x);;
int main()
{
	///int dim=0;
	int n;
	int x;
	FILE* file=NULL;
	open(file);
	n=count_line(file);
	countWord(file);
	x=count_char(file);
	//affichage(n,x);
	return 0;
}

void open(FILE* file)
{
	file=fopen("/var/log/auth.log","r");
	if(file==NULL)
	{
		printf("Erreur pendant l'ouverture du fichier\n");
	}
	else
	{
		printf("\n");
	}
	fclose(file);
}
int count_line(FILE* file)
{
	int n=0;
	char line[300];
	file=fopen("/var/log/auth.log","r");
	while(fgets(line,300,file))
	{
		n++;
	}
	printf("%d ",n);
	fclose(file);
	return (n);
}

int countWord(FILE* file){
	int num=0;
	char *row=malloc(1000);
	file=fopen("/var/log/auth.log","r");
	while(fgets(row, 300, file)){
		for(char *tmp1=strtok(row, " "); tmp1!=NULL ; tmp1=strtok(NULL, " ")){
			num++;
		}
	}
	printf("%d ", num);
	return num;
}
int count_char(FILE* file)
{
	int x=0;
	file=fopen("/var/log/auth.log","r");
	while(fgetc(file)!=EOF)
	{
		x++;
	}
	printf("%d ",x);
	fclose(file);
	return (x);
}

