#include <linux/init.h>

#include <linux/module.h>

#include <linux/printk.h>

#include <linux/slab.h>

#include <linux/ktime.h>

#include <linux/list.h>



#include "hello1.h"



MODULE_AUTHOR("Nokhrina Daria");

MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");

MODULE_LICENSE("Dual BSD/GPL");





struct myData {

    ktime_t mySTime;

    ktime_t myETime;

    struct list_head list;

};



static LIST_HEAD(myData);



void addMyData(void)

{

	struct myData *newTime;

	newTime = kmalloc(sizeof(*newTime), GFP_KERNEL);

	newTime->mySTime = ktime_get();

	list_add_tail(&newTime->list, &myData);

	newTime->myETime = ktime_get();

}



static int __init custom_init(void) {

	if (myIntCheck > 10) {

		return -EINVAL;

	}

	pr_info("Hello world driver loaded.");

	print_hello();

 	return 0;

}



static void printMyData(void)

{

	struct myData *ptr, *next;

    	list_for_each_entry_safe(ptr, next, &myData, list) {

    		pr_info("Time: %lld", ktime_to_ns(ptr->mySTime));

    		pr_info("TimeTaken: %lld", ktime_to_ns(ptr->myETime - ptr->mySTime));

        list_del(&ptr->list);



        kfree(ptr);



    	}



}



static void __exit custom_exit(void) {

	printk("	First");

	printMyData();

	printk("	Second");

	printMyData();

 	pr_info("Goodbye my friend, I shall miss you dearly...");

}



module_init(custom_init);

module_exit(custom_exit);
