#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("Guillaume Pagnoux");
MODULE_DESCRIPTION("Greet module");
MODULE_LICENSE("GPL v2");

static int nb_greet;
static char name[20];

module_param(nb_greet, int, 0644);
module_param_string(name, name, sizeof(name), 0444);

__init static int greet_init(void)
{
	int i;
	for (i = 0; i < nb_greet; i++)
		pr_info("Greetings, %s\n", name);

	return 0;
}

__exit static void greet_exit(void)
{
	int i;
	for (i = 0; i < nb_greet; i++)
		pr_info("Goodbye, %s\n", name);
}

module_init(greet_init);
module_exit(greet_exit);
