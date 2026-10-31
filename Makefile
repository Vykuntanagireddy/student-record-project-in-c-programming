student: main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o stud_util.o
	cc main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o stud_util.o -o student

main.o: main.c header.h
	cc -c main.c

stud_add.o: stud_add.c header.h
	cc -c stud_add.c

stud_del.o: stud_del.c header.h
	cc -c stud_del.c

stud_show.o: stud_show.c header.h
	cc -c stud_show.c

stud_mod.o: stud_mod.c header.h
	cc -c stud_mod.c

stud_save.o: stud_save.c header.h
	cc -c stud_save.c

stud_sort.o: stud_sort.c header.h
	cc -c stud_sort.c

stud_util.o: stud_util.c header.h
	cc -c stud_util.c

clean:
	rm -f *.o student
