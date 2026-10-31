CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o stud_util.o
TARGET = student

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) student.dat
