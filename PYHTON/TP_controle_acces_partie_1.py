#Coding : utf-8
#
#Prenom : Dylan
#Nom    : PERINETTI
#Date   : Mer 2er fèvr.
#heure  : 00:32
#Code   : Controle d'acces SOLO 1.2
#ficname: controlAcc2.py
#

#Import des bibliotèque nécesaire
from datetime import datetime

message = {False: "Non autorisé", True: "Autorisé"}
 
#N° du Badge (n° qui sera normalement récupéré grâce au RFID)
#Saisie utilisateur ID et MDP
user_name  = input("\nUser name :")
user_password = input("\nPassword  :")

#ouvre tous les fichier d'extention .log et .data dans le repertoire courrant 
alllog     = open("all.log", "a")
autorlog   = open("Acces_autor.log", "a")
faillog    = open("acces_interd.log", "a")
autorliste = open(".data", "r")

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
    autorlog.write("\nACCES AUTORISER: "+str(datetime.now())+" USER: "+user_name+"\tPASSWORD: (hash)"+str(hash(user_password)))
    alllog.write("ACCES AUTORISER: "+str(datetime.now())+" USER: "+user_name+"\tPASSWORD: (hash)"+str(hash(user_password))+"\n")
else :
    faillog.write("\nACCES INTERDIT:  "+str(datetime.now())+' USER: '+user_name+"\tPASSWORD: "+user_password)
    alllog.write("ACCES INTERDIT: "+str(datetime.now())+' USER: '+user_name+"\tPASSWORD: "+user_password+"\n")

#fermer tous les fichier ouver 
autorlog.close()
faillog.close()
autorliste.close()
alllog.close()
