TARGET=SmartCalc
FLAGS=-Wall -Werror -Wextra -std=c11
CC=gcc $(FLAGS)
FILE=s21_calc
MODULES=modules/*
FILETEST=tests/*
FILEREPORT=s21_test_report
FILETESTO=s21_test
DIRREPORT=report
COVFLAG=-fprofile-arcs -ftest-coverage

OS = $(shell uname)

ifeq ($(OS), Darwin)
	TESTFLAGS=-pthread -lm -lcheck
	OPEN_CMD=open
else
	TESTFLAGS=-pthread -lcheck_pic -lrt -lm -lsubunit
	OPEN_CMD=xdg-open
endif


all: clean gcov_report install

#####################################
# all: temp

# temp:
# 	$(CC) -fsanitize=address -g *.c  zmain/*.c $(TESTFLAGS)

# compile:
# 	$(CC) *.c zmain/*.c $(TESTFLAGS)

# val:
# 	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./a.out
#####################################

install:
	mkdir ./build
	mkdir ~/Desktop/$(TARGET)/
	cd ./build && qmake ../gui/ && make && cp gui ~/Desktop/SmartCalc/$(TARGET).app \
	&& mv gui $(TARGET).app
	
uninstall:
	rm -rf ~/Desktop/$(TARGET) ./build

dist:
	mkdir dist
	mkdir dist/src
	cp -r gui/ tests/ modules/ Makefile *.c *.h *.html dist/src/
	cd ./dist && tar cvzf $(TARGET)_v1.0.tgz *
	rm -rf dist/src/

dvi:
	$(OPEN_CMD) s21_smart_calc.html

test: 
	$(CC) $(FILETEST).c *.c $(MODULES).c -o $(FILETESTO) $(TESTFLAGS)
	./$(FILETESTO)

test_val: 
	$(CC) $(FILETEST).c *.c $(MODULES).c -o $(FILETESTO) $(TESTFLAGS)
	valgrind --tool=memcheck --log-file="valgrind_check.log" --leak-check=yes \
	--track-origins=yes -s ./$(FILETESTO)

gcov_report:
	$(CC) $(COVFLAG) $(FILETEST).c *.c $(MODULES).c -o $(FILEREPORT) $(TESTFLAGS)
	./$(FILEREPORT)
	lcov -t "$(FILE)" -o test.info -c -d .  
	genhtml -o $(DIRREPORT) test.info
	rm -rf *.o *.a *.gcno *.gcda *.info *.log $(FILETESTO) $(FILEREPORT)
	$(OPEN_CMD) $(DIRREPORT)/index.html

rep: gcov_report

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.log $(DIRREPORT) $(FILETESTO) $(FILEREPORT) ./build* ./dist

#style
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h $(MODULES).c

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h $(MODULES).c
	rm -rf .clang-format

check: cpp clang
