CC = g++
CXXFLAGS = -std=c++11 
EXEC_NAME = jeux
#SRC= $(wildcard *.cpp)
SRC = Unite.cpp Catapulte.cpp Fantassin.cpp SuperSoldat.cpp Archer.cpp CJoueur.cpp CAireJeux.cpp
CLASSES = $(SRC:.cpp=)
SRC += jeux.cpp
OBJ_FILES = $(SRC:.cpp=.o)

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp %.hpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
