CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -g
OBJECTS = cell.o grid.o subject.o textdisplay.o main.o
DEPENDS = ${OBJECTS:.o}
        EXEC = LightsOut

${EXEC} : ${OBJECTS}
            ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
            rm ${DEPENDS} ${OBJECTS}

-include ${DEPENDS}
