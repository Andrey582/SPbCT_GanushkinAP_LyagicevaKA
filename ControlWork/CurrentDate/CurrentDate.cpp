#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <ctime>
int main()
{
	struct tm* date;
	char Current_date[20];
	const time_t timer = time(NULL);
	date = localtime(&timer);
	strftime(Current_date, 20, "%d.%m.%Y", date);
	printf("%s\n", Current_date);
	system("pause");
	return 0;
}