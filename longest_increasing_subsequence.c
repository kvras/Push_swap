#include "header.h"

int LIS(int* nums, int numsSize, int* maxSeq)
{
    int *len_memoisation;
    int temp;
    int *indices_memoisation;
    int first = 0;
    int i=0,j = 0,x = 0,y = 0,max_len = 0,max_index = 0;
    len_memoisation = (int *)malloc(sizeof(int)*numsSize);
    if(len_memoisation == NULL)
        return -1;
    indices_memoisation = (int *)malloc(sizeof(int)*numsSize);
    if(indices_memoisation == NULL)
        return -1;
    while(x < numsSize+ first%numsSize)
    {
        indices_memoisation[x%numsSize] = -1;
        len_memoisation[x%numsSize] = 1;
        y = 0;
        while(y < x)
        {
            i = x%numsSize;
            j = y%numsSize;
            if(nums[i]>nums[j] && len_memoisation[i]<=len_memoisation[j])
            {
                len_memoisation[i] = len_memoisation[j] + 1;
                indices_memoisation[i] = j;   // we store the index of the previous element in the index of the current element
                                              // we save thim by indices not the lenghts to avoid the problem of overwriting
                                              // so that each index have its own previous index
            }
            if(max_len < len_memoisation[i])
            {
                max_len = len_memoisation[i];
                max_index = i;       // we store max_index because ther is no way to find it later
                temp = max_index;
                for(int count = 1; count < max_len; count++)
                    temp = indices_memoisation[temp];
                first = temp;       // we store the first indice of the max_len
            }
            y++;
        }
        x++;
    }
     //printf("first indice is = %d\n",first);
    i = max_len;
    temp = max_index;    // we start from the end of the array and go back to the beginning using the indices_memoisation array
                             // we start with max_index because it is the key to fuind other indices
    while(i > 0)
    {
        maxSeq[--i] = temp;
        temp = indices_memoisation[temp];    // we replace the current index in the array to get his matching index
    }
    free(len_memoisation);
    free(indices_memoisation);
    return max_len;

}
// int main() {

//     //int tab[] ={1000,2000,473,-1, 587, 214, 693, 957, 381, 521, 342, 166, 827, 689, 304, 108, 784, 211, 589, 352, 886, 419, 723, 596, 907, 448, 987, 636, 125, 863, 740, 456, 597, 825, 944, 654, 631, 204, 864, 128, 749, 826, 296, 217, 544, 895, 763, 674, 201, 529, 469, 482, 176, 839, 271, 933, 832, 754, 419, 575, 139, 197, 927, 305, 245, 780, 745, 493, 748, 423, 369, 682, 427, 719, 364, 505, 670, 930, 862, 236, 883, 191, 971, 107, 618, 287, 284, 367, 552, 912, 346, 888, 513, 192, 678, 122, 487, 354, 534, 840, 956, 601, 245, 865, 938, 893, 821, 746, 862, 508, 560, 795, 912, 634, 523, 370, 331, 831, 141, 648, 598, 633, 409, 718, 559, 915, 106, 927, 732, 111, 845, 248, 263, 890, 906, 263, 702, 710, 647, 246, 900, 860, 135, 164, 726, 677, 972, 460, 688, 808, 816, 246, 508, 781, 922, 944, 581, 775, 844, 298, 353, 332, 893, 352, 686, 855, 120, 453, 674, 764, 348, 192, 708, 504, 663, 149, 493, 978, 275, 680, 994, 965, 540, 495, 538, 256, 302, 351, 144, 913, 746, 764, 620, 822, 687, 759, 833, 568, 319, 504, 384, 876, 781, 401, 222, 803, 234, 243, 275, 985, 905, 799, 289, 796, 810, 695, 926, 647, 181, 835, 167, 373, 509, 800, 930, 183, 580, 413, 316, 892, 501, 226, 421, 604, 345, 878, 578, 156, 697, 372, 262, 831, 285, 407, 823, 258, 930, 214, 329, 552, 905, 726, 891, 565, 850, 253, 510, 308, 736, 313, 516, 652, 639, 618, 418, 122, 698, 258, 647, 344, 423, 757, 503, 413, 893, 899, 238, 199, 963, 707, 820, 912, 892, 448, 489, 799, 961, 684, 597, 133, 358, 624, 521, 853, 641, 827, 481, 111, 964, 977, 342, 982, 788, 618, 813, 769, 803, 499, 283, 835, 753, 959, 356, 689, 907, 703, 284, 855, 973, 776, 539, 499, 747, 360, 953, 104, 266, 681, 272, 366, 408, 184, 677, 377, 662, 920, 825, 180, 703, 123, 570, 695, 987, 672, 274, 537, 868, 680, 825, 813, 579, 594, 504, 327, 342, 595, 652, 983, 480, 466, 392, 332, 284, 759, 981, 305, 328, 227, 371, 762, 596, 113, 543, 688, 963, 343, 907, 145, 318, 146, 510, 308, 363, 553, 896, 893, 587, 610, 642, 724, 552, 295, 286, 848, 725, 579, 322, 614, 142, 853, 632, 322, 641, 833, 812, 527, 901, 765, 610, 538, 253, 948, 630, 485, 671, 822, 845, 448, 712, 835, 612, 620, 652, 835, 758, 360, 318, 853, 897, 858, 144, 172, 328, 878, 614, 899, 938, 469, 461, 212, 115, 843, 214, 327, 618, 588, 768, 157, 798, 567, 557, 604, 306, 171, 150, 653, 707, 925, 897, 254, 260, 225, 565, 653, 702, 331, 121, 101, 578, 501, 426, 428, 561, 412, 184, 604, 635, 306, 850, 799, 612, 787, 441, 262, 264, 269, 407, 534, 165, 903, 945, 646, 987, 225, 940, 269, 762, 839, 684, 327, 484, 708, 419, 295, 484, 582, 346, 982, 668, 576};
//     int tab[] = {100,4, 6, 726, 9};
//     int lis[sizeof(tab)/sizeof(tab[0])];
//     int len = LIS(tab, sizeof(tab)/sizeof(tab[0]), lis);
//     printf("Length of LIS: %d\n", len);
//     printf("LIS: ");
//     for(int i = 0; i < len; i++) {
//         printf("%d ", lis[i]);
//     }
//     return 0;
// }