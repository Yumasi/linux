#include <linux/module.h>

MODULE_AUTHOR("Guillaume Pagnoux");
MODULE_DESCRIPTION("Hello World module");
MODULE_LICENSE("GPL v2");

__init static int hello_init(void)
{
	pr_info("Hello World!\n");

	return 0;
}

__exit static void hello_exit(void)
{
	pr_info("Goodbye World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
