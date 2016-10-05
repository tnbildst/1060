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

void print_File(char *filnavn){
	//åpner fil
	FILE *fil = fopen(filnavn, "r");
	if(fil == NULL){
		fprintf(stderr, "Couldn't open file: %s\n", filnavn);
	}
	
	int line = 0;
	char buf[256];
	//printf("\nData from file: %s\n", buf);
	int intNum;
	while(fgets(buf, 256, fil) != NULL){
		//intNum = atoi(buf);
		if(line == 0){
			printf("numer of routers: %d\n", buf);
		}
		printf("line %d: %s\n", line, buf);
		
		line++;
	}
		
	fclose(fil);
}

void write_To_File(char *filnavn, char *str){
	FILE *fil = fopen(filnavn, "a");
    int i;
   
    if (fil == NULL) {
		printf("I couldn't open %s for writing.\n", filnavn);
        exit(0);
    }

	fprintf(fil, "%s\n", str);
	fclose(fil);
}


int main(int argc, char *argv[]){
	//sjekk om riktig argumenter
	if(argc != 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}
	
	//print
	print_File(argv[1]);
	
	return 0;
}





