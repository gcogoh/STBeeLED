#target remote localhost:3333
target remote localhost:50000
monitor reset halt
load
thbreak main
continue
