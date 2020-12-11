import commands
import numpy as np

def avg(name,repeat):
    a=[]
    for i in range(repeat):
        x=float(commands.getstatusoutput('sudo nice -n -20 taskset -c 0 ./'+name)[1])
        a.append(x)
    print(a)
    return np.mean(a),np.std(a);

##counter overhead
#print avg('counter_overhead',100)

##loop overhead experiments
print avg('loop_overhead',100)

##call overhead experiments
#for i in range(3):
#    print avg('call_overhead '+str(i),100)

##syscall overhead experiments
#print avg('syscall_overhead',100)

##process creation
#print avg('process_creation_overhead',1000)
