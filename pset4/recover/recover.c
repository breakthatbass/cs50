#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

    // show correct usage if there is no argument at runtime
    if (argc < 2) 
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // variable for block size
    int block_size = 512;
    // open file
    FILE *file = fopen(argv[1], "r");

    // array to store data from file
    uint8_t buffer[512];

    int img_count = 0;

    // create file to write to
    FILE *new_file = NULL;

    while (fread(buffer, block_size, 1, file))
    {
        
        // check first four bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {
                char filename[8];
                sprintf(filename, "%03i.jpg", img_count);

                new_file = fopen(filename, "w");

                img_count++; 
            }

        if (new_file != NULL)
        {
            // write to new file
            fwrite(buffer, block_size, 1, new_file);
        }
    }

    // close file when done
    if (new_file != NULL)
    {
        fclose(new_file);
    }

    // close memory card file when done
    fclose(file);

    // success!
    return 0;
}
