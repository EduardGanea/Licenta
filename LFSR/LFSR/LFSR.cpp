#define POLYNOM_1 0x1       // polynoms under their masking form  0x1 = 1 * x^0   0xAB 0xAB = 1 * x^7 +1 * x^5+1 * x^3+1 * x^1+1 * x^0
#define POLYNOM_2 0xAB

#include <iostream>

typedef unsigned int uint;

uint lfsr_1, lfsr_2;

int shift_lfsr(uint* lfsr, uint polymonial)     // XOR shifting the bits by one position(LFSR base implementation)
{
    int feedback;

    feedback = *lfsr & 1;
    *lfsr >>= 1;
    if (feedback == 1)
        *lfsr ^= polymonial;
    return *lfsr;
}

void init_lfsrs(void)
{
    lfsr_1 = 0xEA4634C; //seed values
    lfsr_2 = 0xAAABBB554543D;
}

int get_random(void)
{
    shift_lfsr(&lfsr_1, POLYNOM_1);                                         // the principle for the random number generator is that the lfsr_1 is shifted 2 times before the 2nd lfsr(lfsr_2) is XORed with it
    return(shift_lfsr(&lfsr_1, POLYNOM_1) ^ shift_lfsr(&lfsr_2, POLYNOM_2));
}

void main(void)
{
    int random_value[30];

    init_lfsrs();
    for (int i = 0; i < 30; i++)                    // displaying the first i random values
    {
        random_value[i] = get_random();
        std::cout << random_value[i] << std::endl;
    }
}