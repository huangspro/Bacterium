#include "Bacterium.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Bacterium::Bacterium(int x, int y, Environment *env)
    : env(env)
    , is_alive(true)
    , health(100)
    , is_touched(false)
    , x(x)
    , y(y)
    , size(1)
{
    init_sub();
}

Bacterium::Bacterium(Bacterium &other)
{
    x = other.x;
    y = other.y;
    size = other.size;
    is_alive = other.is_alive;
    health = other.health;
    is_touched = other.is_touched;

    sub = new Substance();
    for (auto i : other.sub->all)
        this->sub->add(i.first, i.second);

}


void Bacterium::init_sub() {
    sub = new Substance();

    // 水：细胞含水量约占湿重的70%
    sub->add("Water_水", 38800.0);

    // 能量代谢相关
    sub->add("Oxygen_氧气", 0.005);
    sub->add("Glucose_葡萄糖", 0.05);
    sub->add("ATP_三磷酸腺苷", 3.0);

    // 生物合成原料
    sub->add("AminoAcids_氨基酸", 100.0);
    sub->add("FattyAcids_脂肪酸", 0.5);
    sub->add("Nucleotides_核苷酸", 5.0);

    // 无机离子及代谢辅助物质
    sub->add("Phosphate_无机磷酸盐", 10.0);
    sub->add("Ammonium_铵离子", 5.0);
    sub->add("Potassium_钾离子", 200.0);
    sub->add("Magnesium_镁离子", 10.0);
    sub->add("Calcium_钙离子", 0.0001);

    // 细胞结构物质
    sub->add("Protein_蛋白质", 300.0);
    sub->add("Lipid_脂质", 100.0);
    sub->add("DNA_RNA_核酸", 100.0);


    // 代谢产物及废物（mmol/L）
    sub->add("CarbonDioxide_二氧化碳", 1.0);
    sub->add("Lactate_乳酸", 0.0);
    sub->add("Acetate_乙酸", 0.0);
    sub->add("Ammonia_氨", 0.0);
    sub->add("Ethanol_乙醇", 0.0);
    sub->add("ReactiveOxygenSpecies_活性氧", 0.000001);


    // 主动释放物质（细胞内储量，mmol/L）
    sub->add("Toxin_毒素", 0.0);
    sub->add("Bacteriocin_细菌素", 0.0);
    sub->add("QuorumSignal_群体感应信号分子", 0.0);
    sub->add("Exopolysaccharide_胞外多糖", 0.0);
    sub->add("Siderophore_铁载体", 0.0);
    sub->add("ExtracellularEnzyme_胞外酶", 0.0);
}


void Bacterium::step()
{
    breathe();
    feed();
    if (rand() % 100 < 70)
        grow();
}

void Bacterium::die(){
    is_alive = false;
    env->has_bacterium = false;
    env->delete_bac();
}



void Bacterium::touched(){

}

Bacterium *Bacterium::divide()
{
    if(size >= 50){
        Bacterium *newone = new Bacterium(*this);
        newone->health = 100;
        this->health = 100;
        for (auto i : newone->sub->all)
            i.second /= 2;
        for (auto i : this->sub->all)
            i.second /= 2;
        return newone;
    }
    return nullptr;
}

void Bacterium::check_health(){

}

void Bacterium::grow() {
    if (!is_alive || sub == nullptr || env == nullptr)
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

    size += 10;
}

void Bacterium::feed()
{
    if (!is_alive || sub == nullptr || env == nullptr)
        return;

    // 获取环境中的物质
    Substance *env_sub = env->getSub();

    if (env_sub == nullptr)
        return;

    sub->change("CarbonDioxide_二氧化碳", 0.05);
    // 吸收水
    if (env_sub->get("Water_水") > 0)
    {
        double amount = std::min(5.0, env_sub->get("Water_水"));
        env_sub->change("Water_水", -amount);
        sub->change("Water_水", amount);
    }
    if (env_sub->get("Oxygen_氧气") > 0)
        env_sub->change("Oxygen_氧气", -0.05);

    // 吸收葡萄糖
    if (env_sub->get("Glucose_葡萄糖") > 0)
        env_sub->change("Glucose_葡萄糖", -1.0);

    // 吸收氨基酸
    if (env_sub->get("AminoAcids_氨基酸") > 0)
    {
        double amount = std::min(0.2, env_sub->get("AminoAcids_氨基酸"));
        env_sub->change("AminoAcids_氨基酸", -amount);
        sub->change("AminoAcids_氨基酸", amount);
    }

    // 吸收脂肪酸
    if (env_sub->get("FattyAcids_脂肪酸") > 0)
    {
        double amount = std::min(0.01, env_sub->get("FattyAcids_脂肪酸"));
        env_sub->change("FattyAcids_脂肪酸", -amount);
        sub->change("FattyAcids_脂肪酸", amount);
    }

    // 吸收核苷酸
    if (env_sub->get("Nucleotides_核苷酸") > 0)
    {
        double amount = std::min(0.1, env_sub->get("Nucleotides_核苷酸"));
        env_sub->change("Nucleotides_核苷酸", -amount);
        sub->change("Nucleotides_核苷酸", amount);
    }

    // 吸收无机磷酸盐
    if (env_sub->get("Phosphate_无机磷酸盐") > 0)
    {
        double amount = std::min(0.5, env_sub->get("Phosphate_无机磷酸盐"));
        env_sub->change("Phosphate_无机磷酸盐", -amount);
        sub->change("Phosphate_无机磷酸盐", amount);
    }

    // 吸收铵离子
    if (env_sub->get("Ammonium_铵离子") > 0)
    {
        double amount = std::min(0.5, env_sub->get("Ammonium_铵离子"));
        env_sub->change("Ammonium_铵离子", -amount);
        sub->change("Ammonium_铵离子", amount);
    }

    // 吸收钾离子
    if (env_sub->get("Potassium_钾离子") > 0)
    {
        double amount = std::min(0.5, env_sub->get("Potassium_钾离子"));
        env_sub->change("Potassium_钾离子", -amount);
        sub->change("Potassium_钾离子", amount);
    }

    // 吸收镁离子
    if (env_sub->get("Magnesium_镁离子") > 0)
    {
        double amount = std::min(0.2, env_sub->get("Magnesium_镁离子"));
        env_sub->change("Magnesium_镁离子", -amount);
        sub->change("Magnesium_镁离子", amount);
    }

    // 吸收钙离子
    if (env_sub->get("Calcium_钙离子") > 0)
    {
        double amount = std::min(0.1, env_sub->get("Calcium_钙离子"));
        env_sub->change("Calcium_钙离子", -amount);
        sub->change("Calcium_钙离子", amount);
    }
}

void Bacterium::breathe()
{
    if (!is_alive || sub == nullptr || env == nullptr)
        return;
    // 检查氧气和葡萄糖是否充足
    if (sub->get("Oxygen_氧气") < 0.05 || sub->get("Glucose_葡萄糖") < 1.0) {
        health -= 10;
        return;
    }


    sub->change("Glucose_葡萄糖", -1.0);
    sub->change("Oxygen_氧气", -0.05);
    sub->change("Water_水", 3.0);
    sub->change("ATP_三磷酸腺苷", 30.0);


    env->getSub()->change("Oxygen_氧气", -6.0);
    env->getSub()->change("CarbonDioxide_二氧化碳", 0.05);
    env->getSub()->change("Water_水", 3.0);
}

Bacterium::~Bacterium(){
    delete sub;
}
