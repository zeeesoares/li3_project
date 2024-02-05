#include "parser.h"
#include "batch.h"
#include "interactive.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        interactive();
    }
    else if (argc == 3){
        batch(argv);
    }
    return 0;
}