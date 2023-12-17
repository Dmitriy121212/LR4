#ifndef HELLO1_H
#define HELLO1_H
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
int print_hello(uint cnt);
#endif
