// Xing He, z5413977, 11/10/24
// Part 2: Arrays and Functions

#include <stdio.h>

// -----------------------------------------------------------------------------
// Constant Definition
// -----------------------------------------------------------------------------

#define SIZE 5
#define TREE_POINTS -10
#define DEFAULT_POINTS 0

#define COMMAND_QUIT 'q'
#define COMMAND_BARN 'b'
#define COMMAND_TREE 't'

// -----------------------------------------------------------------------------
// Enum Definition
// -----------------------------------------------------------------------------

enum entity_type {
    COOP,
    BARN,
    TREE,
    FARMER,
    EMPTY,
};

// -----------------------------------------------------------------------------
// Struct Definition
// -----------------------------------------------------------------------------

struct farm_entity {
    enum entity_type entity;
    int points;
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void initialise_farm(struct farm_entity farm[SIZE][SIZE]);
void place_barns_and_trees(struct farm_entity farm[SIZE][SIZE]);
void place_barn(struct farm_entity farm[SIZE][SIZE]);
void place_tree(struct farm_entity farm[SIZE][SIZE]);
void place_farmer(struct farm_entity farm[SIZE][SIZE]);
int is_valid_empty_position(
    struct farm_entity farm[SIZE][SIZE], 
    int row, 
    int col
);
void place_coops(struct farm_entity farm[SIZE][SIZE]);
void print_farm_sum(struct farm_entity farm[SIZE][SIZE]);
void print_farm(struct farm_entity farm[SIZE][SIZE]);

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

int main(void) {
    // Declare the farm map as a 2d array
    struct farm_entity farm[SIZE][SIZE];

    // Initialise the farm
    initialise_farm(farm);

    // Place the barns and trees in the farm
    place_barns_and_trees(farm);

    // Place the farmer in the farm
    place_farmer(farm);

    // Place the coops in the farm
    place_coops(farm);

    // Print the farm
    print_farm(farm);

    // Bonus function: Print the worth (sum of points) of the farm
    print_farm_sum(farm);

    return 0;
}

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

// Function initialises the 2d array map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void initialise_farm(struct farm_entity farm[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Initialise with default values
            farm[row][col].entity = EMPTY;
            farm[row][col].points = DEFAULT_POINTS;
        }
    }
}

// Function places barns and tree onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void place_barns_and_trees(struct farm_entity farm[SIZE][SIZE]) {
    printf("Enter barns and trees:\n");
    char command;
    scanf(" %c", &command);

    while (command != COMMAND_QUIT) {
        if (command == COMMAND_BARN) {
            place_barn(farm);
        } else if (command == COMMAND_TREE) {
            place_tree(farm);
        }

        scanf(" %c", &command);
    }
}

// Function places a barn onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void place_barn(struct farm_entity farm[SIZE][SIZE]) {
    int barn_row;
    int barn_col;
    int barn_points;
    scanf(" %d %d %d", &barn_row, &barn_col, &barn_points);

    farm[barn_row][barn_col].entity = BARN;
    farm[barn_row][barn_col].points = barn_points;
}

// Function places a tree onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void place_tree(struct farm_entity farm[SIZE][SIZE]) {
    int tree_row;
    int tree_col;
    scanf(" %d %d", &tree_row, &tree_col);
    
    farm[tree_row][tree_col].entity = TREE;
    farm[tree_row][tree_col].points = TREE_POINTS;
}

// Function places the farmer onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void place_farmer(struct farm_entity farm[SIZE][SIZE]) {
    printf("Enter the starting position of the farmer: ");
    int farmer_row;
    int farmer_col;
    scanf("%d %d", &farmer_row, &farmer_col);

    while (!is_valid_empty_position(farm, farmer_row, farmer_col)) {
        printf("Invalid starting position!\n");
        printf("Re-enter starting position: ");
        scanf("%d %d", &farmer_row, &farmer_col);
    }

    farm[farmer_row][farmer_col].entity = FARMER;
    farm[farmer_row][farmer_col].points = 0;
}

// Function places the farmer onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
// - row: the row position of the entity
// - col: the col position of the entity
//
// returns: integer
// - the result of the boolean expression
int is_valid_empty_position(
    struct farm_entity farm[SIZE][SIZE], 
    int row, 
    int col
) {
    return row >= 0 && row < SIZE &&
           col >= 0 && col < SIZE &&
           farm[row][col].entity == EMPTY;
}

// Function places coops onto the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void place_coops(struct farm_entity farm[SIZE][SIZE]) {
    printf("Enter the position and points of the coop(s):\n");
    int coop_row;
    int coop_col;
    int coop_points;

    while (scanf("%d %d %d", &coop_row, &coop_col, &coop_points) == 3) {
        farm[coop_row][coop_col].entity = COOP;
        farm[coop_row][coop_col].points = coop_points;
    }
}

// Function calculates the total net worth of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void print_farm_sum(struct farm_entity farm[SIZE][SIZE]) {
    int total_points = 0;

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            total_points += farm[row][col].points;
        }
    }

    printf("The farm's net worth (in points): %d!\n", total_points);
}

// Function prints the map of the farm
//
// Parameters:
// - farm: the 2D array representing the farm
//
// returns: nothing
void print_farm(struct farm_entity farm[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (farm[i][j].entity == FARMER) {
                printf(" X ");
            } else if (farm[i][j].entity == EMPTY) {
                printf("   ");
            } else if (farm[i][j].entity == COOP) {
                printf(" o ");
            } else if (farm[i][j].entity == BARN) {
                printf(" # ");
            } else if (farm[i][j].entity == TREE) {
                printf(" T ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}