#include "Country.h"
#include "WarPhase.h"


/**
 * @brief The constructor of the country class. Assign the name of the country and set the stats of the country.
 * @param name [in] Name of the country.
*/
Country::Country(string name,string leader,int budget) : AlliedForce(name){
    this->setCG(false);
    HP=500;
    this->leader=leader;
    cout << name << " has been successfully created. \n";
    transportationCorridor=new TransportationCorridor(10,10,10,10,10);
    stats=new CountryStats();
    stats->setBudget(budget);
    _mil=new Military(); ///
    produceWeapons();
}

/**
 * @brief destructor for the country class. Deallocate all allocate memory in the class [arsenal, _mil, transportationCorridor and stats].
*/
Country::~Country(){
    for(int i=0;i<8;i++){
        if(arsenal[i])
            delete arsenal[i];
    }
    delete [] arsenal;
    delete _mil;
    delete transportationCorridor;
    delete stats;
}


/**
 * @brief Prints the information of the country and their stats. 
 * Prints the country name,leader,strategy of the country and the background statistics of the country.
*/
void Country::print(){
    cout << "============================CountryInfo============================\n";
    cout << "Country Name: " << this->getName() << "\n";
    cout << "Country Leader: " << this->getLeader() << "\n";

    bool surr = false;
    if (this->flag)
        surr = true;
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
        cout <<"[ "<<name<<" ] has allied with { " << a->getName() <<" } Allied Force"<<endl;
        return;
    }
}


/**
 * @brief Receive the damage inflicted on the country by another. The damage received is substracted from the country strength.
 * @param damage Damage inflicted on the country's Health Point.
*/
void Country::receiveDamage(int damage){
    this->HP -= damage;
    cout << this->getName() << " has taken " << damage << " damage and their HP is now " << this->HP << ".\n";
    transportationCorridor->receiveDamage(damage*0.002);
}

/**
 * @brief
 * This attack function takes an opposing AlliedForce object as a parameter. The country calling the function then calculates it's damage and calls the receiving countries receiveDamage function with the appropriate damage variable. 
 *
 * @param c The opposing country which is being attacked.
 */
void Country::attack(AlliedForce* c){
   /** string check = this->getStrategy();
    if (check != "Aggressive Strategy"){
        cout << this->getName() << " is not in the aggressive state and cannot attack!\n";
        return;
    }*/

    int x = getArsenalDmg();
    //ArmyItorator* p = ((Military*)_mil)->createIterator();
    x += static_cast<int>(_mil->getDMG());
    cout << this->getName() << " is now attacking " << c->getName() << ".\n";

    ((Country*)c)->receiveDamage(x);

    if(((Country*)c)->getHp()>0){
        ((Country*)c)->attack(this);
    }else
        ((Country*)c)->defeat();
}

/**
 * @
*/
void Country::defeat(){
    this->HP = 0;
    cout<<name<<" Citizens in despair as their Country is defeated in the battle."<<endl;
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
    HP-=hp;
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
void Country::setStats(int stats[]){
    (this->stats)->setRefugee(stats[0]);
    (this->stats)->setUnlisted(stats[1]);
    (this->stats)->setEnlisted(stats[2]);
    (this->stats)->setReturned(stats[3]);
    (this->stats)->setDeath(stats[4]);
    (this->stats)->setDeployed(stats[5]);
    (this->stats)->setFighting(stats[6]);
    (this->stats)->setStationed(stats[7]);
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
*/
void Country::produceWeapons(){
    //Factories to manufactuer weapons.
    LightWeightFactory* Lf=new LightWeightFactory();
    HeavyWeightFactory* Hf=new HeavyWeightFactory();
    arsenal=new Weapons*[8];

    int d=2,n=3;


    arsenal[0]=Lf->producePistols(d,n);
    arsenal[1]=Lf->produceRifles(d,n);
    arsenal[d]=Lf->produceMachineGuns(d,n);
    arsenal[3]=Lf->produceGrenades(d,n);
    cout<<"****Light Weapons produced and loaded in the arsernal Inventory****"<<endl;
    //cout<<"****Insuficient Funds to produce Light Weapons.****"<<endl;

    arsenal[4]=Hf->produceHelicopters(d,n);
    arsenal[5]=Hf->produceSubmarines(d,n);
    arsenal[6]=Hf->produceWarships(d,n);
    arsenal[7]=Hf->produceTanks(d,n);
    cout<<"****Heavy Weapons produced and loaded in the arsernal Inventory****"<<endl;
    //cout<<"****Insuficient Funds to produce Heavy Weapons.****"<<endl;
}



/**
 * @brief Load the Arsenal inventory with more weapons. This add to the already existing weapons inventory.
 * @param weapons an array contain the amount of weapons for each type of weapons to be added on the Asernal inventory.
*/
void Country::loadWeapons(int weapons[]){
    for(int i=0;i<8;i++){
        arsenal[i]->addNum(weapons[i]);
    }
}

/**
 * @brief Creates an army for the country.It creates an army upon the creation of of the country.
 * @param budget the budget allocated for the creation of the army.
*/
void Country::createArmy(){
    
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