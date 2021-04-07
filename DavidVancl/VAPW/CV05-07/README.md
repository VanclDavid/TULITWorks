5. úkol - Dědění
Prvky ve formuláři: Button
Navrhněte abstraktní třídu Utvar, která představuje obecně jakýkoliv pravidelný n-stěn v trojrozměrném prostoru. Tato obecná třída má v sobě uloženu délku hrany n-stěnu a předepisuje, že její potomci musí implementovat:
a) veřejnou metodu na výpočet objemu
b) veřejný getter na výpočet povrchu (read-only)
Dále navrhněte třídy, které reprezentují:
1. krychli
2. dvanáctistěn
3. dvacetistěn
4. kouli (při výpočtech je délka hrany interpretována jako poloměr)
Tyto třídy dědí ze třídy Utvar, a proto musí implementovat výše uvedenou metodu a getter, avšak každá jinak. Stiskem tlačítka se založí instance těchto tříd a v každé instanci se zavolá výpočet objemu a povrchu - výsledky se vhodným způsobem zobrazí (Labely, MessageBox...).
Pozn.: třída Utvar je abstraktní třídou, která metodu Objem() ani getter Povrch přímo neimplementuje, avšak vynutí jejich implementaci v potomcích.

6. úkol - Kolekce a listboxy
Prvky na formuláři: 3x Button, Textbox, NumericUpDown, 2x RadioButton, Label, ListBox
Navrhněte třídu, která bude reprezentovat osobu (má své jméno), a dále třídu, která reprezentuje zaměstnance nějakého podniku (dědí z osoby, ale navíc má ještě plat). Po stisknutí tlačítka se - podle toho, jaký RadioButton je zaškrtnutý - vytvoří buď instance osoby, nebo instance zaměstnance. V obou případech se pak tato instance uloží do společné kolekce (kolekce je vhodného typu tak, aby šla nabindovat do ListBoxu). Pomocí dvou tlačítek ("vlevo", "vpravo") lze kolekci procházet a v Labelu zobrazovat jednotlivé položky (v každém případě jméno, v případě zaměstnance i plat). Paralelně k tomu je celá kolekce nabindovaná v ListBoxu (ListBox je na tuto kolekci přesměrovaný pomocí vlastnosti DataSource).
Pozn.: Pro správné zobrazení položek kolekce v ListBoxu je vhodné přetížit metodu ToString() v příslušné třídě.

7. úkol - Pexeso
Prvky na formuláři: NumericUpDown, Button, Timer
Naprogramujte hru pexeso s čísly. Prvkem NumericUpDown se vybere velikost hracího pole (v rozumných mezích). Stiskem tlačítka se vygeneruje hrací pole (matice tlačítek, "kartiček"). Po stisknutí první kartičky se zobrazí jí příslušná číslice; po stisknutí druhé kartičky se zobrazí i její číslice, po uplynutí 3 sekund se však obě otočí zpět rubem nahoru (jsou-li číslice rozdílné), případně zmizí (jsou-li stejné).
Zvláštní požadavky: Rozdávání čísel je náhodné. Ošetřete, aby nešly otočit tři kartičky najednou.
Navrhněte a použijte třídu karticka, která dědí z Buttonu, avšak lze do ní navíc ještě uložit číslo.
