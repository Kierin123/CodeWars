#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Take the following IPv4 address: 128.32.10.1
//
// This address has 4 octets where each octet is a single byte (or 8 bits).
//
//     1st octet 128 has the binary representation: 10000000
//     2nd octet 32 has the binary representation: 00100000
//     3rd octet 10 has the binary representation: 00001010
//     4th octet 1 has the binary representation: 00000001
//
// So 128.32.10.1 == 10000000.00100000.00001010.00000001
//
// Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 2149583361
//
// Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.

void uint32_to_ip(uint32_t ip, char *output)
{   
    const uint32_t mask = 1;
    const uint32_t mask8 = 255;
    uint8_t ip_octets[4] = {0};

    for (int j = 3; j >= 0; j--)
    {
        for (int i = 0; i < 8; i++)
        {
            ip_octets[j] |= (ip & mask) << i;
            ip = ip >> 1;
        }
    }
    
    sprintf(output,"%d.%d.%d.%d",ip_octets[0],ip_octets[1],ip_octets[2],ip_octets[3]);

//sprintf(output,"%d.%d.%d.%d",(ip&mask8),((ip>>8)&mask8),((ip>>16)&mask8),((ip>>24)&mask8));
}

void main(void)
{
    char out[15];
    uint32_to_ip(4294967295, out);
    printf("%s \n", out);
}
