#ifndef INC_NMEA_GPZDA_H
#define INC_NMEA_GPZDA_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>
#include <sys/time.h>

typedef struct {
	nmea_s base;
	unsigned int year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minutes;
	unsigned char seconds;
	unsigned int milliseconds;
} nmea_gpzda_s;

/* Value indexes */
#define NMEA_GPZDA_TIME				0
#define NMEA_GPZDA_DAY				1
#define NMEA_GPZDA_MONTH			2
#define NMEA_GPZDA_YEAR				3
#define NMEA_GPZDA_LOCAL_HOURS		4
#define NMEA_GPZDA_LOCAL_MINUTES	5


#endif  /* INC_NMEA_GPZDA_H */
