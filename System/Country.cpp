#include "Country.h"
#include "WarPhase.h"


/**
 * @brief The constructor of the country class. Assign the name of the country and set the stats of the country.
 * @param name [in] Name of the country.
*/
Country::Country(string name) : AlliedForce(name) {
    this->setCG(false);
    cout << name << " has been successfully created. \n";
    setStats();
    
}


/**
 * @brief Prints the information of the country and their stats. 
 * Prints the country name,leader,strategy of the country and the background statistics of the country.
*/
void Country::print(){
    cout << "============================CountryInfo============================\n";
    cout << "Country Name: " << this->getName() << "\n";
    cout << "Country Leader: " << this->getLeader() << "\n";

    // bool o = false;
    // if (this->isNeutral)
    //     o = true;
    // cout << "Country Neutral: " << o << "\n";

    bool surr = false;
    if (this->flag)
        surr = true;
    //cout << "Country Surrendered: " << surr;
    if (surr){
        cout << "Country Surrendered: True"<<endl;
    }else{
        cout << "Country Surrendered: False"<<endl;
    }
    stats->print();
    cout<<endl<<endl<<endl;
}

/**
 * @brief Set the alliance of the country. 
 * @param a [in] An AlliedForce* instance assigned AlliedForce of the country.
*/
void Country::setAlliance(AlliedForce* a){
    if (this->A  == NULL){
        this->A = a;
        cout << "This country now belongs to " << a->getName()<<endl;
        return;
    }
}


/**
 * @brief Receive the damage inflicted on the country by another. The damage received is substracted from the country strength.
 * @param damage Damage inflicted on the country's Health Point.
*/
void Country::receiveDamage(int damage){
    if (this->HP - damage <= 0)
        this->HP = 0;
    else
        this->HP -= damage;
    cout << this->getName() << " has taken " << damage << " damage and their HP is now " << this->HP << ".\n";
    transportationCorridor->receiveDamage(damage*0.2);
}

/**
 * @brief
 * This attack function takes an opposing AlliedForce object as a parameter. The country calling the function then calculates it's damage and calls the receiving countries receiveDamage function with the appropriate damage variable. 
 *
 * @param c The opposing country which is being attacked.
 */
void Country::attack(AlliedForce* c){
    // cout<<"hello1\n";
    // string phase = "";
    // phase = this->phase->getPhase();
    // if (phase == "Intelligence Phase ."){
    //     cout << "Cannot attack in the intelligence phase!\n";
    //     return;
    // }
    // else if (phase == "Finished Phase ."){
    //     cout << "Cannot attack whilst the war is finished!\n";
    //     return;
    // }

    string check = this->getStrategy();
    if (check != "Aggressive Strategy"){
        cout << this->getName() << " is not in the aggressive state and cannot attack!\n";
        return;
    }

    // cout<<"hello1\n";
    // int x = getArsenalDmg();
    // cout<<"hello2\n";
    // ArmyItorator* p = (this->_mil)->createIterator();
    // cout<<"hello3\n";
    // x += static_cast<int>(_mil->getMilitaryDamage());
    // cout<<"hello4\n";
    // cout << this->getName() << " is now attacking " << c->getName() << ".\n";
    // cout<<"hello5\n";
    ((Country*)c)->receiveDamage(rand()%1000000);
    //cout<<"hello6\n";
}

/**
 * @brief A getter for the country Strategy.
 * @return The current country Strategy.
*/
string Country::getStrategy(){
    //cout<< strategy->getCountryStrategy() << endl ;
    return strategy->getCountryStrategy();
}


/**
 * @brief Sets the phase of the war. Output a message indicating the phase the war is currently at.
*/
void Country::setWarPhase(){
    char answer ;
    cout<<"What Phase of the war is the Country in currently ? \n Type 'A' - IntelligencePhase \n Type 'B' - InitiationPhase \n Type 'C' - OccupationPhase \n Type 'D' - FinishedPhase \n Type 'E' - NeutralPhase \n" ;
    cin>> answer ;
    switch(answer){
      case 'A':
        this->phase = new IntelligencePhase() ;
        cout<<"IntelligencePhase chosen \n";
        break;
      case 'B':
        this->phase = new InitiationPhase();
        cout<<"InitiationPhase chosen \n";
        break;
      case 'C':
        this->phase = new OccupationPhase();
        cout<<"OccupationPhase chosen \n";
        break;
      case 'D':
        this->phase = new FinishedPhase();
        cout<<"FinishedPhase chosen \n";
        break;
      case 'E':
        this->phase = new NeutralPhase();
        cout<<"NeutralPhase chosen \n";
        break;
      default:
        cout<<"No strategy chosen \n" ;
      
    }
  // delete phase ;
   //phase = phase_ ;
}


void Country::iteratePhases(WarPhase* phase_){
    delete phase;
    this->phase = phase_ ;
}

/**
 * @brief A getter for the phase of the war.\
 * @return The phase of the war.
*/
string Country::getCurrentPhase(){
    
   return phase->getPhase();
}

/**
 * @brief update the warPhase. It changes the references the current country have on the war to the current warphase of the war.
*/
void Country::changeWarPhase(){
    phase->change(this) ;
}


