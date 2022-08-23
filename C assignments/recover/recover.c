// recovers JPEGs from a forensic image. usage - ./recover IMAGE (forensice image file name)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover IMAGE");
        return 1;
    } else {
        char *input_file = argv[1];
        FILE *input_pointer = fopen(input_file, "r");

        if (input_pointer == NULL) {
            printf("error - can't open %s\n", input_file);
            return 2;
        }

        //initialising variables
        BYTE buffer[512];
        int count = 0;
        FILE *img_pointer = NULL;
        char *filename = malloc(8 * sizeof(char));

        while(fread(buffer, 512, 1, input_pointer) == 1) {

            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

                if (count != 0) {
                    fclose(img_pointer);
                }

                sprintf(filename, "%03i.jpg", count);
                img_pointer = fopen(filename, "w");
                count++;
            }

            if (count !=0) {
                fwrite(&buffer, 512, 1, img_pointer);
            }
        }

        free(filename);
        fclose(input_pointer);
        fclose(img_pointer);
        return 0;
    }
}
