# Demander le nom à l'utilisateur
nom = input("Quel est ton nom ? ")
age = input("Quel âge as-tu ? ")

# Afficher un message personnalisé
print(f"\nBonjour {nom} !")
print(f"Tu as {age} ans.")

# Vérifier si la personne est majeure
if int(age) >= 18:
    print("Tu es majeur.")
else:
    print("Tu es mineur.")