/**
 * @brief Set the country battle strategy based on user input. 
*/
void Country::setCountryStrategy(char answer){
    // char answer ;
    // cout<<"What Strategy is the Country using currently ? \n Type 'A' if country is Aggresive \n Type 'B' if country is Defensive \n Type 'C' if country is Supportive ." << endl ;
    // cin>> answer ;
    switch (answer){
     case 'A':
        this->strategy = new Aggresive() ;
        cout<<"Country Strategy: Aggressive Strategy \n" ;
        break;
     case 'D':
        this->strategy = new Defensive() ;
        cout<<"Country Strategy: Defensive Strategy \n" ;
        break;
    case 'S':
        this->strategy = new Supportive() ;
        cout<<"Country Strategy: Supportive Strategy \n" ;
        break;
    default:
       cout<<"Invalid Strategy \n" ;
    }
    
}

/**
 * @brief Request Assistance from allies that are in supportive mode.
 * This function creates an iterator for the calling Country's CountryGroup, and iterates through this group. 
 * If any of the AlliedForces in this group are in the supportive strategy, then that country will support the country calling for assistance.
 * It output a message indicating if it got assistance or not.
 */
void Country::requestAssistance(){
    CountryGroupIterator* ptr = myGroup->CreateGroupIterator();
    string tmp = "";

    for (ptr->first(); ptr->hasNext(); ptr->next()){
        Country* c=(Country*)ptr->current();
        if (c->getStrategy() == "supportive" && c->getHp() > 0){
            c->support(this);
            cout << this->getName() << " is now receiving assistance from " << c->getName() << ".\n";
            return;
        }
    }
    cout << "No countries in this alliance are in supportive mode.\n";
}

/**
 * @brief offer support to the country in need of support. Offers 50% of it' Health point to the country in need.
 * @param c Allied country in need of support.
*/
void Country::support(Country* c){
    int hp=HP*0.5;
    HP=hp;
    c->increaseHP(hp);
}

/**
 * @brief Increase the Health point of the country by the passed in int paramater.
 * @param v [in] increase the HP of the country by this much.
*/
void Country::increaseHP(int v){
    this->HP += v;
}

/**
 * @brief A getter for the leader of the country.
 * @return The leader of the country.
*/
string Country::getLeader(){
    return this->leader;
}


/**
 * @brief Checks if the state of the country is neutral.
 * @return A boolean varible indicating if the state of country is neutral.
*/
bool Country::getNeutral(){
    return this->isNeutral;
}

bool Country::getsurr(){
    return this->flag;
}



/**
 * @brief A getter for the Health Point of the country.
 * @return The leader of the country.
*/
int Country::getHp(){
    return this->HP;
}

/**
 * @brief A setter for the leader of the country.
 * @param L [in] Variable to set the name of the leader of the country.
*/
void Country::setLeader(string L){
    this->leader = L;
}

/**
 * @brief A setter for the Neutral state of the country.
 * @param b a boolean variable to set the state of the country.
*/
void Country::setNeutral(bool b){
    this->isNeutral = b;
}

/**
 * @brief 
 * @param 
*/
void Country::setsurr(bool b){
    this->flag = b;
}

/**
 * @brief A setter for the Military object of the country.
 * @param m [Military*] Military object to set the _mil member variable.
*/
void Country::setMil(Military* m){
    this->_mil = m;
}

/**
 * @brief Set the background stats of the country. Reads the stats from a @dir "../data/data.txt".
*/
void Country::setStats(){
    stats=new CountryStats();
}

/**
 * @brief A setter for the TransportationCorridor object of the country.
 * @param t [TransportationCorridor*] TransportationCorridor object to set the transportationCorridor member variable.
*/
void Country::setTransportationCorridor(TransportationCorridor* t){
    this->transportationCorridor = t;
}

/**
 * @brief Produce different weapons for a country based on the budget of weapons the country have.
 * @param budget [int] The budget of weapons.
*/
void Country::produceWeapons(int budget){
    int costPerBadge=budget/8;
    LightWeightFactory* Lf=new LightWeightFactory();
    HeavyWeightFactory* Hf=new HeavyWeightFactory();
    int LfPrice=costPerBadge/5;
    int HfPrice=costPerBadge/10;
    for(int i=0;i<8;i++){
        arsenal[i]=nullptr;
    }


    if(LfPrice>0){
        arsenal[0]=Lf->producePistols(2,LfPrice);
        arsenal[1]=Lf->produceRifles(2,LfPrice);
        arsenal[2]=Lf->produceMachineGuns(2,LfPrice);
        arsenal[3]=Lf->produceGrenades(2,LfPrice);
        cout<<"****Light Weapons produced and loaded in the arsernal Inventory****"<<endl;
    }else
        cout<<"****Insuficient Funds to produce Light Weapons.****"<<endl;

    
    if(HfPrice>0){
        arsenal[4]=Hf->produceHelicopters(2,HfPrice);
        arsenal[5]=Hf->produceSubmarines(2,HfPrice);
        arsenal[6]=Hf->produceWarships(2,HfPrice);
        arsenal[7]=Hf->produceTanks(2,HfPrice);
        cout<<"****Heavy Weapons produced and loaded in the arsernal Inventory****"<<endl;
    }else
        cout<<"****Insuficient Funds to produce Heavy Weapons.****"<<endl;
}


/**
 * @brief Get the total damage of the arsenal Inventory of a country.
 * @return The total damage of the Arsenal inventory of the country.
*/
int Country::getArsenalDmg(){
    int TotalDamage=0;
    for(int i=0;i<8;i++){
        if(arsenal[i]!=nullptr)
            TotalDamage+=arsenal[i]->getTotalDamage();
    }
    return TotalDamage;
}