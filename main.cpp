#include <iostream>
#include "incl_excl.hpp"

int main()
{
    box det = {1, 1, 10, 10};
    box reg [10];
    
    reg[0] = {1,1, 10, 10};
    std::cout <<"-------------------------------" << std::endl;
    std::cout <<"one region entirely overlapped "<< (true == is_excluded(&det, reg, 0)) <<std::endl;
    
    reg[0] = {1,1, 9, 10};
    std::cout <<"one region not entirely overlapped "<< (false == is_excluded(&det, reg, 0)) <<std::endl;
    
    reg[0] = {0,0, 12, 12};
    std::cout <<"one region entirely overlapped bigger "<< (true == is_excluded(&det, reg, 0)) <<std::endl;
    
    std::cout <<"-------------------------------" << std::endl;
    reg[1] = {1,1, 5, 10};
    reg[0] = {6,1, 5, 10};
    std::cout <<"split in two vertical1 " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {6,1, 5, 10};
    reg[0] = {1,1, 5, 10};
    std::cout <<"split in two vertical2 " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {0,0, 7, 12};
    reg[0] = {5,0, 7, 12};
    std::cout <<"split in two vertical bigger " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {6,1, 5, 10};
    reg[0] = {1,1, 4, 10};
    std::cout <<"not covered vert split1 : " <<(false == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {6,1, 4, 10};
    reg[0] = {1,1, 5, 10};
    std::cout <<"not covered vert split2 : " <<(false == is_excluded(&det, reg, 1)) <<std::endl;

    std::cout <<"-------------------------------" << std::endl;
    reg[1] = {1,1, 10, 5};
    reg[0] = {1,6, 10, 5};
    std::cout <<"split in two horizontal1 " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {1,6, 10, 5};
    reg[0] = {1,1, 10, 5};
    std::cout <<"split in two horizontal2 " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {0,0, 12, 7};
    reg[0] = {0,5, 12, 12};
    std::cout <<"split in two horizontal bigger " <<(true == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {1,1, 10, 4};
    reg[0] = {1,6, 10, 5};
    std::cout <<"not covered horizontal split1 : " <<(false == is_excluded(&det, reg, 1)) <<std::endl;

    reg[1] = {1,1, 10, 5};
    reg[0] = {1,6, 10, 4};
    std::cout <<"not covered horizontal split2 : " <<(false == is_excluded(&det, reg, 1)) <<std::endl;

    std::cout <<"-------------------------------" << std::endl;
    reg[4] = {3,3, 2, 2};
    reg[3] = {1,1, 5, 5};
    reg[2] = {1,6, 5, 5};
    reg[1] = {6,1, 5, 5};
    reg[0] = {6,6, 5, 5};
    std::cout <<"covered quarter split : " <<(true == is_excluded(&det, reg, 4)) <<std::endl;

    std::cout <<"-------------------------------" << std::endl;
}
