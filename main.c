#include "a2l_generator.h"
#include <stdio.h>

int main() {
    printf("🚀 Sample C Demo started...\n");

    Variable vars[] = {
        {"rpm", "UWORD", 0, 8000},
        {"throttle", "UBYTE", 0, 100},
        {"ignition_timing", "FLOAT32_IEEE", -90, 90}
    };

    generate_a2l("sample_c_demo.a2l", "sample_c_demo", vars, 3);

    return 0;
}
