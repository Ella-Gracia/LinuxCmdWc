#include "wc_devoir.h"

void open(FILE** file)
{
	*file=fopen("/var/log/auth.log","r");
	if(*file==NULL)
	{
		printf("Erreur pendant l'ouverture du fichier\n");
	}
	else
	{
		printf("Ouverture réussie\n");
	}
}
int options(FILE* file,char* argv[])
{
	int n=0;
	char line[3000];
	if(strcmp(argv[1],"-l")==0)
	{
		while(fgets(line,300,file))
		{
			n++;
		}
	}
	else if(strcmp(argv[1],"-m")==0||strcmp(argv[1],"-c")==0 )
	{
		while(fgetc(file)!=EOF)
		{
			n++;
		}
	}
	else if(strcmp(argv[1],"-w")==0) 
	{
		char *row=malloc(1000);
		while(fgets(row, 300, file)){
			for(char *tmp1=strtok(row, " "); tmp1!=NULL ; tmp1=strtok(NULL, " ")){
				n++;
			}
		}
	}
	else if(strcmp(argv[1],"-L")==0)
	{
		int first_line=0;
		file=fopen("/var/log/auth.log","r");
		fgets(line,255,file);
		first_line=strlen(line);
		n=first_line;
			while(fgets(line,1000,file))
			{
				first_line=strlen(line);
				if(n<first_line)
				{
					n=first_line-1;
				}
			}
	}
	 else if(strcmp(argv[1],"--help")==0)
	{
		file=fopen("aide.txt","r");
		while(fgets(line,300,file)!= 0)
		{
			printf("%s",line);
		}
	}
	else if(strcmp(argv[1],"--version")==0)
	{
		file=fopen("version","r");
		while(fgets(line,300,file)!= 0)
		{
			printf("%s",line);
		}
	}
	else
	{
		printf("option invalide\nSaisissez l'option--help » pour plus d'informations");

	}
	return (n);
}
void affichage(int n)
{
	printf("%d\n",n);
}

