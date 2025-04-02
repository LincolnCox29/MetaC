#include "MetaC.h"
#include "stdio.h"

int main()
{
	String str = string_create("Hello");
	str.print(&str);
	str.replace(&str, 0, 'h');
	str.print(&str);
	printf("%llu", str.length(&str));
	str.free(&str);
}
