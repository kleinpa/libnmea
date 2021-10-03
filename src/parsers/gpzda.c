#include "../nmea/parser_types.h"
#include "gpzda.h"
#include "parse.h"

#include <stdio.h>

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPZDA);
	NMEA_PARSER_PREFIX(parser, "GPZDA");
	NMEA_PARSER_PREFIX(parser, "GNZDA");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_gpzda_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_gpzda_s));
	nmea_gpzda_s *data = (nmea_gpzda_s *) parser->data;
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gpzda_s *data = (nmea_gpzda_s *) parser->data;

	switch (val_index) {
	case NMEA_GPZDA_TIME:
        /* Parse time */
        if (nmea_time_ms_parse(value, &data->hour, &data->minutes,
                               &data->seconds, &data->milliseconds) < 0) {
		  printf("error parsing time\n");
          return -1;
        }
        break;


	case NMEA_GPZDA_DAY:
		data->day = atoi(value);
		break;

	case NMEA_GPZDA_MONTH:
		data->month = atoi(value);
		break;

	case NMEA_GPZDA_YEAR:
		data->year = atoi(value);
		break;

	default:
		break;
	}

	return 0;
}
