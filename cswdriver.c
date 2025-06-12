#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
 // prints the processs id, 
 printk(KERN_ALERT "The process is pid %i\n", current->parent->pid);

 return 0;
}

static void hello_exit(void)
{
    for(int i=0; i<5; i++) {
        printk(KERN_ALERT "wubba lubba dub dub\n");
    }

    printk(KERN_ALERT "Voluntary context switches: %lu\n", current->parent->nvcsw);
    printk(KERN_ALERT "Involuntary context switches: %lu\n", current->parent->nivcsw);
}

module_init(hello_init);
module_exit(hello_exit);
