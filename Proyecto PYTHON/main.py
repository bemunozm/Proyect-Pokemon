from pokemon import Pokemon
from battle import Battle
from random import randint

def select_pokemon(player):
    print(f"\n\n\n\t\t\t\tJUGADOR {player}:")
    print("\n1.Charmander")
    print("\n2.Bulbasaur")
    print("\n3.Squirtle")
    if (player == 1):
        select = int(input("\nIngrese el Pokemon que desea usar:"))
    else:
        select = randint(1,3)

    if(select == 1):
        return(Pokemon("Charmander","Fuego",["Ascuas","Colmillo Igneo","Lanzallamas","Pirotecnia"],[20,32,45,35],[5,3,4,4])) #132 y 16
    elif(select == 2):
        return(Pokemon("Bulbasaur","Planta",["Latigo Cepa","Hoja Afilada","Bomba Germen","Doble Filo"],[20,32,40,40],[5,3,4,4])) #132 y 16
    elif(select == 3):
        return(Pokemon("Squirtle","Agua",["Pistola Agua","Hidro Pulso","Acua Cola","Hidrobomba"],[20,32,35,45],[5,3,4,4])) #132 y 16
    else:
        print("Ingrese una opcion valida")

def main():
    #variables
    pokemon_1 = 0
    pokemon_2 = 0
    batalla = 0

    #menu selecciones
    pokemon_1 = select_pokemon(1)
    pokemon_2 = select_pokemon(2)

    #battle mode
    batalla = Battle(pokemon_1,pokemon_2)
    batalla.play()




if __name__ == "__main__":
    main()