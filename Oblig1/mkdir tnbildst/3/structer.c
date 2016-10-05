#include <stdio.h>
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

	
int main(void){
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