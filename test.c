#include "MetaC.h"
#include "stdio.h"

int main()
{
	// test create
	MCString str = MCString_create("Hello");
	// test print
	MCString_print(&str);
	//test replace
	MCString_replace(&str, 0, 'h');
	MCString_print(&str);
	//test length
	printf("%llu\n", MCString_length(&str));
	//test delete
	MCString_delete(&str, 2);
	MCString_print(&str);
	//test append
	MCString_push_back(&str, '!');
	MCString_print(&str);
	//test at
	printf("%c\n", MCString_at(&str, 0));
	//test insert
	MCString_insert(&str, 'l', 2);
	MCString_print(&str);
	//test free
	MCString_free(&str);
}
