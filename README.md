# Cub3D - 3D Raycasting Game Engine

A 42 School project that creates a 3D graphical representation of a maze using raycasting techniques, similar to classic games like Wolfenstein 3D.

## 📋 Project Overview

Cub3D is an advanced graphics project that builds upon concepts from so_long, implementing:
- Ray casting algorithm for 3D rendering
- Texture mapping and image manipulation
- Real-time player movement and rotation
- Flood fill map validation
- Event handling and graphics optimization

**Expected Performance**: ~750 fps on modern hardware (12th Gen Intel i7, 16GB RAM, Ubuntu 22.04)

## 🎯 Learning Objectives

- Understand and implement raycasting algorithms
- Master 3D graphics concepts using 2D techniques
- Work with image buffers and pixel manipulation
- Optimize graphics rendering performance
- Handle mathematical calculations for 3D projection

## 🛠️ Setup and Installation

### Prerequisites
Theese can be installed with the command below
- MinilibX library
- GCC compiler
- Github
- Make
- Math library (-lm)

### Installing Prerequisites
If you are missing some prerequisites, run this command,
to install all the neccesary packages
(Admin/Sudo priviliges required)
   ```bash
   sudo apt install build-essential gcc git make
   ```

### Installation Steps
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
### Running the game
The game requires a map file, which holds information about the map, which the game should load
The repository comes prepared with some maps, in the "maps" folder
Maps have to satisfy certain requirements, which the program will complain about if invalid

Different ways of running the game:
1. Quick Run:
Will run the game with the pre-delivered "test.cub" map file
	```bash
   make run
   ```
2. Custom Map:
Replace MAP_PATH with something like "./maps/test.cub"
Replace "test" from that with whatever other name your map has
The map has to be in a ".cub" format
	```bash
   ./cub3d MAP_PATH
   ```

### Map Files
Map Files have to hold 3 types of information
There should only be 1 of theese per line
1.	4x A path to a texture file per corresponding wall
	WALL_IDENTIFIER: WALL_TEXTURE
	You will need to specify the direction for the wall, and then the texture file
	WALL IDENTIFIERs are "NO", "SO", "WE" or "EA"
	WALL_TEXTURE is the file, which has to be in an xpm file format
	It is also expected that theese files are 64x64 pixels
	Example:
	NO: ./textures/rick.xpm
2.	2x Color data for the ceiling and floor
	IDENTIFIER RED_VALUE, GREEN_VALUE, BLUE_VALUE
	IDENTIFIERs are 'C' or 'F'
	The rgb values should be between (including) 0-255
	Example:
	C 0, 69, 255
3.	The map
	The map consists of ' ', '1', '0' and a single identifer for the player
	Player identifers are 'N', 'E', 'S', or 'W', corresponding to the initial direction of the player
	' ' are Empty Spaces, they can seperate map pieces, but may not be encountered by the player
	'1' are walls, they limit the players movement and view, and should encase the player
	'0' are free spaces, allowing the player to move on them
	The player may be surrounded by free spaces, but the area HAS TO be surrounded in walls.
The map should be the last piece of information in the file.
All Map files are text files in the ".cub" file format.
You can open the maps in the "maps" folder with a text editor for some examples

## 📁 Project Structure

