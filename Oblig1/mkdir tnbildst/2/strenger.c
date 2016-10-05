#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//oblig 1 - inf1060 
//tnbildst


//Oppgave 2.b)
int stringsum(char *s){
	char streng[sizeof(s)];
	strcpy(streng,s);
	
	int i;
	int sum = 0;
	for(i = 0; i < strlen(streng); i++){
		if(streng[i] >= 'A' && streng[i] <= 'Z'){
			sum += streng[i];
			sum -= 64;
		}
		else if(streng[i] >= 'a' && streng[i] <= 'z'){
			sum += streng[i];
			sum -= 96;
		}
		else{
			return -1;
		}
	}
	printf("Sum av %s = %d\n", s, sum);
    return 0;
}

//Oppgave 2.c)
int distance_between(char *s, char c){
	char streng[sizeof(s)];
	strcpy(streng,s);
	
	int i;
	int antall = 0;
	int avstand;
	for(i = 0; i < strlen(streng); i++){
		if(streng[i] == c){
			antall++;
		}
		if(antall > 0 && antall <= 2){
			avstand ++;
		}
	}
	if(antall < 2){
		return -1;
	}
	printf("Avstanden er %d\n", avstand);
	return avstand;
}

//Oppgave 2.d)
char* string_between(char *s, char c){
	char streng[sizeof(s)];
	strcpy(streng,s);
	
	int i;
	int antall = 0;
	int start = 0;
	int end = 0;
	char *substr;
	for(i = 0; i < strlen(streng); i++){
		if(streng[i] == c){
			antall++;
		}
		if(antall == 1 && start == 0){
			start = i;
		}
		if(antall == 2 && end == 0){
			end = i;
		}
	}
	//printf("%d\n", start);
	//printf("%d\n", end);
	if(start != 0 && end != 0){
		substr = malloc(200);
		strncpy(substr, s+start, end-1);
		return substr;
	}
	return NULL;
}

//Oppgave 2.c) - 
char **split(char *s){
	//mallokeres med antall ord + 1 for null terminering
	char **nystreng = malloc((sizeof(char*)*3)+1);
	
	char str[strlen(s)+1];
	int i;
	for(i = 0; i < strlen(s)+1; i++){
		
		if(i != strlen(s)+1){
			str[i] = s[i];
		}
		else {
			str[i] = '\0';
		}
	}
	char *temp;
	temp = strtok(str, " ");
	int teller = 0;
	while(temp != NULL){
		nystreng[teller] = malloc(strlen(temp));
		strcpy(nystreng[teller], temp);
		temp = strtok(NULL, " ");
		teller++;
	}
	nystreng[teller++] = NULL;
	
	//free(nystreng);
	
	return nystreng;

}

//Oppgave 2.g)
void stringsum2(char *s, int *res){
	char streng[sizeof(s)];
	strcpy(streng,s);
	
	int i;
	int sum = 0;
	for(i = 0; i < strlen(streng); i++){
		if(streng[i] >= 'A' && streng[i] <= 'Z'){
			sum += streng[i];
			sum -= 64;
		}
		else if(streng[i] >= 'a' && streng[i] <= 'z'){
			sum += streng[i];
			sum -= 96;
		}
	}
	*res = sum;
	printf("Sum av %s ble lagt inn i res og har nå verdien %d\n", s, *res);
}

int main(void){
	//sum av streng
	stringsum("abcd");
	
	//avstand mellom c
	distance_between("a123a", 'a');
	
	//string between
	char* test = string_between("a1234a", 'a');
	printf("String between: %s\n", test);
	
	//stringsum2
	int res;
	stringsum2("abcd", &res);
	
	//split 
	char **test2 = split("hei du der");
	int i= 0;
	printf("Split:");
	for(i = 0; i < 3; i++){
		printf("%s ", test2[i]);
	}
}








