#include <utils/string.h>

int replace_if_match_str(const char *source, char **dest, const char *pattern)
{
	if(strstr(source, pattern))
	{
		char temp[512];
		const x = 3;
		strcpy(temp, source + strlen(pattern) + x);

		// Remove the new line character
		char *pos;
		if((pos = strchr(temp, '\n')) != NULL)
			*pos = '\0';

		// Allocating memory for dest pointer, + 1 for null character
		*dest = malloc(sizeof(char) * strlen(temp + 1));
		if(*dest != NULL) {
			strcpy(*dest, temp);
			return 1;
		}
		else {
			printf("error allocating memory\n");
			return 0;
		}
	}
	else
		return 0;
}

int replace_if_match_int(const char *source, int *dest, const char *pattern)
{
	if(strstr(source, pattern))
	{
		char temp[512];
		const x = 3;
		strcpy(temp, source + strlen(pattern) + x);

		// Remove the new line character
		char *pos;
		if((pos = strchr(temp, '\n')) != NULL)
			*pos = '\0';

		char *pend;
		*dest = strtol(temp, &pend, 10);
		if(*pend == '\0')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}