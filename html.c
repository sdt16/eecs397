#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE 50

void open_tag(char tag[], char attribute[])
{
	char buf[BUFFER_SIZE];
	buf[0] = '\0';
	strncat(buf, "<", 1);
	strncat(buf, tag, strlen(tag));
	strncat(buf, strlen(attribute)>0?" ":"", 1);
	strncat(buf, attribute, strlen(attribute));
	char* final_string = strncat(buf, ">", 1);
	printf("%s", final_string);
}


void close_tag(char tag[])
{
	char buf[BUFFER_SIZE];
	buf[0] = '\0';
	strncat(buf, "</", 2);
	strncat(buf, tag, strlen(tag));
	char* final_string = strncat(buf, ">", 1);
	printf("%s", final_string);
}


int main(int argc, char* argv[])
{
	open_tag("html", "");
	printf("\n");
	open_tag("body", "");
	open_tag("p", "");
	printf("Hey There!");
	close_tag("p");
	printf("\n");
	open_tag("p", "");
	printf("You can search for things on the internet at:\n");
	open_tag("ul", "");
	printf("\n");
	open_tag("li", "");
	open_tag("a", "href=\"http://www.google.com\"");
	printf("Google");
	close_tag("a");
	close_tag("li");
	printf("\n");
	open_tag("li", "");
	open_tag("a", "href=\"http://www.bing.com\"");
	printf("Bing");
	close_tag("a");
	close_tag("li");
	printf("\n");
	close_tag("ul");
	printf("\n");
	close_tag("p");
	printf("\n");
	close_tag("body");
	printf("\n");
	close_tag("html");
	printf("\n");
	return 0;
}
