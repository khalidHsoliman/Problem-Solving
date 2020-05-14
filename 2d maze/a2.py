# Do not import any modules. If you do, the tester may reject your submission.

# Constants for the contents of the maze.

# The visual representation of a wall.
WALL = '#'

# The visual representation of a hallway.
HALL = '.'

# The visual representation of a brussels sprout.
SPROUT = '@'

# Constants for the directions. Use these to make Rats move.

# The left direction.
LEFT = -1

# The right direction.
RIGHT = 1

# No change in direction.
NO_CHANGE = 0

# The up direction.
UP = -1

# The down direction.
DOWN = 1

# The letters for rat_1 and rat_2 in the maze.
RAT_1_CHAR = 'J'
RAT_2_CHAR = 'P'


class Rat:
    """ A rat caught in a maze. """

    # Write your Rat methods here.
    
    def __init__(self, symbol, row, col):
        """ (Rat, str, int, int) => NoneType
    
        initialize a Rat with a symbol to show on the maze
        and two int to detect its position
        """
        
        self.symbol =symbol
        self.row = row
        self.col = col
        self.num_sprouts_eaten = 0

    def set_location(self, row, col):
        """ (Rat, int, int) => NoneType

        Set the rat's row and col instance variables to
        the given row and column.
        """
        assert row >= 0, \
           'row is negative.'

        assert col >= 0, \
           'col is negative.'
        
        self.row = row
        self.col = col

    def eat_sprout(self):
        """ (Rat) => NoneType

        Add one to the rat's instance variable
        num_sprouts_eaten
        """

        self.num_sprouts_eaten+=1

    def __str__(self):
        """ (Rat) => str

        Return a string representation of the rat,
        in this format:
        symbol at (row, col) ate num_sprouts_eaten sprouts.    
        """

        return '{0} at ({1}, {2}) ate {3} sprouts.'.format(
            self.symbol,self.row,self.col,self.num_sprouts_eaten)
    
class Maze:
    """ A 2D maze. """

    num_sprouts_left = 0

    new_vdir = 0
    new_hdir = 0
    
    # Write your Maze methods here.

    def __init__(self, maze, rat_1, rat_2):
        """ (Maze, list of list of str, Rat, Rat) => NoneType

        Initialize this maze's four instance variables
        """

        self.maze = maze
        self.rat_1 = rat_1
        self.rat_2 = rat_2

        self.maze[rat_1.row][rat_1.col] = rat_1.symbol
        self.maze[rat_2.row][rat_2.col] = rat_2.symbol

        for row in maze:
            for char in row:
                if char == '@':
                    self.num_sprouts_left +=1 


    def is_wall(self, row, col):
        """ (Maze, int, int) => boolean

        Return True if and only if there is a wall at the
        given row and column of the maze
        """

        return self.get_character(row, col) == WALL
            
    def get_character(self, row, col):
        """ (Maze, int, int) => str

        Return the character in the maze at the given row and column.
        If there is a rat at that location,
        then its character should be returned rather than HALL.
        """

        assert 0 <= row < len(self.maze), \
           'row not in the maze.'

        assert 0 <= col < len(self.maze[0]), \
           'col not in the maze.'

        return self.maze[row][col]

    def move(self, rat, vdir, hdir):
        """ (Maze, Rat, int, int) => bool

        Move the rat in the given direction, unless there is a wall in the way.
        Also, check for a Brussels sprout at that location and eat it if present
        """

        assert vdir == UP or \
               vdir == NO_CHANGE or \
               vdir == DOWN, \
           'vertical direction wrong.'

        assert hdir == UP or \
               hdir == NO_CHANGE or \
               hdir == DOWN, \
           'horizontal direction wrong.'
        
        new_vdir = rat.row + vdir
        new_hdir = rat.row + hdir
        
        if self.is_wall(new_vdir, new_hdir):
            return False

        if self.get_character(new_vdir, new_hdir) == SPROUT:
            rat.eat_sprout()
            self.num_sprouts_left -= 1
            self.maze[new_vdir, new_hdir] == HALL

        rat.set_location(new_vdir, new_hdir)

        self.maze[self.rat_1.row][self.rat_1.col] = self.rat_1.symbol
        self.maze[self.rat_2.row][self.rat_2.col] = self.rat_2.symbol
        
        return True     

    def __str__(self):
        """ (Maze) => str

        . Return a string representation of the maze.  
        """
        str_to_print = ''
        
        for row in self.maze:
            for element in row:
                str_to_print += element
            str_to_print += '\n'
            
        str_to_print += str(self.rat_1) + '\n'
        str_to_print += str(self.rat_2) 

        return  str_to_print
