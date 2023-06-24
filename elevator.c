#include <stdbool.h>
#include <stdio.h>

unsigned int minFloor = 1;
unsigned int maxFloor = 25;

unsigned int stateFloor = 1;

unsigned int getFloor() {
    unsigned int selectedFloor;
    printf("Enter floor: ");
    scanf("%u", &selectedFloor);
    printf("You chose floor: %u\n", selectedFloor);
    return selectedFloor;
}

void stop(unsigned int floor) {
    printf("Your floor: %u\n", floor);
    stateFloor = floor;
    getFloor();
}

void movingUp(unsigned int selectedFloor) {
    for (; stateFloor <= maxFloor; stateFloor++) {
        if (selectedFloor == stateFloor) {
            stop(stateFloor);
            break;
        }
    }
}

void movingDown(unsigned int selectedFloor) {
    for (; stateFloor >= minFloor; stateFloor--) {
        if (selectedFloor == stateFloor) {
            stop(stateFloor);
            break;
        }
    }
}

void elevatorMoving(unsigned int selectedFloor) {
    if (stateFloor < selectedFloor) {
        movingUp(selectedFloor);
    } else if (stateFloor > selectedFloor) {
        movingDown(selectedFloor);
    } else {
        stop(selectedFloor);
    }
}

int main() {
    while (true) {
        unsigned int selectedFloor = getFloor();
        elevatorMoving(selectedFloor);
    }

    return 0;
}
