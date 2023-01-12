
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
int HP = 0;
class Pokemon
{
private: //Declarar variables
    string name;
    string type;
    int level;
    string attack[4];
    int damage0, damage1, damage2, damage3;
    int uses0, uses1, uses2, uses3;

public: //Declarar metodos
    int health;
    Pokemon(string name, string type, string attack[4], int damage0, int damage1, int damage2, int damage3, int uses0, int uses1, int uses2, int uses3)
    { //Constructor
        this->name = name;
        this->type = type;
        this->level = 50;
        this->health = 150;
        for (int i = 0; i < 4; i++)
        {
            this->attack[i] = attack[i];
        }
        this->damage0 = damage0;
        this->damage1 = damage1;
        this->damage2 = damage2;
        this->damage3 = damage3;
        this->uses0 = uses0;
        this->uses1 = uses1;
        this->uses2 = uses2;
        this->uses3 = uses3;
    }
    Pokemon()
    { //constructor por defecto
        this->name = "";
        this->type = "";
        this->level = 50;
        this->health = 66;
        for (int i = 0; i < 4; i++)
        {
            this->attack[i] = "";
        }
        this->damage0 = 0;
        this->damage1 = 0;
        this->damage2 = 0;
        this->damage3 = 0;
        this->uses0 = 0;
        this->uses1 = 0;
        this->uses2 = 0;
        this->uses3 = 0;
    }

public:
    void print() // Método para imprimir el contenido del objeto
    {
        cout << "Nombre: " << this->name << endl;
        cout << "Tipo: " << this->type << endl;
        cout << "Nivel: " << this->level << endl;
        cout << "Vida: " << this->health << endl;
        cout << "Ataques: " << endl;
     
    }


int setHealth(int newValue)
{ //Getter y setter para variables privadas requeridas
    this->health = newValue;
    return this->health;
}
int getHealth()
{
    return this->health;
}
string getName()
{
    return this->name;
}
string getType()
{
    return this->type;
}
string getAttack(int num)
{
    return this->attack[num];
}
int getDamage0()
{
    return this->damage0;
}
int getDamage1()
{
    return this->damage1;
}
int getDamage2()
{
    return this->damage2;
}
int getDamage3()
{
    return this->damage3;
}
int getUses0()
{
    return this->uses0;
}
int getUses1()
{
    return this->uses1;
}
int getUses2()
{
    return this->uses2;
}
int getUses3()
{
    return this->uses3;
}
int setUses0(int newvalue)
{
    this->uses0 = newvalue;
    return this->uses0;
};
int setUses1(int newvalue)
{
    this->uses1 = newvalue;
    return this->uses1;
};
int setUses2(int newvalue)
{
    this->uses2 = newvalue;
    return this->uses2;
};
int setUses3(int newvalue)
{
    this->uses3 = newvalue;
    return this->uses3;
};
}
;

class Backpack
{
private:
    int potion_health;
    int super_potion_health;
    

public:                           //Declarar metodos y variables publicas
    int potion_n, super_potion_n; // Cantidad de pociones disponibles
    Pokemon pokemon;
    Backpack(Pokemon pokemon)

    { //Constructor
        this->pokemon = pokemon;
        this->potion_n = 1;
        this->potion_health = 25;
        this->super_potion_n = 1;
        this->super_potion_health = 50;
    };
    void use(int select);
    int getp_hp();
    int getsp_hp();
};

