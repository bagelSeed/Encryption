CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = keysgen
OBJECTS = keysgen.o keysgenerator.o primenumgenerator.o algebra.o
DEPENDS = ${OBJECTS:.o=.d}
 
${EXEC}: ${OBJECTS}
        ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
 
-include ${DEPENDS}
 
.PHONY: clean
 
clean:
        rm ${OBJECTS} ${EXEC} ${DEPENDS}
