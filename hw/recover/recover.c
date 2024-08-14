#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int BUFFER_SIZE = 512;
typedef uint8_t BYTE;

void recover(FILE *input);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover [image file]");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Unable to open file %s", argv[1]);
        return 1;
    }
    recover(input);
    return 0;
}

void recover(FILE *input)
{
    char outname[8];
    int filecount = 0;
    BYTE buffer[BUFFER_SIZE];
    sprintf(outname, "%03d.jpg", filecount);
    FILE *output = NULL;
    while (fread(&buffer, 1, BUFFER_SIZE, input) == BUFFER_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef)
        {
            if (filecount > 0)
            {
                fclose(output);
            }
            output = fopen(outname, "w");
            filecount++;
            sprintf(outname, "%03d.jpg", filecount);
        }
        if (output)
        {
            fwrite(&buffer, 1, BUFFER_SIZE, output);
        }
    }
    // Close files
    if (output)
    {
        fclose(output);
    }
    fclose(input);
    return;
}
