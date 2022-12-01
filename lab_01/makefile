CC=g++
SRCDIR := src
OUTDIR := out
DEF := 

all: clean | app.exe

app.exe: $(OUTDIR) $(OUTDIR)/main.o $(OUTDIR)/levenshtein.o $(OUTDIR)/matrix.o 
	$(CC) $(OUTDIR)/main.o $(OUTDIR)/levenshtein.o $(OUTDIR)/matrix.o -o $@
	
$(OUTDIR) :
	mkdir $@

test: DEF += -DTEST
test: clean | test.exe
	touch test.txt
	./test.exe >> test.txt
	python main.py
	
test.exe: $(OUTDIR) $(OUTDIR)/main.o $(OUTDIR)/levenshtein.o $(OUTDIR)/matrix.o $(OUTDIR)/test.o 
	$(CC) $(OUTDIR)/main.o $(OUTDIR)/levenshtein.o $(OUTDIR)/matrix.o $(OUTDIR)/test.o -o $@

$(OUTDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp $(DEF) -o $@
	
$(OUTDIR)/levenshtein.o: $(SRCDIR)/levenshtein.cpp $(SRCDIR)/levenshtein.h
	$(CC) -c $(SRCDIR)/levenshtein.cpp -o $@

$(OUTDIR)/matrix.o: $(SRCDIR)/matrix.cpp $(SRCDIR)/matrix.h
	$(CC) -c $(SRCDIR)/matrix.cpp -o $@

$(OUTDIR)/test.o: $(SRCDIR)/test.cpp $(SRCDIR)/test.h
	$(CC) -c $(SRCDIR)/test.cpp -o $@

clean:
	rm -f ./*.exe
	rm -rf ./$(OUTDIR)
	rm -f test.txt
	rm -f test.pdf
	rm -f test4.pdf
