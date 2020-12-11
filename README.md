# 221

## System requirement
Raspberry Pi 4 running 32-bit Linux

## Enable ARM CPU counter register access from userspace
By default the user space program has no access to the cycle counter. To enable the use of the register for timestamping, you must load a custom kernel module. See [this post](https://matthewarcus.wordpress.com/2018/01/27/using-the-cycle-counter-registers-on-the-raspberry-pi-3/).

If modification is needed for already installed kernal module, use
```
sudo rmmod enable_ccr
sudo insmod enable_ccr.ko
```

## Fixing the CPU frequency
```
cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor

sudo sh -c "echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"

sudo sh -c "echo 750000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed"
```

## CPU operations

```
gcc -Wall -O0 counter_overhead.c -o ./counter_overhead
sudo nice -20 taskset -c 0 ./counter_overhead

gcc -Wall -O0 loop_overhead.c -o ./loop_overhead
sudo nice -20 taskset -c 0 ./loop_overhead

gcc -Wall -O0 call_overhead.c -o ./call_overhead
sudo nice -20 taskset -c 0 ./call_overhead

gcc -Wall -O0 syscall_overhead.c -o ./syscall_overhead
sudo nice -20 taskset -c 0 ./syscall_overhead

gcc -Wall -O0 thread_creation_overhead.c -o thread_creation_overhead -lpthread
sudo nice -20 taskset -c 0 ./thread_creation_overhead

gcc -Wall -O0 process_creation_overhead.c -o process_creation_overhead -lpthread
sudo nice -20 taskset -c 0 ./process_creation_overhead

```

`calc_average.py` can then be modified to repeat tests with specific repeat numbers.


## memory operations
```
gcc -Wall -O0 memory_access.c -o memory_access
sudo nice -20 taskset -c 0 ./memory_access

gcc -Wall -O0 memory_bandwidth.c -o memory_bandwidth -lm
sudo nice -20 taskset -c 0 ./memory_bandwidth
```

## networking
```
gcc client.c -o client -lm
gcc server.c -o server
```
Start the server first `./server`, then run the client `./client`


## file system operations
First create the test file.
```
truncate -s 8G test.dat
```
The run the tests.
```
gcc -Wall -O0 -D_GNU_SOURCE  file_cache_size.c -o file_cache_size -lm
sudo nice -20 taskset -c 0 ./file_cache_size

gcc -Wall -O0 -D_GNU_SOURCE file_read_time.c -o file_read_time -lm
sudo nice -20 taskset -c 0 ./file_read_time

gcc -Wall -O0 -D_GNU_SOURCE contention.c -o contention -lm
sudo nice -20 taskset ./contention
```


