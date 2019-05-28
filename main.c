/************************************************************

   main.c
     copyright 2019.05.28 konoar
 
 ***********************************************************/
#include <stdio.h>
#include <regex.h>

void substr(char *buff, const char *data, int st, int ed)
{

	for (int idx = 0; idx < (ed - st); idx++) {
		buff[idx] = data[st + idx];
	}

	buff[ed - st] = '\0';

}

int main(int argc, const char *argv[])
{

	const char *data = "http://api.kono.site/action";
	char buff[256];

	regex_t reg;
	regmatch_t mat[2];

	if (regcomp(&reg, "^https?://api\\.kono\\.site/(\\w+)$", REG_EXTENDED)) {
		return 1;
	}

	if (regexec(&reg, data, 2, mat, 0) == 0) {
		substr(buff, data, mat[1].rm_so, mat[1].rm_eo);
		printf("match: %s!\n", buff);
	} else {
		printf("not!\n");
	}

	return 0;

}

