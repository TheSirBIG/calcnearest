#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double target = 6.6;        //к какому числу надо подвести
    double diff = 0.05;          //максимальная разница

//    double values[] = {94.99*0.02, 119.17*0.02, 109.99*0.02*2, 119.99*0.02, 35.97*0.02,
//                       125.99*0.02, 139.99*0.02, 119*0.02, 159.99*0.02, 26.99*0.02*2,
//                       8.99*0.02};
    double values[] = {94.99*0.02, 119.17*0.02,  119.99*0.02, 35.97*0.02,
                       139.99*0.02, 119*0.02, 159.99*0.02, 26.99*0.02*2,
                       8.99*0.02};
    int len = sizeof(values)/sizeof(double);
    std::cout << len << std::endl;

    //обычный перебор по бинарному паттерну
    //убирающиеся в разницу выдаю на печать

    long pattlen = exp2(len);
    std::cout << pattlen << std::endl;

    //test pattern
    /*
    long k=16;
    while(k!=0)
    {
        std::cout << (k & 0x01);
        k = k/2;
    }
    std::cout << std::endl;
    */

    double *pattmas = new double[len];
    for(long patt=0; patt<pattlen; patt++)
    {
        for(int i=0; i<len; i++) pattmas[i] = 0.0;
        long k = patt;
        int idx = 0;
        while(k!=0)
        {
            pattmas[idx] = (k & 0x01);
            k = k/2;
            idx++;
        };
        double summ = 0;
        for(int i=0; i<len; i++)
            summ += values[i]*pattmas[i];
//        std::cout << summ << std::endl;
        if(abs(target-summ) <= diff)
        {
            for(int i=0; i<len; i++)
                std::cout << pattmas[i];
            std::cout << "," << target << "," << summ << std::endl;
        }
    };
    std::cout << "end" << std::endl;
    delete[] pattmas;

    return a.exec();
//    return 0;
}
