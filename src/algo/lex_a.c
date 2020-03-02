#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_delimiter(char ch)
{
	if ( ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
	     ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
	     ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
	     ch == '[' || ch == ']' || ch == '{' || ch == '}') 
	{
		return true;
	}
	return false;
}

bool is_operator(char ch)
{
	if ( ch == '+' || ch == '-' || ch == '*' ||
	     ch == '/' || ch == '>' || ch == '<' ||
	     ch == '=') 
	{
		return true;
	}
	return false;
}

bool is_valid_id(char *str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
	    str[0] == '3' || str[0] == '4' || str[0] == '5' ||
	    str[0] == '6' || str[0] == '7' || str[0] == '8' ||
	    str[0] == '9' || is_delimiter(str[0] == true))
	{
		return false;
	}
	return true;
}

bool is_integer(char *str)
{
	int i;
	int len = strlen(str);

	if (len == 0)
		return false;

	for (i = 0; i < len; i++) {
		if ((str[i] != '0' && str[i] != '1' && str[i] != '2' &&
		     str[i] != '3' && str[i] != '4' && str[i] != '5' &&
		     str[i] != '6' && str[i] != '7' && str[i] != '8' &&
		     str[i] != '9') || (str[i] == '-' && i > 0))
		{
			return false;
		}
	}
	return true;
}

bool is_R_num(char *str)
{
	int i;
	int len = strlen(str);
	bool has_dec = false;

	if (len == 0) {
		return false;
	}
	for (i = 0; i < len; i++) {
		if ((str[i] != '0' && str[i] != '1' && str[i] != '2' &&
		    str[i] != '3' && str[i] != '4' && str[i] != '5' &&
		    str[i] != '6' && str[i] != '7' && str[i] != '8' &&
		    str[i] != '9' && str[i] != '.') || (str[i] == '-' && i > 0))
		{
			return false;
		}
		if (str[i] == '.') {
			has_dec = true;
		}
	}
	return has_dec;
}

char *sub_string(char *str, int left, int right) 
{ 
    	int i; 
    	char* sub_str = (char *) malloc(sizeof(char) * (right - left + 2)); 
  
    	for (i = left; i <= right; i++) 
    		sub_str[i - left] = str[i]; 

   	sub_str[right - left + 1] = '\0'; 
   	return (sub_str); 
}

void parse(char *str)
{
	int left = 0;
	int right = 0;

	int len = strlen(str);

	while (right <= len && left <= right) {

		if (is_delimiter(str[right]) == false) {
			right++;
		}

		if (is_delimiter(str[right]) == true && left == right) {
			if (is_operator(str[right]) == true) {
				printf("%c OPERATOR\n", str[right]);
			}

			right++;
			left = right;
		}
		else if (is_delimiter(str[right]) == true && left != right || (right == len && left != right)) {
			char *sub_str = sub_string(str, left, right - 1);
			
			if (is_integer(sub_str)) {
				printf("%s INTEGER\n", sub_str);
			}
			else if (is_R_num(sub_str)) {
				printf("%s REAL_NUMBER\n", sub_str);
			}
			else if (!is_valid_id(sub_str)) {
				printf("%s NOT VALID ID\n", sub_str);
			}

			left = right;
		}

	}

	return;
}

/*
 *	TEMPORARY MAIN FOR TESTING PURPOSES
 */

int main(int argc, char **argv)
{
	char *expression = "int a = 10.2";
	parse(expression);

	return 0;
}