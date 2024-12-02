all:  dijkstra_large dijkstra_small

dijkstra_large: dijkstra_large.c Makefile
	${CC} -static dijkstra_large.c -O3 -o dijkstra_large

dijkstra_small: dijkstra_small.c  ../../timers/timers.c Makefile
	${CC} -static dijkstra_small.c  ../../timers/timers.c -O3 -o dijkstra_small 

clean:
	rm -rf dijkstra_large dijkstra_small output*
