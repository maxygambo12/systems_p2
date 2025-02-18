CC = gcc
CFLAGS = -Wall -g
OBJS = analyze_scores.o analysis_functions.o

runScores: $(OBJS)
	$(CC) $(CFLAGS) -o runScores $(OBJS)

analyze_scores.o: analyze_scores.c analysis_functions.h
	$(CC) $(CFLAGS) -c analyze_scores.c

analysis_functions.o: analysis_functions.c analysis_functions.h
	$(CC) $(CFLAGS) -c analysis_functions.c

clean:
	rm -f *.o runScores