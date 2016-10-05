#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//oblig 1 - inf1060 
//tnbildst


//Oppgave 3.a)
struct datetime {
	int year, month, date;
	int hour, minute, second;
};

//Oppgave 3.b)
void init_datetime(struct datetime *dt, int year){
	(*dt).year = year;
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

//Oppgave 3.d)
void datetime_diff(struct datetime *dt_from, struct datetime *dt_to, struct datetime *dt_res){
	int distanceyear = (*dt_from).year - (*dt_to).year;
	int distancemonth = (*dt_from).month - (*dt_to).month;
	int distancedate = (*dt_from).date - (*dt_to).date;
	
	int differencehour = (*dt_from).hour - (*dt_to).hour;
	int differenceminute = (*dt_from).minute - (*dt_to).minute;
	int differenceseconds = (*dt_from).second - (*dt_to).second;
	
	printf("dt_from time: %d/%d/%d\n", (*dt_from).year, (*dt_from).month, (*dt_from).date);
	printf("dt_to date: %d/%d/%d\n", (*dt_to).year, (*dt_to).month, (*dt_to).date);
	printf("\tdt_res: %d years, %d months and %d days difference in date\n", distanceyear, distancemonth, distancedate);
	
	printf("dt_from time: %d:%d:%d\n", (*dt_from).hour, (*dt_from).minute, (*dt_from).second);
	printf("dt_to date: %d:%d:%d\n", (*dt_to).hour, (*dt_to).minute, (*dt_to).second);
	printf("\tdt_res: %d hours, %d minutes and %d seconds difference in time\n", differencehour, differenceminute, differenceseconds);
	
	
	datetime_set_date(dt_res, distanceyear, distancemonth, distancedate);
	datetime_set_time(dt_res, differencehour, differenceminute, differenceseconds);
	
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
	
	//datetime_diff
	struct datetime dt_from;
	datetime_set_date(&dt_from, 2016,9,15);
	datetime_set_time(&dt_from, 22,18,40);
	
	struct datetime dt_to;
	datetime_set_date(&dt_to, 2014,7,11);
	datetime_set_time(&dt_to, 16,15,30);
	
	struct datetime dt_res;
	datetime_diff(&dt_from, &dt_to, &dt_res);
	printf("dt_res difference: %d/%d/%d\n", dt_res.year, dt_res.month, dt_res.date);
	printf("dt_res difference: %d:%d:%d\n", dt_res.hour, dt_res.minute, dt_res.second);
	
}