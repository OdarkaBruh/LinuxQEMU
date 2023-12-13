#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <linux/list.h>
#include "hello1.h"

int myIntCheck = 1;

module_param(myIntCheck, int, 0644);
MODULE_PARM_DESC(myIntCheck, "uint");
MODULE_INFO(myIntCheck, "How many to print hullo");

//в hello1.h було змінено, що воно тепер повертає int.
int print_hello(void)
{
	return -EINVAL;
}
