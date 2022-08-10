#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 512 // 1行の最大文字数(バイト数)
#define V 1024

typedef struct {
	char date[N];
	char title[N];
} Videos;

int main()
{
	Videos vdo[V];
	FILE *fp;
	char str[N];
	char* ptr;
	int i=0,j;

	fp = fopen("data.txt", "r");						/* ファイルのオープン */

	if (fp == NULL){
		printf("そのファイルは存在しません\n");
		return 0;
	}

	while(fgets(str, N, fp) != NULL) {
		ptr = strtok(str, "\"");
		ptr = strtok(NULL, "\"");
		if(ptr == 0) continue;
		if(strlen(ptr)){
			if(strncmp("publishedAt", ptr,11)==0){
				ptr = strtok(NULL, "\"");
				ptr = strtok(NULL, "\"");
				strncpy(vdo[i].date,ptr,N);
				printf("%s	", vdo[i].date);
				continue;
			}
		}
		if(strlen(ptr)){
			if(strncmp("title", ptr,5)==0){
				ptr = strtok(NULL, "\"");
				ptr = strtok(NULL, ",");
				ptr[strlen(ptr)-1] = '\0';
				strncpy(vdo[i].title,ptr,N);
				printf("%s\n", vdo[i].title);
				i++;
				continue;
			}
		}
	}

	fclose(fp);								/* ファイルのクローズ */


	return 0;
}