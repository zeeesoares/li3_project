CC = gcc
CFLAGS := -lncurses -lm -I./include/ -Wall -O3 -g $(shell pkg-config --cflags glib-2.0)
LDFLAGS := $(shell pkg-config --libs glib-2.0) -lm -lncurses
SOURCES := ./src/batch.c ./src/interactive.c ./src/menu.c ./src/load_dataset.c ./src/results_output.c ./src/help.c ./src/execute_query.c ./src/draw.c ./src/draw_outputs.c ./src/catalog_manager.c ./src/date.c ./src/user.c ./src/user_catalog.c ./src/flight.c ./src/flights_catalog.c ./src/output.c ./src/parser.c ./src/stats.c ./src/passengers_catalog.c ./src/hotel ./src/hotel_catalog ./src/airport ./src/airport_catalog ./src/reservation.c ./src/reservation_catalog.c ./src/queries.c ./src/utils.c ./src/query_services.c./src/main.c ./tests/programa-teste.c

all: programa-principal programa-testes

programa-principal: batch.o interactive.o menu.o load_dataset.o results_output.o help.o execute_query.o draw.o draw_outputs.o catalog_manager.o date.o user.o user_catalog.o flight.o flights_catalog.o output.o parser.o stats.o passengers_catalog.o reservation.o reservation_catalog.o queries.o utils.o hotel.o hotel_catalog.o airport.o airport_catalog.o query_services.o main.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

programa-testes: programa-teste.o batch.o catalog_manager.o date.o user.o user_catalog.o flight.o flights_catalog.o output.o parser.o stats.o passengers_catalog.o reservation.o reservation_catalog.o queries.o utils.o hotel.o hotel_catalog.o airport.o airport_catalog.o query_services.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

programa-teste.o: ./tests/programa-teste.c
	$(CC) $(CFLAGS) -c $< -o $@

batch.o : ./src/batch.c
	$(CC) $(CFLAGS) -c $< -o $@

catalog_manager.o : ./src/catalog_manager.c
	$(CC) $(CFLAGS) -c $< -o $@

date.o : ./src/date.c
	$(CC) $(CFLAGS) -c $< -o $@

user.o : ./src/user.c
	$(CC) $(CFLAGS) -c $< -o $@

user_catalog.o : ./src/user_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

flight.o : ./src/flight.c
	$(CC) $(CFLAGS) -c $< -o $@

flights_catalog.o : ./src/flights_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

output.o : ./src/output.c
	$(CC) $(CFLAGS) -c $< -o $@

stats.o : ./src/stats.c
	$(CC) $(CFLAGS) -c $< -o $@

parser.o : ./src/parser.c
	$(CC) $(CFLAGS) -c $< -o $@

passengers_catalog.o : ./src/passengers_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

reservation.o : ./src/reservation.c
	$(CC) $(CFLAGS) -c $< -o $@

reservation_catalog.o : ./src/reservation_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

hotel.o : ./src/hotel.c
	$(CC) $(CFLAGS) -c $< -o $@

hotel_catalog.o : ./src/hotel_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

airport.o : ./src/airport.c
	$(CC) $(CFLAGS) -c $< -o $@

airport_catalog.o : ./src/airport_catalog.c
	$(CC) $(CFLAGS) -c $< -o $@

queries.o : ./src/queries.c
	$(CC) $(CFLAGS) -c $< -o $@

query_services.o : ./src/query_services.c
	$(CC) $(CFLAGS) -c $< -o $@

utils.o : ./src/utils.c
	$(CC) $(CFLAGS) -c $< -o $@

draw.o : ./src/draw.c
	$(CC) $(CFLAGS) -c $< -o $@

draw_outputs.o : ./src/draw_outputs.c
	$(CC) $(CFLAGS) -c $< -o $@

menu.o : ./src/menu.c
	$(CC) $(CFLAGS) -c $< -o $@

help.o : ./src/help.c
	$(CC) $(CFLAGS) -c $< -o $@

execute_query.o : ./src/execute_query.c
	$(CC) $(CFLAGS) -c $< -o $@

load_dataset.o : ./src/load_dataset.c
	$(CC) $(CFLAGS) -c $< -o $@

results_output.o : ./src/results_output.c
	$(CC) $(CFLAGS) -c $< -o $@

interactive.o : ./src/interactive.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: ./src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./programa-principal
	./programa-testes

clean:
	rm programa-principal
	rm programa-testes
	rm *.o
	rm Resultados/flights_errors.csv
	rm Resultados/reservations_errors.csv
	rm Resultados/passengers_errors.csv
	rm Resultados/users_errors.csv
	rm Resultados/*.txt

