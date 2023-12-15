CC = gcc
CFLAGS = -Wall
BUILD_DIR = build
SOURCES := $(wildcard *.c tests/*.c)
OBJECTS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES))
customasm = customasm/customasm customasm/arch.asm

.PHONE: decoder_test

build/%.o : %.c 
	mkdir -p build/tests
	$(CC) $(CFLAGS) -c $< -o $@


decoder_test: $(customasm) scripts/generate_decoder_test.py  customasm/decoder_test.asm $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/decoder_test $(OBJECTS)
	python scripts/generate_decoder_test.py
