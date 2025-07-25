# Cub3D - 3D Raycasting Game Engine

A 42 School project that creates a 3D graphical representation of a maze using raycasting techniques, similar to classic games like Wolfenstein 3D.

## 📋 Project Overview

Cub3D is an advanced graphics project that builds upon concepts from so_long, implementing:
- Ray casting algorithm for 3D rendering
- Texture mapping and image manipulation
- Real-time player movement and rotation
- Flood fill map validation
- Event handling and graphics optimization

## 🎯 Learning Objectives

- Understand and implement raycasting algorithms
- Master 3D graphics concepts using 2D techniques
- Work with image buffers and pixel manipulation
- Optimize graphics rendering performance
- Handle mathematical calculations for 3D projection

## 🛠️ Setup and Installation

This game is for Linux, and Subsystems of it (like WSL for Windos)

### 🔔 Prerequisites
Theese can be installed with the command below
- MinilibX library
- GCC compiler
- Github
- Make
- Math library (-lm)

### 👨🏼‍💻 Installing Prerequisites
If you are missing some prerequisites, run this command, to install all the neccesary packages:
(Admin/Sudo priviliges required)
   ```bash
   sudo apt install build-essential gcc git make
   ```

### ⬇️ Installation Steps
1. Clone the repository
	```bash
   git clone https://github.com/Idriz4work/Cube3dd.git cub3d
   ```
2. Navigate into repository
	```bash
   cd cub3d
   ```
3. Compile the project:
   ```bash
   make
   ```
### 🕹 Running the game
The game requires a map file, which holds information about the map, which the game should load<br/>
The repository comes prepared with some maps, in the "maps" folder<br/>
Maps have to satisfy certain requirements, which the program will complain about if invalid<br/>

Different ways of running the game:
1. Quick Run:
Will run the game with the pre-delivered "test.cub" map file
	```bash
   make run
   ```
2. Custom Map:
Replace MAP_PATH with something like "./maps/test.cub"<br/>
Replace "test" from that with whatever other name your map has<br/>
The map has to be in a ".cub" format
	```bash
   ./cub3d MAP_PATH
   ```

### 🌏 Map Files
Map Files have to hold 3 types of information<br/>
There should only be 1 of theese per line<br/>
1.	4x A path to a texture file per corresponding wall<br/>
	WALL_IDENTIFIER: WALL_TEXTURE<br/>
	You will need to specify the direction for the wall, and then the texture file<br/>
	WALL IDENTIFIERs are "NO", "SO", "WE" or "EA"<br/>
	WALL_TEXTURE is the file, which has to be in an xpm file format<br/>
	It is also expected that theese files are 64x64 pixels<br/>
	Example:<br/>
	NO: ./textures/rick.xpm<br/>
2.	2x Color data for the ceiling and floor<br/>
	IDENTIFIER RED_VALUE, GREEN_VALUE, BLUE_VALUE<br/>
	IDENTIFIERs are 'C' or 'F'<br/>
	The rgb values should be between (including) 0-255<br/>
	Example:<br/>
	C 0, 69, 255<br/>
3.	The map<br/>
	The map consists of ' ', '1', '0' and a single identifer for the player<br/>
	Player identifers are 'N', 'E', 'S', or 'W', corresponding to the initial direction of the player<br/>
	' ' are Empty Spaces, they can seperate map pieces, but may not be encountered by the player<br/>
	'1' are walls, they limit the players movement and view, and should encase the player<br/>
	'0' are free spaces, allowing the player to move on them<br/>
	The player may be surrounded by free spaces, but the area HAS TO be surrounded in walls.<br/>
 	Example:<br/>
	111111<br/>
  	1E01011<br/>
  	1100001<br/>
  	 1111111<br/>

The map should be the last piece of information in the file<br/>
All Map files are text files in the ".cub" file format<br/>
You can open the maps in the "maps" folder with a text editor for some examples<br/>

## 🎮 Controls
- **W/A/S/D**: Move forward/left/backward/right
- **Arrow Keys**: Rotate view left/right, Move forward/backward
- **ESC**: Exit game

## 📚 Recommended Resources

