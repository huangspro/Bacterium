#include "World.h"
#include <cstdlib>
#include <ctime>
#include <matplot/matplot.h>

using namespace matplot;

int main(){
    srand(time(NULL));
    World newWorld = World(100, 100);
    newWorld.init(1000);
    newWorld.real_time_info();
    std::vector<double> x;
    std::vector<double> y;
    for (int i = 1; i <= 1000; i++) {
        newWorld.step();
        if(i%10==0)
        {
            x.push_back(newWorld.steps);
            y.push_back(newWorld.bac_num);
        }
    }

    // 画图
    plot(x, y);
    show();

    return 0;
}
