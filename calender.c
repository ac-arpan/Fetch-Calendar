#include<stdio.h>
#include<stdlib.h>

int get_1st_weekday(int year)
{
	int day;
	day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
	return day;
}
int main()
{
	system("Color 0B");
	int year,month,day,weekDay = 0,startingDay;
	printf("Enter any Year : ");
	scanf("%d",&year);
	
	char *months[] = {"January","February","March","Arpil","May","June","July","August","September","October","November","December"};
	int monthDays[] ={31,28,31,30,31,30,31,31,30,31,30,31};
	
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			monthDays[1] = 29;
	}
	
	startingDay = get_1st_weekday(year);
	
	for(month=0;month < 12;month++)
	{
	
		printf("\n\n\n------------------%s-----------------------\n",months[month]);
		printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		
		for(weekDay = 0;weekDay < startingDay; weekDay++)
		{
			printf("     ");
		}
		
		for(day=1 ; day<=monthDays[month] ; day++)
		{
			printf("%5d",day);
			
			if(++weekDay > 6)
			{
				printf("\n");
				weekDay = 0;
			}
			startingDay = weekDay;	
		}
	}
	
	return 0;
}
