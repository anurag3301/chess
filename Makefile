CXX=g++
CXXFLAGS=-g -Wall $$(pkgconf --cflags sfml-graphics)
CXX_LIBS=$$(pkgconf --libs sfml-graphics)
TARGETS=main
TEST=test
all: $(TARGETS)

main: main.o
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) $^ -o $@

main.o: main.cpp Board.h Piece.h utils.h Chess.h
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS)

run: $(TARGETS)
	./$(TARGETS)

test: test.o
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) $^ -o $@

test.o: test.cpp
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) -c $< -o $@

