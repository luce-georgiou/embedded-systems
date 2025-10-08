#define SETBIT(reg,bit) ((reg) |= (1<<(bit))) //passe le bit dans reg à 1 (bit = position dans reg)
#define CLRBIT(reg,bit) ((reg) &= ~(1<<(bit))) //passe le bit dans reg à 0
#define TOGGLEBIT(reg,bit) ((reg) ^= (1<<(bit))) //
#define get_bit(reg,bit) (((reg) >> (bit)) & 1) //renvoie le num/lettre à la position bit de reg, 0 sinn
#define test_bit(reg,bit) ((reg) & (1<<(bit))) //renvoie 0 si reg = 0000000 et 1 si bit != 0

void led_yellow_on_off();