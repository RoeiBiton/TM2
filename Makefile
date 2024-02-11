CC=gcc
FLAGS =-Wall -g

all: my_graph my_Knapsack

libmy_mat.so: my_mat.o my_mat.h
	$(CC) $(FLAGS) -shared -fpic -o $@ $^

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c


my_graph: my_graph.o libmy_mat.so
	$(CC) $(FLAGS) my_graph.o ./libmy_mat.so -o my_graph

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) my_Knapsack.o -o my_Knapsack

clean:
	rm -f *.o *.so my_graph my_Knapsack


