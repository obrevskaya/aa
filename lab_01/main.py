import matplotlib.pyplot as plot
import math
import numpy as np

file = open("test.txt", "r")

index = []
lev = []
dam = []
damRC = []

index1 = []
lev1 = []
dam1 = []
damRC1 = []
damR1 =[]

numbers = []
x = 0
while True:
    line = file.readline()

    x += 1
    if not line:
        break

    numbers = [int(x) for x in line.split()]
    if (x < 10):
        index1.append(numbers[0])
        lev1.append(numbers[1])
        dam1.append(numbers[2])
        damR1.append(numbers[3])
        damRC1.append(numbers[4])


    index.append(numbers[0])
    lev.append(numbers[1])
    dam.append(numbers[2])
    damRC.append(numbers[4])

plot.figure(1)
plot.ylabel("Время (в тиках)")
plot.xlabel("Длина слова")
plot.grid(True)

plot.plot(index, lev, color = "red", label = "Итеративный (Левенштейн)")
plot.plot(index, dam, color = "yellow", label = "Итеративный (Дамерау - Левенштейн)")
plot.plot(index, damRC, color = "blue", label = "Рекурсивный  с кэшем (Дамерау - Левенштейн)")

plot.legend(loc="upper left")
plot.savefig("test.pdf")

plot.figure(2)
plot.ylabel("Время (в тиках)")
plot.xlabel("Длина слова")
plot.grid(True)

plot.plot(index1, lev1, color = "red", label = "Итеративный (Левенштейн)")
plot.plot(index1, dam1, color = "yellow", label = "Итеративный (Дамерау - Левенштейн)")
plot.plot(index1, damR1, color = "blue", label = "Рекурсивный  с кэшем (Дамерау - Левенштейн)")
plot.plot(index1, damRC1, color = "green", label = "Рекурсивный  с кэшем (Дамерау - Левенштейн)")

plot.legend(loc="upper left")
plot.savefig("test4.pdf")