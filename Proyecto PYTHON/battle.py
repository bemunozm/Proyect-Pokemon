from backpack import Backpack
import time
from random import randint

class Battle:
    def __init__(self,pokemon_1,pokemon_2):
        self.pokemon_1 = pokemon_1
        self.pokemon_2 = pokemon_2
        self.turn = 0
    
    ##Metodo de ataque##
    def miss_attack(self,pokemon):
        miss_probability = randint(0,9)
        miss = False
        if(miss_probability<2):
            print(f"\n\n\n\n\n\n\n\n\n\n{pokemon.get_name()} fallo el ataque!")
            miss = True
            time.sleep(3)
        return miss
        
    def attack(self,attacker,defender,selector):
        
        damage_selector = selector - 1
        damage = attacker.get_damage(damage_selector)
        attack_name = attacker.get_attack(damage_selector)
        
        if attacker.get_type() == defender.get_type():
            damage = damage / 2
        elif (attacker.get_type() == "Fuego") and (defender.get_type() == "Planta"):     
            damage = damage * 2
        elif (attacker.get_type() == "Fuego") and (defender.get_type() == "Agua"):
            damage = damage / 2
        elif (attacker.get_type() == "Agua") and (defender.get_type() == "Planta"):
            damage = damage / 2
        elif (attacker.get_type() == "Agua") and (defender.get_type() == "Fuego"):
            damage = damage * 2
        elif (attacker.get_type() == "Planta") and (defender.get_type() == "Fuego"):
            damage = damage / 2
        elif (attacker.get_type() == "Planta") and (defender.get_type() == "Agua"):
            damage = damage * 2
        
        new_health = defender.get_health() - damage
        defender.set_health(new_health)
        print(f"\n\n\n\n\n\n\n\n\n¡{attacker.get_name()} uso {attack_name}!")
        print(f"Causo {damage} de daño a {defender.get_name()}")
        time.sleep(3)
        if (defender.get_health() <= 0):
            print(f"\n\n\n\n\n\n\n\n\n\n{defender.get_name()} fue derrotado!")
            time.sleep(3)
        else:
            print(f"\n\n\n\n\n\n\n\n\n\n\n\n{defender.get_name()} tiene {defender.get_health()} de vida")
            time.sleep(2)
        
        self.turn += 1
    
    ##Metodo para iniciar el juego##
    def play(self):
        backpack_1 = Backpack(self.pokemon_1)
        backpack_2 = Backpack(self.pokemon_2)
        print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡A luchar contra el campeon GARY!")
        time.sleep(3)
        print(f"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡{self.pokemon_2.get_name()} es el POKEMON enviado por GARY!")
        time.sleep(3)
        print(f"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡Adelante {self.pokemon_1.get_name()}!")
        time.sleep(3)
        while((self.pokemon_1.get_health()>0) and (self.pokemon_2.get_health()>0)):
            if((self.turn%2) == 0 and (self.turn!=-1)):
                i = 0
                while(i==0):
                    print(f"\n\n\n\n\n\n\n\n\nEs el turno de {self.pokemon_1.get_name()}!")
                    print(f"\n\n\n\n\n\n\n\n\n{self.pokemon_1.get_name()}")
                    print(f"HP = {self.pokemon_1.get_health()}")
                    print("----------------MENU----------------")
                    print("\n1 = LUCHA")
                    print("\n2 = MOCHILA")
                    print("\n3 = HUIDA")
                    option = int(input(f"\n¿Que deberia hacer {self.pokemon_1.get_name()}?: "))
                    
                    if(option == 1):
                        print(f"\n\n\n\n\n\n\n\n\n{self.pokemon_1.get_name()}")
                        print(f"HP = {self.pokemon_1.get_health()}")                                                                        #LUCHAR
                        print("----------------MENU ATAQUES----------------")
                        print(f"1.{self.pokemon_1.get_attack(0)} ({self.pokemon_1.get_damage(0)})\t\t\t2.{self.pokemon_1.get_attack(1)} ({self.pokemon_1.get_damage(1)})")
                        print(f"disponibles: {self.pokemon_1.get_uses(0)}\t\t\tdisponibles: {self.pokemon_1.get_uses(1)}")
                        print(f"\n3.{self.pokemon_1.get_attack(2)} ({self.pokemon_1.get_damage(2)})\t\t\t4.{self.pokemon_1.get_attack(3)} ({self.pokemon_1.get_damage(3)})")
                        print(f"disponibles: {self.pokemon_1.get_uses(2)}\t\t\tdisponibles: {self.pokemon_1.get_uses(3)}")
                        select = int(input("\nSeleccione el ataque a usar: "))
                        if(select == 1 and self.pokemon_1.get_uses(0)>0):
                            miss = self.miss_attack(self.pokemon_1)
                            if(miss == False):
                                self.attack(self.pokemon_1,self.pokemon_2,1)
                                new_uses = self.pokemon_1.get_uses(0) - 1
                                self.pokemon_1.set_uses(new_uses,0)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 2 and self.pokemon_1.get_uses(1)>0):
                            miss = self.miss_attack(self.pokemon_1)
                            if(miss == False):
                                self.attack(self.pokemon_1,self.pokemon_2,2)
                                new_uses = self.pokemon_1.get_uses(1) - 1
                                self.pokemon_1.set_uses(new_uses,1)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 3 and self.pokemon_1.get_uses(2)>0):
                            miss = self.miss_attack(self.pokemon_1)
                            if(miss == False):
                                self.attack(self.pokemon_1,self.pokemon_2,3)
                                new_uses = self.pokemon_1.get_uses(2) - 1
                                self.pokemon_1.set_uses(new_uses,2)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 4 and self.pokemon_1.get_uses(3)>0):
                            miss = self.miss_attack(self.pokemon_1)
                            if(miss == False):
                                self.attack(self.pokemon_1,self.pokemon_2,4)
                                new_uses = self.pokemon_1.get_uses(3) - 1
                                self.pokemon_1.set_uses(new_uses,3)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        else:
                            print("Ingrese una opcion valida!")
                            time.sleep(2)
                    elif(option == 2):                                                                      #MOCHILA
                        print(f"\n\n\n\n\n\n\n\n\n{self.pokemon_1.get_name()}")
                        print(f"HP = {self.pokemon_1.get_health()}")
                        print("----------------MOCHILA----------------")
                        print(f"1.POCION +{backpack_1.get_potion_health()} HP ({backpack_1.get_potion()})\t\t\t2.SUPERPOCION +{backpack_1.get_super_potion_health()} HP ({backpack_1.get_super_potion()})")
                        select = int(input("\nSeleccione el item a usar: "))
                        if(select == 1 and backpack_1.get_potion() >= 1):
                            backpack_1.use(1)
                            self.turn += 1
                            i += 1
                        elif(select == 2 and backpack_1.get_super_potion() >= 1):
                            backpack_1.use(2)
                            self.turn += 1
                            i += 1
                        else:
                            print("Ingrese una opcion valida")
                            time.sleep(2)
                    elif(option == 3):
                        print("Has huido!")
                        self.turn = -1
                        i += 1
                    else:
                        print("Ingrese una opcion valida")
                        time.sleep(2)
            elif(self.turn%2!=0 and self.turn!=-1):   ######AUTOMATIZAR CON RANDOMIZE #####
                i=0
                while(i==0):
                    print(f"\n\n\n\n\n\n\n\n\n\n\n\nEs el turno de {self.pokemon_2.get_name()}!")
                    time.sleep(3)
                    if(self.pokemon_2.get_health() <= 75 and (backpack_2.get_potion() >= 1 or backpack_2.get_super_potion() >= 1)):
                        option = 2
                    else:
                        option = 1
                    
                    if(option == 1):
                        select = randint(1,4)
                        if(select == 1 and self.pokemon_2.get_uses(0)>0):
                            miss = self.miss_attack(self.pokemon_2)
                            if(miss == False):
                                self.attack(self.pokemon_2,self.pokemon_1,1)
                                new_uses = self.pokemon_2.get_uses(0) - 1
                                self.pokemon_2.set_uses(new_uses,0)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 2 and self.pokemon_2.get_uses(1)>0):
                            miss = self.miss_attack(self.pokemon_2)
                            if(miss == False):
                                self.attack(self.pokemon_2,self.pokemon_1,2)
                                new_uses = self.pokemon_2.get_uses(1) - 1
                                self.pokemon_2.set_uses(new_uses,1)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 3 and self.pokemon_2.get_uses(2)>0):
                            miss = self.miss_attack(self.pokemon_2)
                            if(miss == False):
                                self.attack(self.pokemon_2,self.pokemon_1,3)
                                new_uses = self.pokemon_2.get_uses(2) - 1
                                self.pokemon_2.set_uses(new_uses,2)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                        elif(select == 4 and self.pokemon_2.get_uses(3)>0):
                            miss = self.miss_attack(self.pokemon_2)
                            if(miss == False):
                                self.attack(self.pokemon_2,self.pokemon_1,4)
                                new_uses = self.pokemon_2.get_uses(3) - 1
                                self.pokemon_2.set_uses(new_uses,3)
                                i += 1
                            else:
                                self.turn += 1
                                i += 1
                    elif(option == 2):
                        if(self.pokemon_2.get_health() <= 75 and backpack_2.get_potion() >= 1):
                            select = 1
                        elif((self.pokemon_2.get_health() <= 50 and backpack_2.get_super_potion() >= 1) or (self.pokemon_2.get_health() <= 75 and backpack_2.get_potion() == 0)):
                            select = 2
                        if(select == 1):
                            backpack_2.use(1)
                            self.turn += 1
                            i += 1
                        elif(select == 2):
                            backpack_2.use(2)
                            self.turn += 1
                            i += 1
                    elif(option == 3):
                        print("Has huido!")
                        self.turn = -1
                        i += 1
                    else:
                        print("Ingrese una opcion valida")
            else:
                break