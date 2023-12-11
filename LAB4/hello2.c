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





void print_hello(void)

{

	if (myIntCheck == 0 || (myIntCheck>5 && myIntCheck<10)){

		pr_warn("!!! Warning !!!");

	}

	for (int i = 0; i < myIntCheck; ++i)

	{

		addMyData();

		pr_info("%d hi hi hullo", i);

	}

}

