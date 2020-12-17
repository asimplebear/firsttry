CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = system_helper.o system.o
TARGET = system

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

#this works alone:
objects: $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
