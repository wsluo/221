# 221

## System requirement
Raspberry Pi 4 running Linux

## Enable ARM CPU counter register access from userspace
By default the user space program has no access to the cycle counter. For this purpose, load a custom kernel module. See [this post](https://matthewarcus.wordpress.com/2018/01/27/using-the-cycle-counter-registers-on-the-raspberry-pi-3/).
