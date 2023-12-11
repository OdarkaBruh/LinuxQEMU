#include <linux/init.h>

#include <linux/module.h>

#include <linux/printk.h>

#include<linux/slab.h>

#include <linux/ktime.h>

#include <linux/list.h>



MODULE_AUTHOR("Nokhrina Daria");

MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");

MODULE_LICENSE("Dual BSD/GPL");



static int myIntCheck = 1;



module_param(myIntCheck, int, 0644);

MODULE_PARM_DESC(myIntCheck, "uint");

MODULE_INFO(myIntCheck, "How many to print hullo");





struct myData {

    ktime_t myTime;

    struct list_head list;

};



static LIST_HEAD(myData);



static void addMyData(void)

{

	struct myData *newTime;

	newTime = kmalloc(sizeof(*newTime), GFP_KERNEL);

	newTime->myTime = ktime_get();

	list_add_tail(&newTime->list, &myData);

}



static void printMyData(void)

{

	struct myData *ptr, *next;

    	list_for_each_entry_safe(ptr, next, &myData, list) {

    		printk(KERN_INFO "Time: %lld", ktime_to_ns(ptr->myTime));


        list_del(&ptr->list);

        kfree(ptr);

    	}

}



static int __init custom_init(void) {

	

	if (myIntCheck > 10) {

		return -EINVAL;

	}

	else if (myIntCheck == 0 || (myIntCheck>5 && myIntCheck<10)){

		printk("Warning");

	}

	

	printk(KERN_INFO "Hello world driver loaded.");

	for (int i = 0; i < myIntCheck; ++i)

	{

		addMyData();

		printk("%d hi hi hullo", i);

	}

	

 	return 0;

}

static void __exit custom_exit(void) {



	printk("	First");

	printMyData();

	printk("	Second");

	printMyData();

 	printk(KERN_INFO "Goodbye my friend, I shall miss you dearly...");

 	

}



module_init(custom_init);

module_exit(custom_exit);
