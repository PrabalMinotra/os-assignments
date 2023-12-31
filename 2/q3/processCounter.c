#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

//metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rayyan_Hussain and Mehul_Agarwal");

static int __init processCounterInit(void){
    printk("Process Counter module loaded.\n");

    struct task_struct *currProcess = NULL;
    int counter = 0;

    for_each_process(currProcess){
        if(currProcess -> __state == 0){
            counter += 1;
        }
    }

    printk("The number of processes running are: %d\n", counter);
    return 0;
}

static void __exit processCounterExit(void){
    printk("Exiting Process Counter module.\n");
}

module_init(processCounterInit);
//This runs until return
module_exit(processCounterExit);
//This runs after init is done.
