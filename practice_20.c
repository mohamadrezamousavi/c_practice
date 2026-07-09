// practice lesson: Basics of embedded C
# include <stdio.h>
# include <stdint.h>
void printBinary (int8_t a);
int main()
{
    unsigned char a = 0b10101100;
    unsigned char b = 0xac;
    unsigned char c = 176;
    printf("a is %d\n",a);
    printf("b is %d\n",b);
    printf("c is %d\n",c);

    uint8_t A = 255;
    uint8_t B = 0b11111111;
    uint8_t C = 0xff;
    printf("A is %d\n",A);
    printf("B is %d\n",B);
    printf("C is %d\n",C);
    //--------------------------------------
    int8_t data1 = 10;
    int8_t data2 = -3;

    int8_t and_data = data1 & data2;
    printf("And is: ");
    printBinary(and_data);
    int8_t not_data = ~and_data; 
    printf("Not And is: ");
    printBinary(not_data);
    int8_t xor_data = data1 ^ data2;
    printf("Xor is: ");
    printBinary(xor_data);
    return 0;
}

void printBinary (int8_t a)
{
    uint8_t binary_data = (uint8_t) a;
    for (int i = 7; i>=0; i--)
    {
        printf("%d", (binary_data >> i) & 1);
    }
    printf("\n");     
}