int Backpack::getp_hp()
{
    return this->potion_health;
}
int Backpack::getsp_hp()
{
    return this->super_potion_health;
}
void Backpack::use(int select)
{
    select = select;
    if ((select == 1) && (potion_n > 0))
    {
        cout << "\n\n\n\n\n\n\n\n\nHas usado una POCION!" << endl;
        cout << pokemon.getName() << " se ha curado " << getp_hp() << " de vida..." << endl;
        pokemon.setHealth(HP + getp_hp());
        HP = pokemon.getHealth();
        cout << pokemon.getName() << " tiene " << pokemon.getHealth() << " de vida" << endl;
        potion_n = potion_n - 1;
        this_thread::sleep_for(chrono::seconds(2));
    }
    else if ((select == 1) && (potion_n == 0))
    {
        cout << "\n\n\n\n\n\n\n\n\n\nNo tienes mas POCIONES!" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
    else if ((select == 2) && (super_potion_n > 0))
    {
        cout << "\n\n\n\n\n\n\n\n\nHaz usado una SUPERPOCION!" << endl;
        cout << pokemon.getName() << " se ha curado " << getsp_hp() << " de vida..." << endl;
        pokemon.setHealth(HP + getsp_hp());
        HP = pokemon.getHealth();
        cout << pokemon.getName() << " tiene " << pokemon.getHealth() << " de vida" << endl;
        super_potion_n = super_potion_n - 1;
        this_thread::sleep_for(chrono::seconds(2));
    }
    else if ((select == 2) && (super_potion_n == 0))
    {
        cout << "\n\n\n\n\n\n\n\n\n\nNo tienes mas SUPERPOCIONES!" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
    else
    {
        cout << "Ingrese una opcion valida!" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

class Battle
{
    // INICIALIZAR ATRIBUTOS
public:
    Pokemon pokemon_1;
    Pokemon pokemon_2;
    int turn;
    // INICIALIZAR METODOS
public:
    Battle(Pokemon pokemon_1, Pokemon pokemon_2);
    bool miss_attack(Pokemon);
    void attack(Pokemon, Pokemon, int); //tipo de variable que es, en este caso es de la clase Pokemon
    void play();
};
Battle::Battle(Pokemon pokemon_1, Pokemon pokemon_2)
{
    this->pokemon_1 = pokemon_1;
    this->pokemon_2 = pokemon_2;
    this->turn = 0;
}

//METODOS
bool Battle::miss_attack(Pokemon pokemon)
{
    srand(time(NULL));
    int miss_probability = rand() % 10;
    bool miss = false;
    if (miss_probability < 2)
    {
        cout << pokemon.getName() << " falló el ataque" << endl;
        miss = true;
    }
    return miss;
}

void Battle::attack(Pokemon attacker, Pokemon defender, int selector)
{
    int damage_selector = selector - 1;
    int damage = 0;
    if (selector == 1)
    {
        damage = attacker.getDamage0();
    }
    if (selector == 2)
    {
        damage = attacker.getDamage1();
    }
    if (selector == 3)
    {
        damage = attacker.getDamage2();
    }
    if (selector == 4)
    {
        damage = attacker.getDamage3();
    }
    string attack_name = attacker.getAttack(damage_selector);

    if (attacker.getType() == defender.getType())
    {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Fuego") && (defender.getType() == "Planta"))
    {
        damage = damage * 2;
    }
    else if ((attacker.getType() == "Fuego") && (defender.getType() == "Agua"))
    {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Agua") && (defender.getType() == "Planta"))
    {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Agua") && (defender.getType() == "Fuego"))
    {
        damage = damage * 2;
    }
    else if ((attacker.getType() == "Planta") && (defender.getType() == "Fuego"))
    {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Planta") && (defender.getType() == "Agua"))
    {
        damage = damage * 2;
    }
    
    defender.setHealth(defender.getHealth() - damage);
    HP = defender.getHealth();
    //defender.setHealth(666);
    cout << attacker.getName() << " uso " << attack_name << "!" << endl;
    cout << "Causo " << damage << " de daño a " << defender.getName() << endl;
    this_thread::sleep_for(chrono::seconds(2));

    if (defender.getHealth() <= 0)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n"
             << defender.getName() << " fue derrotado!" << endl;
    }
    else
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n"
             << defender.getName() << " tiene " << defender.getHealth() << " de vida" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    turn++;
}
void Battle::play()
{
    Backpack backpack_1 = Backpack(pokemon_1);
    Backpack backpack_2 = Backpack(pokemon_2);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡A luchar contra el campeon GARY!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << pokemon_2.getName() << " ¡Es el POKEMON enviado por GARY!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡Adelante " << pokemon_1.getName() << "!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    while ((pokemon_1.getHealth() > 0) && (pokemon_2.getHealth() > 0))
    {
        
        
        int i = 0;
        if ((turn % 2) == 0 && (turn != -1))
        {
            i = 0;
            while (i == 0)
            {
                cout << "\n\n\n\n\n\n\n\n\nEs el turno de " << pokemon_1.getName() << "!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "\n\n\n\n\n\n\n\n\n" << pokemon_1.getName() << endl;
                cout << "HP = " << pokemon_1.getHealth() << endl;
                cout << "----------------MENU----------------" << endl;
                cout << "\n1 = LUCHA" << endl;
                cout << "\n2 = MOCHILA" << endl;
                cout << "\n3 = HUIDA" << endl;
                int option;
                cout << "¿Que deberia hacer " << pokemon_1.getName() << "?: " << endl;
                cin >> option;
                if (option == 1)
                {
                    cout << "\n\n\n\n\n\n\n\n\n" << pokemon_1.getName() << endl;
                    cout << "HP = " << pokemon_1.getHealth() << endl; //LUCHAR
                    cout << "----------------MENU ATAQUES----------------" << endl;
                    cout << "1. " << pokemon_1.getAttack(0) << " " << pokemon_1.getDamage0() << "\t\t\t2. " << pokemon_1.getAttack(1) << " " << pokemon_1.getDamage1() << endl;
                    cout << "Disponibles: " << pokemon_1.getUses0() << "\t\t\tDisponibles: " << pokemon_1.getUses1() << endl;
                    cout << "3." << pokemon_1.getAttack(2) << " " << pokemon_1.getDamage2() << "\t\t\t4. " << pokemon_1.getAttack(3) << " " << pokemon_1.getDamage3() << endl;
                    cout << "Disponibles: " << pokemon_1.getUses2() << "\t\t\tDisponibles: " << pokemon_1.getUses3() << endl;
                    int select;
                    cout << "\nSeleccione el ataque a usar: " << endl;
                    cin >> select;
                    if (select == 1 && pokemon_1.getUses0() > 0)
                    {
                        bool miss = miss_attack(pokemon_1);
                        if (miss == false)
                        {
                            attack(pokemon_1, pokemon_2, 1);
                            pokemon_2.setHealth(HP);
                            pokemon_1.setUses0(pokemon_1.getUses0() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 2) && (pokemon_1.getUses1() > 0))
                    {
                        bool miss = miss_attack(pokemon_1);
                        if (miss == false)
                        {
                            attack(pokemon_1, pokemon_2, 2);
                            pokemon_2.setHealth(HP);
                            pokemon_1.setUses1(pokemon_1.getUses1() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 3) && (pokemon_1.getUses2() > 0))
                    {
                        bool miss = miss_attack(pokemon_1);
                        if (miss == false)
                        {
                            attack(pokemon_1, pokemon_2, 3);
                            pokemon_2.setHealth(HP);
                            pokemon_1.setUses2(pokemon_1.getUses2() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 4) && (pokemon_1.getUses3() > 0))
                    {
                        bool miss = miss_attack(pokemon_1);
                        if (miss == false)
                        {
                            attack(pokemon_1, pokemon_2, 4);
                            pokemon_2.setHealth(HP);
                            pokemon_1.setUses3(pokemon_1.getUses3() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else
                    {
                        cout << "Ingrese una opcion valida!" << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
                else if (option == 2)
                { //MOCHILA
                    cout << "\n\n\n\n\n\n\n\n\n"
                         << pokemon_1.getName() << endl;
                    cout << "HP = " << pokemon_1.getHealth() << endl;
                    cout << "----------------MOCHILA----------------" << endl;
                    cout << "1.POCION + " << backpack_1.getp_hp() << "HP (" << backpack_1.potion_n << ")\t\t\t2.SUPERPOCION +" << backpack_1.getsp_hp() << "HP (" << backpack_1.super_potion_n << ")" << endl;
                    int select;
                    cout << "\nSeleccione el item a usar: " << endl;
                    cin >> select;
                    if ((select == 1) && backpack_1.potion_n >= 1)
                    {
                        backpack_1.use(1);
                        pokemon_1.setHealth(HP);
                        turn++;
                        i++;
                    }
                    else if ((select == 2) && backpack_1.super_potion_n >= 1)
                    {
                        backpack_1.use(2);
                        pokemon_1.setHealth(HP);
                        turn++;
                        i++;
                    }
                    else
                    {
                        cout << "Ingrese una opcion valida" << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }

                else if (option == 3)
                {
                    cout << "Has huido!" << endl;
                    turn = -1;
                    i++;
                }
                else
                {
                    cout << "Ingrese una opcion valida" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                }
            }
        }
        else if ((turn % 2 != 0) && (turn != -1))
        { //AUTOMATIZAR CON RANDOMIZE
            int select = 0;
            int option = 0;
            i = 0;
            while (i == 0)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\nEs el turno de " << pokemon_2.getName() << "!" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                if ((pokemon_2.getHealth() <= 75) && ((backpack_2.potion_n >= 1) || (backpack_2.super_potion_n >= 1)))
                {
                    option = 2;
                }
                else
                {
                    option = 1;
                }
                if (option == 1)
                {
                    
                    select = (rand() % 4) + 1;
                    if ((select == 1) && (pokemon_2.getUses0() > 0))
                    {
                        bool miss = miss_attack(pokemon_2);
                        if (miss == false)
                        {
                            attack(pokemon_2, pokemon_1, 1);
                            pokemon_1.setHealth(HP);
                            pokemon_2.setUses0(pokemon_2.getUses0() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 2) && (pokemon_2.getUses1() > 0))
                    {
                        bool miss = miss_attack(pokemon_2);
                        if (miss == false)
                        {
                            attack(pokemon_2, pokemon_1, 2);
                            pokemon_1.setHealth(HP);
                            pokemon_2.setUses1(pokemon_2.getUses1() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 3) && (pokemon_2.getUses2() > 0))
                    {
                        bool miss = miss_attack(pokemon_2);
                        if (miss == false)
                        {
                            attack(pokemon_2, pokemon_1, 3);
                            pokemon_1.setHealth(HP);
                            pokemon_2.setUses2(pokemon_2.getUses2() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                    else if ((select == 4) && (pokemon_2.getUses3() > 0))
                    {
                        bool miss = miss_attack(pokemon_2);
                        if (miss == false)
                        {
                            attack(pokemon_2, pokemon_1, 4);
                            pokemon_1.setHealth(HP);
                            pokemon_2.setUses3(pokemon_2.getUses3() - 1);
                            i++;
                        }
                        else if (miss == true)
                        {
                            turn++;
                            i++;
                        }
                    }
                }
                else if (option == 2)
                {
                    if ((pokemon_2.getHealth() <= 75) && (backpack_2.potion_n >= 1))
                    {
                        select = 1;
                    }
                    else if ((pokemon_2.getHealth() <= 50) && (backpack_2.super_potion_n >= 1) || (pokemon_2.getHealth() <=75) && (backpack_2.potion_n == 0) )
                    {
                        select = 2;
                    }
                    if (select == 1)
                    {
                        backpack_2.use(1);
                        pokemon_2.setHealth(HP);
                        turn++;
                        i++;
                    }
                    else if (select == 2)
                    {
                        backpack_2.use(2);
                        pokemon_2.setHealth(HP);
                        turn++;
                        i++;
                    }
                    else if (option == 3)
                    {
                        cout << "Has huido!" << endl;
                        turn = -1;
                        i++;
                    }
                    else
                    {
                        cout << ("Ingrese una opcion valida") << endl;
                        cout << option;
                        srand(time(NULL));
                    }
                }
            }
        }
        else
            break;
    }
}

Pokemon select_pokemon(int player)
{
    cout << "\n\n\n\t\t\t\tJUGADOR " << player << ":" << endl;
    cout << "\n1.Charmander" << endl;
    cout << "\n2.Bulbasaur" << endl;
    cout << "\n3.Squirtle" << endl;

    int select = 0;
    if (player == 1)
    {
        cout << "\nIngrese el Pokemon que desea usar: ";
        cin >> select;
    }
    else
    {
        select = rand() % 3 + 1;
    }

    if (select == 1)
    {
        string attacks[4] = {"Ascuas", "Colmillo Igneo", "Lanzallamas", "Pirotecnia"};
        Pokemon pokemon("Charmander", "Fuego", attacks, 20, 32, 45, 35, 5, 3, 4, 4);
        return pokemon;
    }
    else if (select == 2)
    {
        string attacks[4] = {"Latigo Cepa", "Hoja Afilada", "Bomba Germen", "Doble Filo"};
        Pokemon pokemon("Bulbasaur", "Planta", attacks, 20, 32, 40, 40, 5, 3, 4, 4);
        return pokemon;
    }
    else if (select == 3)
    {
        string attacks[4] = {"Pistola Agua", "Hidro Pulso", "Acua Cola", "Hidrobomba"};
        Pokemon pokemon("Squirtle", "Agua", attacks, 20, 32, 35, 45, 5, 3, 4, 4);
        return pokemon;
    }
    else
    {
        cout << "Ingrese una opcion valida" << endl;
        string attacks[4] = {"", "", "", ""};
        return Pokemon("", "", attacks, 0, 0, 0, 0, 0, 0, 0, 0);
    };
}

int main()
{
    srand(time(NULL));

    Pokemon pokemon_1 = select_pokemon(1);
    Pokemon pokemon_2 = select_pokemon(2);

    Battle batalla = Battle(pokemon_1, pokemon_2);
    batalla.play();

    return 0;
}
