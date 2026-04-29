import os

class Karys:
    def __init__(self, vardas, pavarde, rangas, padalinys):
        self.vardas = vardas
        self.pavarde = pavarde
        self.rangas = rangas
        self.padalinys = padalinys


class Padalinys:
    def __init__(self, pavadinimas):
        self.pavadinimas = pavadinimas


class Technika:
    def __init__(self, pavadinimas, tipas, padalinys):
        self.pavadinimas = pavadinimas
        self.tipas = tipas
        self.padalinys = padalinys


kariai = []
padaliniai = []
technika = []


def issaugoti():
    with open("kariuomene.txt", "w", encoding="utf-8") as f:

        surikiuoti_kariai = sorted(kariai, key=lambda k: (k.vardas.lower(), k.pavarde.lower()))
        surikiuoti_padaliniai = sorted(padaliniai, key=lambda p: p.pavadinimas.lower())
        surikiuota_technika = sorted(technika, key=lambda t: t.pavadinimas.lower())

        f.write("KARIAI:\n")
        for k in surikiuoti_kariai:
            f.write(f"{k.vardas};{k.pavarde};{k.rangas};{k.padalinys}\n")

        f.write("\nPADALINIAI:\n")
        for p in surikiuoti_padaliniai:
            f.write(f"{p.pavadinimas}\n")

        f.write("\nTECHNIKA:\n")
        for t in surikiuota_technika:
            f.write(f"{t.pavadinimas};{t.tipas};{t.padalinys}\n")


def uzkrauti():
    global kariai, padaliniai, technika

    kariai = []
    padaliniai = []
    technika = []

    if not os.path.exists("kariuomene.txt"):
        return

    with open("kariuomene.txt", "r", encoding="utf-8") as f:
        skyrius = None

        for eilute in f:
            eilute = eilute.strip()

            if eilute == "KARIAI:":
                skyrius = "kariai"
                continue
            elif eilute == "PADALINIAI:":
                skyrius = "padaliniai"
                continue
            elif eilute == "TECHNIKA:":
                skyrius = "technika"
                continue

            if not eilute:
                continue

            if skyrius == "kariai":
                vardas, pavarde, rangas, padalinys = eilute.split(";")
                kariai.append(Karys(vardas, pavarde, rangas, padalinys))

            elif skyrius == "padaliniai":
                padaliniai.append(Padalinys(eilute))

            elif skyrius == "technika":
                pavadinimas, tipas, padalinys = eilute.split(";")
                technika.append(Technika(pavadinimas, tipas, padalinys))


def prideti_kari():
    vardas = input("Vardas: ")
    pavarde = input("Pavardė: ")
    rangas = input("Rangas: ")
    padalinys = input("Padalinys: ")

    kariai.append(Karys(vardas, pavarde, rangas, padalinys))
    issaugoti()
    print("Karys pridėtas")


def rodyti_karius():
    if not kariai:
        print("Nėra karių")
        return

    for i, k in enumerate(kariai):
        print(f"{i}. {k.vardas} {k.pavarde}, {k.rangas}, {k.padalinys}")


def salinti_kari():
    rodyti_karius()
    try:
        i = int(input("Pasirink indeksą: "))
        kariai.pop(i)
        issaugoti()
        print("Karys pašalintas")
    except:
        print("Klaida")


def ieskoti_kario():
    tekstas = input("Įvesk vardą arba rangą: ").lower()

    for k in kariai:
        if tekstas in k.vardas.lower() or tekstas in k.rangas.lower():
            print(f"{k.vardas} {k.pavarde}, {k.rangas}, {k.padalinys}")


def prideti_padalini():
    pavadinimas = input("Padalinio pavadinimas: ")
    padaliniai.append(Padalinys(pavadinimas))
    issaugoti()
    print("✅ Padalinys pridėtas")


def rodyti_padalinius():
    for p in padaliniai:
        print(p.pavadinimas)


def prideti_technika():
    pavadinimas = input("Technikos pavadinimas: ")
    tipas = input("Tipas: ")
    padalinys = input("Padalinys: ")

    technika.append(Technika(pavadinimas, tipas, padalinys))
    issaugoti()
    print("✅ Technika pridėta")


def rodyti_technika():
    for t in technika:
        print(f"{t.pavadinimas}, {t.tipas}, {t.padalinys}")


def statistika():
    print(f"Karių: {len(kariai)}")
    print(f"Padalinių: {len(padaliniai)}")
    print(f"Technikos vienetų: {len(technika)}")


def meniu():
    while True:
        print("\n--- Lietuvos kariuomenės sistema ---")
        print("1. Pridėti karį")
        print("2. Rodyti karius")
        print("3. Šalinti karį")
        print("4. Ieškoti kario")
        print("5. Pridėti padalinį")
        print("6. Rodyti padalinius")
        print("7. Pridėti techniką")
        print("8. Rodyti techniką")
        print("9. Statistika")
        print("0. Išeiti")

        pasirinkimas = input(">> ")

        if pasirinkimas == "1":
            prideti_kari()
        elif pasirinkimas == "2":
            rodyti_karius()
        elif pasirinkimas == "3":
            salinti_kari()
        elif pasirinkimas == "4":
            ieskoti_kario()
        elif pasirinkimas == "5":
            prideti_padalini()
        elif pasirinkimas == "6":
            rodyti_padalinius()
        elif pasirinkimas == "7":
            prideti_technika()
        elif pasirinkimas == "8":
            rodyti_technika()
        elif pasirinkimas == "9":
            statistika()
        elif pasirinkimas == "0":
            print("💾 Viskas išsaugota. Iki!")
            break
        else:
            print("Blogas pasirinkimas")


uzkrauti()
meniu()