- Raycasting tutorials and mathematical explanations
- MinilibX documentation
- Computer graphics fundamentals
- Game development optimization techniques

## 📁 Project Structure

```
cub3d/
├── headers/
├── includes/
│   ├── Libft/
│   ├── minilibx-linux/
├── maps/
├── sources/
│   ├── hooks/
│   ├── movement/
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   ├── utils/
│   └── main.c
├── textures/
├── Makefile
└── README.md
```

## 🔧 Key Data Structures

### Core Structure<br/>
Used in almost all functions, central memory storage for the game<br/>
```c
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*tex[NUM_TEXTURES];
	int 	action;
	double	pos_x;
	double	pos_y;
	double	rot;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	t_img	*image;
	t_map	*minfo;
	int 	frame;
	int 	fps;
	time_t	oldtime;
}	t_data;
```
MLX Image Data is stored in this, for easier acces to attributes<br/>
```c
typedef struct s_img
{
    void    *img;
    int     *addr;
    int     bpp;
    int     line_length;
    int     endian;
} t_img;
```
Stores information from parsing into memory<br/>
```c
typedef struct s_map
{
	char	**grid;
	int 	width;
	int 	height;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int 	floor_color[3];
	int 	ceiling_color[3];
}	t_map;
```

## 🗺️ Implementation Roadmap

### Phase 1: Environment Setup and Parsing
- [x] Set up MinilibX environment
- [x] Implement map file parsing (.cub format)
- [x] Validate map structure and requirements
- [x] Implement flood fill algorithm for map validation
- [x] Parse texture paths and colors
- [x] Error handling for invalid maps/textures

### Phase 2: Basic Window and Graphics
- [x] Initialize MLX window
- [x] Set up basic image buffer system
- [x] Implement window event handling (ESC to close)
- [x] Basic pixel manipulation functions
- [x] Test rendering simple shapes

### Phase 3: Player System
- [x] Initialize player position and orientation
- [x] Implement player movement (WASD keys)
- [x] Add player rotation (arrow keys or mouse)
- [x] Implement collision detection
- [x] Add smooth movement and rotation

### Phase 4: Raycasting Algorithm Implementation

#### Step 1: Ray Direction Calculation
- [x] Implement camera plane setup
- [x] Calculate ray direction for each screen column
- [x] Set up player direction and plane vectors

#### Step 2: Delta Distance Calculation
- [x] Calculate delta distances for x and y grid intersections
- [x] Implement grid position mapping

#### Step 3: Step and Side Distance Calculation
- [x] Calculate step directions (±1)
- [x] Initialize side distances for ray traversal

#### Step 4: Digital Differential Analysis (DDA)
- [x] Implement DDA algorithm
- [x] Wall detection logic
- [x] Track which side of wall was hit

#### Step 5: Wall Height and Distance Calculation
- [x] Calculate wall distance from player
- [x] Determine wall height on screen
- [x] Calculate draw start and end positions

### Phase 5: Texture Implementation
- [x] Load textures into memory buffers
- [x] Implement texture coordinate calculation
- [x] Map wall intersection to texture coordinates
- [x] Handle different wall orientations (N, S, E, W)
- [x] Add shading for visual depth

### Phase 6: Rendering Optimization
- [x] Implement pixel map system
- [x] Optimize image buffer manipulation
- [x] Use MLX image functions instead of individual pixel drawing
- [x] Implement ceiling and floor coloring
- [x] Prevent screen flickering

### Phase 7: Polish and Optimization (optional)
- [x] Fine-tune performance
- [x] Add visual enhancements
- [x] Implement smooth animations
- [x] Code cleanup and documentation
- [x] Memory leak checking with Valgrind

## 📝 Submission Checklist

- [x] Code compiles without warnings
- [x] All required features implemented
- [x] No memory leaks (Valgrind clean)
- [x] Proper error handling
- [x] Code follows 42 School norms
- [x] Performance meets expectations
- [x] Documentation complete

## 🏆 Bonus Features

- [x] Wall collision
- [x] Minimap display
- [x] FPS Counter
- [x] Darkness based on distance

---
