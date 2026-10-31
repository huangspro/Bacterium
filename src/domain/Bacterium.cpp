#include "Bacterium.h"

Bacterium::Bacterium(int x, int y):is_alive(true), health(100), is_touched(false), x(x), y(y){}

void Bacterium::init_sub() {
    sub = new Substance[24]{
        // 生命基本物质
        {"Water_水", 70.0},
        {"Oxygen_氧气", 5.0},
        {"Glucose_葡萄糖", 10.0},
        {"AminoAcids_氨基酸", 5.0},
        {"FattyAcids_脂肪酸", 2.0},
        {"Nucleotides_核苷酸", 2.0},
        {"ATP_三磷酸腺苷", 3.0},
        {"Phosphate_无机磷酸盐", 2.0},
        {"Ammonium_铵离子", 1.0},
        {"Potassium_钾离子", 2.0},
        {"Magnesium_镁离子", 1.0},
        {"Calcium_钙离子", 0.5},

        // 代谢产物及废物
        {"CarbonDioxide_二氧化碳", 0.0},
        {"Lactate_乳酸", 0.0},
        {"Acetate_乙酸", 0.0},
        {"Ammonia_氨", 0.0},
        {"Ethanol_乙醇", 0.0},
        {"ReactiveOxygenSpecies_活性氧", 0.0},

        // 主动释放物质
        {"Toxin_毒素", 0.0},
        {"Bacteriocin_细菌素", 0.0},
        {"QuorumSignal_群体感应信号分子", 0.0},
        {"Exopolysaccharide_胞外多糖", 0.0},
        {"Siderophore_铁载体", 0.0},
        {"ExtracellularEnzyme_胞外酶", 0.0}
    };
}

void Bacterium::die(){
    is_alive = false;
}

void Bacterium::move(){
    int dx, dy;
    if(is_alive){
        x += dx;
        y += dy;
    }
}


void Bacterium::touched(){

}

Bacterium Bacterium::divide() {

}

void Bacterium::impair_health(double i){
    health -= i;
}

void Bacterium::grow(){

}

void Bacterium::breathe(){

}

Bacterium::~Bacterium(){
    delete sub;
}
