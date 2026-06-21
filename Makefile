CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra

LDFLAGS = $(SDL_LIBS) \
          -lSDL2_ttf \
          -lSDL2_image

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS   := $(shell sdl2-config --libs)

INCLUDES = -Iinclude

SRC = \
src/main.cpp \
src/core/Game.cpp \
src/core/StateMachine.cpp \
src/core/TextureManager.cpp \
src/states/BootState.cpp \
src/states/AimState.cpp \
src/states/ShootState.cpp \
src/states/ResultState.cpp \
src/states/GameOverState.cpp \
src/entities/GoalKeeper.cpp	\
src/entities/Ball.cpp \
src/ui/TextRenderer.cpp \
src/ui/HUD.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = PenaltyShootout2

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)