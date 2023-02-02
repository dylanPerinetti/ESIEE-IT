#Coding : utf-8
#   Prenom : Dylan
#   Nom    : PERINETTI
#   Date   : Mer 2er fèvr.
#   heure  : 17:55
#   Code   : Controle d'acces Securiser par sha512 2
#   ficname: controlAcc2.py

#Import des fonctions dans les bibliotèques 
from datetime import datetime
from hashlib import sha512
import getpass


#ouvre tous les fichier d'extention .log et .data dans le repertoire courrant 
alllog     = open("all.log", "a")
autorlog   = open("Acces_autor.log", "a")
faillog    = open("acces_interd.log", "a")
autorliste = open(".data", "r")
message = {False: "Non autorisé", True: "Autorisé"}


#Saisie utilisateur ID et MDP à la place du n° du Badge qui sera normalement récupéré grâce au RFID
user_name  = input("\nUser name :")
user_password = getpass.getpass("\nPassword  :")
cpy_user_pass = user_password

#encode() pour géré les caractere utf-8
user_password = user_password.encode()


#sha512() hash le mdp
user_password = str(sha512(user_password).hexdigest())


#Boucle pour cherher une occurence de la concaténation de user;mdp dans le fichier cacher .data
for ligne in autorliste:
    if user_name+';'+user_password == ligne.strip():
        autorisation = True
        break
    else:
        autorisation = False


#Afficher sur a l'écrant si l'on est autorisaté ou non!
print(message[autorisation])


if autorisation == True:
    autorlog.write("\nACCES AUTORISER: "+str(datetime.now())+" USER: "+user_name+"\tPASSWORD: $sha512"+user_password)
    alllog.write("ACCES AUTORISER: "+str(datetime.now())+" USER: "+user_name+"\tPASSWORD: $sha512"+user_password+"\n")
else :
    faillog.write("\nACCES INTERDIT :  "+str(datetime.now())+' USER: '+user_name+"\tPASSWORD: "+cpy_user_pass)
    alllog.write("ACCES INTERDIT :  "+str(datetime.now())+' USER: '+user_name+"\tPASSWORD: "+cpy_user_pass+"\n")


#fermer tous les fichier ouver 
autorlog.close()
faillog.close()
autorliste.close()
alllog.close()