```
cub3d/
├── src/
│   ├── main.c
│   ├── hooks/
│   ├── movement/
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   └── utils/
├── maps/
├── textures/
├── Makefile
└── README.md
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
- [ ] Test rendering simple shapes

### Phase 3: Player System
- [x] Initialize player position and orientation
- [x] Implement player movement (WASD keys)
- [x] Add player rotation (arrow keys or mouse)
- [x] Implement collision detection
- [x] Add smooth movement and rotation
- [ ] Variable speed implementation

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
- [ ] Implement DDA algorithm
- [ ] Wall detection logic
- [ ] Track which side of wall was hit

#### Step 5: Wall Height and Distance Calculation
- [x] Calculate wall distance from player
- [x] Determine wall height on screen
- [x] Calculate draw start and end positions

### Phase 5: Texture Implementation
- [x] Load textures into memory buffers
- [x] Implement texture coordinate calculation
- [x] Map wall intersection to texture coordinates
- [x] Handle different wall orientations (N, S, E, W)
- [ ] Add shading for visual depth

### Phase 6: Rendering Optimization
- [ ] Implement pixel map system
- [ ] Optimize image buffer manipulation
- [x] Use MLX image functions instead of individual pixel drawing
- [x] Implement ceiling and floor coloring
- [x] Prevent screen flickering

### Phase 7: Polish and Optimization
- [ ] Fine-tune performance
- [ ] Add visual enhancements
- [ ] Implement smooth animations
- [ ] Code cleanup and documentation
- [ ] Memory leak checking with Valgrind

## 🔧 Key Data Structures

### Core Structures
```c
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*tex[NUM_TEXTURES];
	int		action;
	double	pos_x;
	double	pos_y;
	double	rot;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	t_img	*image;
	int		**pixels_map;
	t_map	*minfo;
}	t_data;

typedef struct s_img
{
    void    *img;
    int     *addr;
    int     bpp;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_map;
```

## 🎮 Controls
- **W/A/S/D**: Move forward/left/backward/right
- **Arrow Keys**: Rotate view left/right, Move forward/backward
- **ESC**: Exit game

## 🧮 Mathematical Concepts

### Essential Formulas
- **Ray Direction**: `ray_dir = player_dir + cam_dir + camera_plane * camera_x`
- **Delta Distance**: `delta_dist = |1 / ray_dir|`
- **Wall Distance**: `wall_dist = (map_pos - player_pos + adjustment) / ray_dir`
- **Texture Coordinate**: `tex_x = wall_x * TEXTURE_SIZE`

## 🚀 Performance Tips

1. **Use Image Buffers**: Manipulate entire image buffer instead of individual pixels
2. **Optimize Texture Access**: Use efficient array indexing for texture data
3. **Minimize Function Calls**: Reduce MLX function calls in main loop
4. **Efficient Memory Management**: Properly manage texture buffers
5. **Variable Frame Rate**: Implement frame rate independent movement

## 🐛 Common Pitfalls to Avoid

- **Mathematical Understanding**: Don't skip learning the math behind raycasting
- **Continuous Movement**: Implement proper key event handling for smooth movement
- **Variable Speed**: Account for different computer performances
- **Memory Leaks**: Properly free all allocated resources
- **Texture Errors**: Handle texture loading failures gracefully
- **Map Validation**: Thoroughly validate map file format

## 📚 Recommended Resources

- Raycasting tutorials and mathematical explanations
- MinilibX documentation
- Computer graphics fundamentals
- Game development optimization techniques

## 🧪 Testing

### Test Cases
- [ ] Various map configurations
- [ ] Invalid map handling
- [ ] Performance benchmarking
- [ ] Memory leak testing with Valgrind
- [ ] Edge case scenarios (corners, small spaces)

### Debugging Tips
- Use visual debugging (draw rays, mark positions)
- Test with simple maps first
- Verify mathematical calculations step by step
- Check texture loading and indexing

## 🤝 Team Collaboration

### Division of Work Suggestions
- **Person 1**: Parsing, validation, and setup
- **Person 2**: Raycasting algorithm and rendering
- **Both**: Testing, optimization, and documentation

### Communication
- Regular code reviews
- Shared understanding of mathematical concepts
- Coordinated testing and debugging sessions

## 📝 Submission Checklist

- [ ] Code compiles without warnings
- [ ] All required features implemented
- [ ] No memory leaks (Valgrind clean)
- [ ] Proper error handling
- [ ] Code follows 42 School norms
- [ ] Performance meets expectations
- [ ] Documentation complete

## 🏆 Bonus Features Ideas

- [x] Wall collision
- [x] Minimap display
- [ ] Sprite rendering
- [ ] Sound effects
- [ ] Multiple levels
- [ ] Mouse look control

---

**Good luck with your Cub3D adventure! Remember: understanding the mathematics is crucial for successful implementation and debugging.**
