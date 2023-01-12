class Pokemon:
    def __init__(self,name,type,attack,damage,uses):
        self._name = name
        self._type = type
        self._level = 50
        self._health = 150
        self._attack = attack
        self._damage = damage
        self._uses = uses
    
    ##GETTERS##
    def get_name(self):
        return self._name
    def get_type(self):
        return self._type
    def get_level(self):
        return self._level
    def get_health(self):
        return self._health
    def get_attack(self,i):
        return self._attack[i]
    def get_damage(self,i):
        return self._damage[i]
    def get_uses(self,i):
        return self._uses[i]
    
    ##SETTERS##
    def set_name(self,name):
        self._name = name
    def set_type(self,type):
        self._type = type
    def set_level(self,level):
        self._level = level
    def set_health(self,health):
        self._health = health
    def set_attack(self,attack,i):
        self._attack[i] = attack
    def set_damage(self,damage,i):
        self._damage[i] = damage
    def set_uses(self,uses,i):
        self._uses[i] = uses