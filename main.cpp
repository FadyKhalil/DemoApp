#include <iostream>
#include <thread>
#include <pthread.h>
#include "class.hpp"
#include "config.h"


Calculator Calc;
EnhanceCalc enhance;

void function_Calc(void)
{
    float result = 0;

    for(int i = START; i < SIZE_LOOP; i++)
    {
        result += Calc.add(INPUT_1, INPUT_2);
    }

    std::cout << "result 1 =  " << result << std::endl;
}

void function_Enh(void)
{
    float result = 0;


    for(int i = START; i < SIZE_LOOP; i++)
    {
        result += enhance.modulos(INPUT_1, INPUT_2);
    }

    std::cout << "result 2 =" << result << std::endl;
}


int main(void)
{

    std::thread showCalc(function_Calc);
    std::thread showEnh(function_Enh);

    EnhanceCalc* myenhace = new EnhanceCalc();
    Calculator* myCalc = reinterpret_cast<Calculator*>(myenhace);

    pthread_t handle = showCalc.native_handle();
    pthread_setname_np(handle, "MyThreadCalc");
    auto id1 = showCalc.get_id();

#if (PRINT_ID_2 == 1)
    pthread_t handle1 = showEnh.native_handle();
    pthread_setname_np(handle1, "MyThreadEnhc");
    auto id2 = showEnh.get_id();
#endif


    std::cout << "id thread 1 = " << id1 << 
#if (PRINT_ID_2 == 1)
    " id thread 2 = " << id2 << std::endl;
#else
    std::endl;
#endif

    if(showCalc.joinable())
    {
        showCalc.join();
    }

    if(showEnh.joinable())
    {
        showEnh.join();
    }

    return 0;
}