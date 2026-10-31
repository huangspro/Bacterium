#include "Bacterium.h"
#include <cstdlib>
#include <ctime>


Bacterium::Bacterium(int x, int y, Environment *env):env(env), is_alive(true), health(100), is_touched(false), x(x), y(y), size(1){}

Bacterium::Bacterium(Bacterium &other)
{
    x = other.x;
    y = other.y;
    size = other.size;
    is_alive = other.is_alive;
    health = other.health;
    is_touched = other.is_touched;

    sub = new Substance();
    for (auto i : other.sub->all) {
        this->sub->add(i.first, i.second);
    }
}

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
    sub->add("Protein_蛋白质", 5.0);
    sub->add("Lipid_脂质", 5.0);
    sub->add("DNA_RNA_核酸", 5.0);
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

void Bacterium::step()
{
    move();
    breathe();
    if (rand() % 100 < 70)
        grow();
    if (rand() % 100 < 50)
        divide();
    if (health <= 0)
        die();
}

void Bacterium::die(){
    is_alive = false;
}

void Bacterium::move(){
    int dx[3] = {1, -1, 0};
    int dy[3] = {1, -1, 0};
    int i = 0;
    if(is_alive){
        x += dx[i];
        y += dy[i];
    }
}


void Bacterium::touched(){

}

void Bacterium::divide() {
    if(size >= 50){
        Bacterium *newone = new Bacterium(*this);
        newone->health = 100;
        this->health = 100;
        for (auto i : newone->sub->all)
            i.second /= 2;
        for (auto i : this->sub->all)
            i.second /= 2;

    }
}

void Bacterium::impair_health(double i){
    health -= i;
}

void Bacterium::grow() {
    if (!is_alive || sub == nullptr)
        return;

    // 生长所需原料不足时不生长
    if (sub->get("Glucose_葡萄糖") < 1.0 ||
        sub->get("AminoAcids_氨基酸") < 0.5 ||
        sub->get("ATP_三磷酸腺苷") < 0.5)
        return;

    sub->change("Glucose_葡萄糖", -1.0);
    sub->change("AminoAcids_氨基酸", -0.5);
    sub->change("FattyAcids_脂肪酸", -0.1);
    sub->change("Nucleotides_核苷酸", -0.1);
    sub->change("ATP_三磷酸腺苷", -0.5);
    sub->change("Protein_蛋白质", 0.4);
    sub->change("Lipid_脂质", 0.1);
    sub->change("DNA_RNA_核酸", 0.1);

    env->getSub()->change("Glucose_葡萄糖", -1.0);
    env->getSub()->change("AminoAcids_氨基酸", -0.5);
    env->getSub()->change("FattyAcids_脂肪酸", -0.1);
    env->getSub()->change("Nucleotides_核苷酸", -0.1);
    env->getSub()->change("ATP_三磷酸腺苷", -0.5);
    env->getSub()->change("Protein_蛋白质", 0.4);
    env->getSub()->change("Lipid_脂质", 0.1);
    env->getSub()->change("DNA_RNA_核酸", 0.1);

    size++;
}


void Bacterium::breathe()
{
    if (!is_alive || sub == nullptr)
        return;

    // 检查氧气和葡萄糖是否充足
    if (sub->get("Oxygen_氧气") < 1.0 || sub->get("Glucose_葡萄糖") < 1.0) {
        impair_health(10);
        return;
    }


    sub->change("Glucose_葡萄糖", -1.0);
    sub->change("Oxygen_氧气", -6.0);
    sub->change("CarbonDioxide_二氧化碳", 6.0);
    sub->change("Water_水", 6.0);
    sub->change("ATP_三磷酸腺苷", 30.0);

    env->getSub()->change("Glucose_葡萄糖", -1.0);
    env->getSub()->change("Oxygen_氧气", -6.0);
    env->getSub()->change("CarbonDioxide_二氧化碳", 6.0);
    env->getSub()->change("Water_水", 6.0);
    env->getSub()->change("ATP_三磷酸腺苷", 30.0);

}

Bacterium::~Bacterium(){
    delete sub;
}
