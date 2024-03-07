g++ main.cpp \
src/colors.h src/colors.cpp \
src/grid.h src/grid.cpp \
src/position.h src/position.cpp \
src/block.h src/block.cpp src/blocks.cpp \
src/game.h src/game.cpp \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
-g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -std=c++20