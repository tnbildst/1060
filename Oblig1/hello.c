#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Oppgave 3.a)
struct datetime {
	int hour, minute, second;
	int year, month, date;
};

//Oppgave 3.b)
void init_datetime(struct datetime *dt, int year){
	(*dt).year = year;
	(*dt).month = month;
	(*dt).date = date;
}

//Oppgave 3.c)
void datetime_set_date(struct datetime *dt, int year, int month, int date){
	(*dt).year = year;
	(*dt).month = month;
	(*dt).date = date;
}

//Oppgave 3.c)
void datetime_set_time(struct datetime *dt, int hour, int minute, int second){
	(*dt).hour = hour;
	(*dt).minute = minute;
	(*dt).second = second;
}

void datetime_diff(struct datetime *dt_from), struct datetime *dt_to, struct datetime *dt_res){
	
}

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

//Oppgave 2.c) - fungerer ikke som den skal
char **split(char *s){
	char **splitstreng = malloc(sizeof(s));
	
	int teller = 0;
	char c = s[teller];
	char *nystreng;
	int antOrd = 0;
	while(c != '\0'){
		if(c != ' '){
			int len = strlen(nystreng);
			nystreng[len] = c;
			nystreng[len+1] = '\0';
		}
		else {
			splitstreng[antOrd] = nystreng;
			antOrd++;
			teller ++;
		}
		teller++;
	}
	return splitstreng;
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

int main(int argc, char *argv[]){
	//Oppgave 1.a) print argument
	printf("%s\n",argv[1]);
	
	//sum av streng
	stringsum("abcd");
	
	//avstand mellom c
	distance_between("a123a", 'a');
	
	//string between
	char* test = string_between("a1234a", 'a');
	printf("String between: %s\n", test);
	
	//split 
	//char **testsplit = split("hei du der");
	//printf("%s\n",testsplit);
	
	//stringsum2
	int res;
	stringsum2("abcd", &res);
	
	//initialisere struct datetime
	struct datetime dt;
	init_datetime(&dt, 2016);
	
}















