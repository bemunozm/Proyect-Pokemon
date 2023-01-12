import time

class Backpack:
    def __init__(self,pokemon):
        self._pokemon = pokemon
        self._potion = 1
        self._potion_health = 25
        self._super_potion = 1
        self._super_potion_health = 50
    
    def use(self,select):
        select = select
        if((select == 1) and (self._potion > 0)):
            print("\n\n\n\n\n\n\n\n\nHaz usado una POCION!")
            print(f"{self._pokemon.get_name()} se a curado {self._potion_health} de vida...")
            new_health = self._pokemon.get_health() + self._potion_health
            self._pokemon.set_health(new_health)
            print(f"{self._pokemon.get_name()} tiene {self._pokemon.get_health()} de vida")
            self._potion = self._potion - 1
            time.sleep(2)
        elif((select == 1) and (self._potion == 0)):
            print("\n\n\n\n\n\n\n\n\n\nNo tienes mas POCIONES!")
            time.sleep(2)
        elif((select == 2) and (self._super_potion > 0)):
            print("\n\n\n\n\n\n\n\n\nHaz usado una SUPERPOCION!")
            print(f"{self._pokemon.get_name()} se a curado {self._super_potion_health} de vida...")
            new_health = self._pokemon.get_health() + self._super_potion_health
            self._pokemon.set_health(new_health)
            print(f"{self._pokemon.get_name()} tiene {self._pokemon.get_health()} de vida")
            self._super_potion = self._super_potion - 1
            time.sleep(2)
        elif((select == 2) and (self._super_potion == 0)):
            print("\n\n\n\n\n\n\n\n\n\nNo tienes mas SUPERPOCIONES!")
            time.sleep(2)
        else:
            print("Ingrese una opcion valida!")

    ##GETTERS##
    def get_pokemon(self):
        return self._pokemon
    def get_potion(self):
        return self._potion
    def get_potion_health(self):
        return self._potion_health
    def get_super_potion(self):
        return self._super_potion
    def get_super_potion_health(self):
        return self._super_potion_health

    ##SETTERS##
    def set_pokemon(self,pokemons):
        self._pokemon = pokemons
    def set_potion(self,potion):
        self._potion = potion
    def set_potion_health(self,health):
        self._potion_health = health
    def set_super_potion(self,super_potion):
        self._super_potion = super_potion
    def set_super_potion_health(self,health):
        self._super_potion_health = health