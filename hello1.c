#include "hello1.h"


MODULE_AUTHOR("Dima Bryzgalov <Bryzgalov174@ukr.net>");
MODULE_DESCRIPTION("Module for lab 4");
MODULE_LICENSE("Dual BSD/GPL");

struct list {
	struct list_head l;
	ktime_t t1;
	ktime_t t2;
} *ptr;

static LIST_HEAD(head);

struct list2 {
	struct list_head l2;
	ktime_t t_diff;
} *ptr2;
static LIST_HEAD(head2);
int print_hello(uint cnt)
{
	if( (cnt == 0) || (cnt > 4 && cnt < 11) ) {
		pr_warn("Warning!\n");
		int i = 0;
		for(i = 0;i < cnt;i++){
			ptr = kmalloc(sizeof(*ptr), GFP_KERNEL);
			ptr2 = kmalloc(sizeof(*ptr2), GFP_KERNEL);
			list_add_tail(&ptr->l,&head);
			ptr->t1 = ktime_get();
			printk(KERN_INFO "Hello, world!\n");
			ptr->t2 = ktime_get();
			ptr2->t_diff = (ptr->t2) - (ptr->t1);
			list_add_tail(&ptr->l,&head);
			list_add_tail(&ptr2->l2,&head2);
		}
		
}
	if (cnt > 10) {
		pr_err("Error! cnt must be <= 10");
		return -EINVAL;		
}
	return 0;
}

EXPORT_SYMBOL(print_hello);
static int __init hello_init(void)
{
	pr_info("Module 1 starting...");
	return 0;
}
static void __exit hello_exit(void)
{
	struct list *cur, *next;
	struct list2 *cur2, *next2;
	list_for_each_entry_safe(cur2, next2, &head2, l2) {
	
	long long time_difference = ktime_to_ns(cur2->t_diff);
	pr_info("time difference: %lld\n", time_difference);
	list_del(&cur2->l2);
	kfree(cur2);
	
	}
	list_for_each_entry_safe(cur, next, &head, l) {
	list_del(&cur->l);
	kfree(cur);

	}
	BUG_ON(!list_empty(&head));

}
module_init(hello_init);
module_exit(hello_exit);

