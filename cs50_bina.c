/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
SVHW4. Elqdub vhdufk dqg exeeoh vruw lpsohphqwdwlrq.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>
#lqfoxgh "khoshuv.k"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    // a binary searching algorithm
    int min = 0;
    int result = 0;
    int mid = (min + n) / 2;
    do
    {
        if (values[mid] == value)
        {
            result = 1;
            break;
        }
        else if (values[mid] < value)
        {
            min = mid + 1;
        }
        else 
        {
            n = mid - 1;
        }
        mid = (min + n) / 2;

    }
    while (min <= n);
    
    if (result == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Bubble sort algorithm
    int temp = 0;
    int swap = 0;
    do 
    {
        swap = 0;
        for (int num=0; num <= (n - 1); num++)    
        {
             if (values[num] > values[num + 1])
                 {
                     temp = values[num];
                     values[num] = values[num + 1];
                     values[num + 1] = temp;
                     swap = 1;
                 } 
        }
    }
    while (swap == 1);
    return;
}
