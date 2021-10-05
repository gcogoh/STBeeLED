target remote localhost:3333
monitor reset halt
load
thbreak main
continue
b src/main.c:65
b src/main.c:90
