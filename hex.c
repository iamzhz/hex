#include <stdio.h>
#include "mycon.h"

int main(int argc, char *argv[])
{
	if(argc < 2) return 0;
	FILE *fp=fopen(argv[1], "rb");
	if(fp == NULL){
		set_color(0x0, 0x4);
		puts("ERROR");
		set_color(0x0, 0xF);
		return 0;
	}
	set_color(0x0, 0x9);
	puts("00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F");
	set_color(0x0, 0x1);
	char ch;
	int i = 0;
	ch=fgetc(fp);
	while(!feof(fp))      
    {
        if(ch < 0x10)
		printf("0%X ", ch);
		else
		printf("%X ", ch);
		
		ch=fgetc(fp);
		i += 1;
		if(i == 0x10){
			puts("");
			i = 0;
		}
	}
	fclose(fp);
	set_color(0x0, 0xF);
	return 0;
}
