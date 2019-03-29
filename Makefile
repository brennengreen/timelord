CXX = g++
CXXFLAGS = -Wall -g
SRCDIR = src/
BUILDDIR = build/
target = bin/timelord

$(target): $(BUILDDIR)main.o
	$(CXX) $(CXXFLAGS) -o $(target) $(BUILDDIR)main.o

$(BUILDDIR)main.o: $(SRCDIR)main.cpp $(SRCDIR)timelord.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)main.cpp -o $(BUILDDIR)main.o
