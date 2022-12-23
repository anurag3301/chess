CXX=g++
CXXFLAGS=-g -Wall $$(pkgconf --cflags sfml-graphics)
CXX_LIBS=$$(pkgconf --libs sfml-graphics)
TARGETS=main
all: $(TARGETS)

main: main.o
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS)

run: $(TARGETS)
	clear && ./$(TARGETS)
