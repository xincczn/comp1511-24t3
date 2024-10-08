// Xing He, z5413977, 11/10/24
// Part 1: 2D Arrays Practice

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

void print_farm(struct farm_entity farm[SIZE][SIZE]);

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

int main(void) {
    // Declare the farm map as a 2d array
    struct farm_entity farm[SIZE][SIZE];

    // Initialise the farm
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Initialise with default values
            farm[row][col].entity = EMPTY;
            farm[row][col].points = DEFAULT_POINTS;
        }
    }


    // Place the barns and trees in the farm
    printf("Enter barns and trees:\n");
    char command;
    scanf(" %c", &command);

    while (command != COMMAND_QUIT) {
        if (command == COMMAND_BARN) {
            int barn_row;
            int barn_col;
            int barn_points;
            scanf(" %d %d %d", &barn_row, &barn_col, &barn_points);

            farm[barn_row][barn_col].entity = BARN;
            farm[barn_row][barn_col].points = barn_points;
        } else if (command == COMMAND_TREE) {
            int tree_row;
            int tree_col;
            scanf(" %d %d", &tree_row, &tree_col);
            
            farm[tree_row][tree_col].entity = TREE;
            farm[tree_row][tree_col].points = TREE_POINTS;
        }

        scanf(" %c", &command);
    }


    // Place the farmer in the farm
    printf("Enter the starting position of the farmer: ");
    int farmer_row;
    int farmer_col;
    scanf("%d %d", &farmer_row, &farmer_col);

    while (farmer_row < 0 || farmer_row >= SIZE || 
           farmer_col < 0 || farmer_col >= SIZE ||
           farm[farmer_row][farmer_col].entity != EMPTY
    ) {
        printf("Invalid starting position!\n");
        printf("Re-enter starting position: ");
        scanf("%d %d", &farmer_row, &farmer_col);
    }

    farm[farmer_row][farmer_col].entity = FARMER;
    farm[farmer_row][farmer_col].points = 0;


    // Place the coops in the farm
    printf("Enter the position and points of the coop(s):\n");
    int coop_row;
    int coop_col;
    int coop_points;

    while (scanf("%d %d %d", &coop_row, &coop_col, &coop_points) == 3) {
        farm[coop_row][coop_col].entity = COOP;
        farm[coop_row][coop_col].points = coop_points;
    }

    // Print the farm
    print_farm(farm);

    return 0;
}

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

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