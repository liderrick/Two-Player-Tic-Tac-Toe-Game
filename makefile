#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++0x

#Project executable output file
PROJ = project

#Object files
OBJS = main.o Board.o TicTacToe.o

#Source files
SRCS = main.cpp Board.cpp TicTacToe.cpp

#Header files
HEADERS = Board.hpp TicTacToe.hpp

#Compile project executable from object files
${PROJ}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJ}

#Compile object files from source files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Remove project executable and object files
clean:
	rm ${PROJ} ${OBJS}

#Citation:
#Format of this makefile based off of: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4