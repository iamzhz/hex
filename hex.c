#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mycon.h"

void showHex(int number);
int main(int argc, char *argv[])
{
	char *filename = NULL;
	int column = 16; // column number
	int i;
	int ch;
	// parse command-line parameters
	for(i = 1;  i<=(argc-1);  i ++) {
		if(!strcmp(argv[i], "-f")) {
			filename = argv[i+1];
			i ++;
		}else if(!strcmp(argv[i], "-c")) {
			column = atoi(argv[i+1]);
			i ++;
		}
	}
	if(filename == NULL) {
		printf(" > hex -f [file name] (-c [column number])\n");
		return 0;
	}

	FILE *fp=fopen(filename, "rb");
	if(fp == NULL) {
		set_color(0x0, 0x4);
		printf("Connot open file `%s`. \n", filename);
		set_color(0x0, 0xF);
		return 0;
	}
	// show top line
	set_color(0x0, 0x9);
	for(i = 0;  i < column;  i++) showHex(i);
	printf("\n");
	// show hex
	set_color(0x0, 0xF);
	i = 0;
	ch=fgetc(fp);
	while(!feof(fp)) {
        showHex(ch);
		ch=fgetc(fp);
		i ++;
		if(i == column){
			puts("");
			i = 0;
		}
	}
	fclose(fp);
	set_color(0x0, 0xF);
	return 0;
}
void showHex(int number) {
	if(number < 0x10) printf("0%X ", number);
	else printf("%X ", number);
}
