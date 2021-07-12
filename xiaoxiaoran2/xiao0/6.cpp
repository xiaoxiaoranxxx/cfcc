#include<iostream>
#include<iomanip>

//using namespace std;

int main()
{
    // double a=123.1234567899;
    // std::cout << a << std::endl; //123.123
    // std::cout << std::setprecision(8) << a << std::endl; //123.12346
    // std::cout << std::setprecision(6) ;

    // std::cout << std::setiosflags(std::ios::fixed);
    // std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(8) << a << std::endl;
    // std::cout << std::setiosflags(std::ios::fixed) << a << std::endl;
    
    std::cout.fill('*');


    int x=111;
    std::cout << std::hex <<x << std::endl;
    std::cout << std::setiosflags(std::ios::uppercase) <<x << std::endl;

    


    return 0;
}
