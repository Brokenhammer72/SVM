SOURCE_FILE = main.c
OUTPUT_FILE = vm

all: build run

build:
	gcc $(SOURCE_FILE) -o $(OUTPUT_FILE)

run:
	./$(OUTPUT_FILE)
