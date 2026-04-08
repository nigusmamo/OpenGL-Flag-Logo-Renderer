# Makefile for Guyana Flag & Logo Renderer

# Detect the Operating System
ifeq ($(OS),Windows_NT)
    # Windows Settings (MinGW)
    LIBS = -lfreeglut -lopengl32 -lglu32
    TARGET = flag_app.exe
    RM = del
else
    # macOS Settings
    LIBS = -framework OpenGL -framework GLUT
    TARGET = flag_app
    RM = rm -f
endif

# Default task: Compile and Run
all: build run

# Compile the source code
build:
	g++ src/main.cpp -o $(TARGET) $(LIBS)

# Execute the program
run:
	./$(TARGET)

# Clean up build files
clean:
	$(RM) $(TARGET)