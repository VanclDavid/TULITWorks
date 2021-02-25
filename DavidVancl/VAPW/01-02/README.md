1. Modus
Prvky ve formuláři: Button, Label
Napište program, který po stisknutí tlačítka sestaví pole 10-20 integerů (klidně nastavte čísla ručně přímo v kódu, ale je možné je i náhodně vygenerovat) a v poli najde modus, tj. nejčastěji se vyskytující číslo. Výsledek se vypíše do labelu.

2. Trojúhelníková nerovnost
Prvky ve formuláři: Button, 3× NumericUpDown
Napište metodu, která ověří trojúhelníkovou nerovnost a další metodu, která ze tří stran spočítá obsah trojúhelníka. Po stisknutí tlačítka program ověří nerovnost a spočítá obsah, je-li splněna.
Zvláštní požadavky: Trojúhelníková nerovnost a obsah mají být počítány ve zvláštních metodách.
Pozn.: Při výpočtech v plovoucí desetinné čárce hrozí při počítání rozdílu dvou hodně blízkých čísel ztráta přesnosti (rozdíl má méně platných číslic než vstupní hodnoty). Klasický Heronův vzorec tak může být pro extrémně ploché trojúhelníky nepřesný. Lépe použijte:
S = sqrt( (a+(b+c)) * (c-(a-b)) * (c+(a-b)) * (a+(b-c)) ) / 4
a &gt;= b &gt;= c 
Rozdíl oproti Heronovu vzorci si můžete vyzkoušet (např. a = b = 10^8, c = 10^(-8)).