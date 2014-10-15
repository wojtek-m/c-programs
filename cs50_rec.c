/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Uhfryhuv MSHJv iurp d iruhqvlf lpdjh.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t  BYTE;

// FIRST_8_BYTES struct
typedef struct 
{ 
    BYTE byte1;
    BYTE byte2;
    BYTE byte3;
    BYTE byte4;
    BYTE bytes508[508];
} __attribute__((__packed__)) 
BUFFER; 


int main(int argc, char* argv[])
{
    
    // open input file 
    FILE* mem_card = fopen("card.raw", "r");
    
    // check if input file exist
    if (mem_card == NULL)
    {
        printf("Could not open the file");
        return 1;
    }
    
    // declaring variables
    BUFFER bf;
    int found_jpg = false;
    int jpg_count = 0;
    FILE* jpg_temp = NULL;
    char jpg_name[8] = {};
    
    // loops over the content of the card file
    while (fread(&bf, sizeof(BYTE), 512, mem_card) == 512) 
    {  
      // check if the first bytes are start of a jpg
      if (bf.byte1 == 0xff && bf.byte2 == 0xd8 && bf.byte3 == 0xff && (bf.byte4 == 0xe0 || bf.byte4 == 0xe1))
      {
             
        // checks if a file is open
        if (found_jpg == true)
        {
                   
            // creates new file name
            sprintf(jpg_name, "%03d.jpg", jpg_count);
         
            // opens and writes to a file
            jpg_temp = fopen(jpg_name, "w");
            fwrite(&bf, sizeof(BUFFER), 1, jpg_temp);
            fclose(jpg_temp);
        }
        else
        {
            // sets the found flag to true
            found_jpg = true;
            
            // creates new file name
            sprintf(jpg_name, "%03d.jpg", jpg_count);
         
            // opens and writes to a file
            jpg_temp = fopen(jpg_name, "w");
            fwrite(&bf, sizeof(BUFFER), 1, jpg_temp);
            fclose(jpg_temp);
        }
        
        // increments jpg count
        jpg_count++;  
        
      }
      else
      {
        // checks if file is open
        if (found_jpg == true)
        {
            // opens and writes to a file
            jpg_temp = fopen(jpg_name, "a");
            fwrite(&bf, sizeof(BUFFER), 1, jpg_temp);
            fclose(jpg_temp);
            
        }
        else
        {
            continue;
        }    
      }
    }
    
    fclose(mem_card);
    return 0;
}
