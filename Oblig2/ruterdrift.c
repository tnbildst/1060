#include <stdio.h>
#include <stdlib.h> //to use atoi(string) - check if string is an int, if not int value == 0

struct router {
	unsigned char routerID;
	char flagg;
	unsigned char lengthProd;
	char modell[0];
};

void init_router(struct router *rt, unsigned char routerID, char flagg, unsigned char lengthProd, char modell[]){
	(*rt).routerID = routerID;
	(*rt).flagg = flagg;
	(*rt).lengthProd = lengthProd;
	//(*rt).modell = malloc(sizeof(struct router) + (253-1));
	(*rt).modell[0] = *modell;
}


int main(int argc, char *argv[]){
	//sjekk om riktig argumenter
	if(argc != 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}
	
	//åpner fil
	FILE *fil = fopen(argv[1], "r");
	if(fil == NULL){
		fprintf(stderr, "Couldn't open file: %s\n", argv[1]);
		return -1;
	}
	
	int line = 0;
	char buf[256];
	int intNum;
	//char *buf2 = buf[0];
	//char *buf3 = malloc(256); //må free-es
	while(fgets(buf, 256, fil) != NULL){
		//intNum = atoi(buf);
		if(line == 0){
			printf("numer of routers: %d\n", buf);
		}
		printf("line %d: %s\n", line, buf);
		
		line++;
	}
	
	//printf("\nData from file: %s\n", buf);
	
	fclose(fil);
	
	return 0;
}