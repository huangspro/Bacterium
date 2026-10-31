#include "Bacterium.h"

Bacterium::Bacterium(int x, int y):is_alive(true), health(100), is_touched(false), x(x), y(y){}

void Bacterium::init_sub() {
    sub = new Substance();

    // 生命基本物质
    sub->add("Water_水", 70.0);
    sub->add("Oxygen_氧气", 5.0);
    sub->add("Glucose_葡萄糖", 10.0);
    sub->add("AminoAcids_氨基酸", 5.0);
    sub->add("FattyAcids_脂肪酸", 2.0);
    sub->add("Nucleotides_核苷酸", 2.0);
    sub->add("ATP_三磷酸腺苷", 3.0);
    sub->add("Phosphate_无机磷酸盐", 2.0);
    sub->add("Ammonium_铵离子", 1.0);
    sub->add("Potassium_钾离子", 2.0);
    sub->add("Magnesium_镁离子", 1.0);
    sub->add("Calcium_钙离子", 0.5);

    // 代谢产物及废物
    sub->add("CarbonDioxide_二氧化碳", 0.0);
    sub->add("Lactate_乳酸", 0.0);
    sub->add("Acetate_乙酸", 0.0);
    sub->add("Ammonia_氨", 0.0);
    sub->add("Ethanol_乙醇", 0.0);
    sub->add("ReactiveOxygenSpecies_活性氧", 0.0);

    // 主动释放物质
    sub->add("Toxin_毒素", 0.0);
    sub->add("Bacteriocin_细菌素", 0.0);
    sub->add("QuorumSignal_群体感应信号分子", 0.0);
    sub->add("Exopolysaccharide_胞外多糖", 0.0);
    sub->add("Siderophore_铁载体", 0.0);
    sub->add("ExtracellularEnzyme_胞外酶", 0.0);
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
