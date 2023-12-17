#include "hello1.h"

MODULE_AUTHOR("Dima Bryzgalov <Bryzgalov174@ukr.net>");
MODULE_DESCRIPTION("Module for lab 4");
MODULE_LICENSE("Dual BSD/GPL");

static uint cnt = 1;
MODULE_PARM_DESC(cnt,"this parameter shows us, how many times Hello world! will be outputted");
module_param(cnt, uint, S_IRUGO);

static int __init hello_init(void)
{
	print_hello(cnt);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("exiting module 2...");
}

module_init(hello_init);
module_exit(hello_exit);

