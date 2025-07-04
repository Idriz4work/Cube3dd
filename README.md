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
- MinilibX library
- GCC compiler
- Make
- Math library (-lm)

### Installation Steps
1. Clone the repository
2. Install MinilibX:
   ```bash
   # For streamlined installation, consider using 42-cli tool
   # OR install manually following MLX documentation
   ```
3. Compile the project:
   ```bash
   make
   ```

## 📁 Project Structure

```
cub3d/
├── src/
│   ├── main.c
│   ├── raycasting/
│   ├── textures/
│   ├── movement/
│   ├── parsing/
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
- [ ] Implement collision detection
- [ ] Add smooth movement and rotation
- [ ] Variable speed implementation

### Phase 4: Raycasting Algorithm Implementation

#### Step 1: Ray Direction Calculation
- [ ] Implement camera plane setup
- [ ] Calculate ray direction for each screen column
- [ ] Set up player direction and plane vectors

#### Step 2: Delta Distance Calculation
- [ ] Calculate delta distances for x and y grid intersections
- [ ] Implement grid position mapping

#### Step 3: Step and Side Distance Calculation
- [ ] Calculate step directions (±1)
- [ ] Initialize side distances for ray traversal

#### Step 4: Digital Differential Analysis (DDA)
- [ ] Implement DDA algorithm
- [ ] Wall detection logic
- [ ] Track which side of wall was hit

#### Step 5: Wall Height and Distance Calculation
- [ ] Calculate wall distance from player
- [ ] Determine wall height on screen
- [ ] Calculate draw start and end positions

### Phase 5: Texture Implementation
- [ ] Load textures into memory buffers
- [ ] Implement texture coordinate calculation
- [ ] Map wall intersection to texture coordinates
- [ ] Handle different wall orientations (N, S, E, W)
- [ ] Add shading for visual depth

### Phase 6: Rendering Optimization
- [ ] Implement pixel map system
- [ ] Optimize image buffer manipulation
- [ ] Use MLX image functions instead of individual pixel drawing
- [ ] Implement ceiling and floor coloring
- [ ] Prevent screen flickering

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
	void	*text_buf[NUM_TEXTURES];
	// Player position and direction
	double	pos_x;
	double	pos_y;
	double	dir;
	double	plane_x;
	double	plane_y;
	// Image buffer for rendering
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
- **Ray Direction**: `ray_dir = player_dir + camera_plane * camera_x`
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

- Minimap display
- Sprite rendering
- Sound effects
- Multiple levels
- Mouse look control

---

**Good luck with your Cub3D adventure! Remember: understanding the mathematics is crucial for successful implementation and debugging.**
