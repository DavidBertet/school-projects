SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_VERBOSE_MAKEFILE on)

PROJECT(jdv CXX)

include_directories(
 ./
 display/
 loader/
 error/
 ants/
 cells/
 cells/pheromones/
 random/
 rules/
)

SET(JDV_SRCS
 main
 game
 map
 team
 display/ascii
 display/display
 loader/maploader
 error/maperror
 error/opterror
 ants/ant
 ants/killableant
 ants/fighter
 ants/foodworker
 ants/queen
 ants/waterworker
 cells/cell
 cells/ground
 cells/resource
 cells/scenery
 cells/pheromones/pheromone
 cells/pheromones/fighterpheromone
 cells/pheromones/queenpheromone
 cells/pheromones/foodpheromone
 cells/pheromones/waterpheromone
 random/random
 rules/standardrules
 rules/rules
 )

ADD_EXECUTABLE(jdv ${JDV_SRCS})
