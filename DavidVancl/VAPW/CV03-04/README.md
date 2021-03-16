3. úkol - Herní postava
Prvky ve formuláři: 2x Button, TextBox, Labely
Napište třídu, která reprezentuje herního hrdinu s těmito vlastnostmi: jméno, zdraví a umění boje. Stiskem prvního tlačítka se vygeneruje postava se jménem z TextBoxu a číselnými vlastnosmi:
zdraví: dvakrát hod šestistěnnou kostkou + 12
umění boje:  jeden hod šestistěnnou kostkou + 6
Vlastnosti se vypíšou do labelů. Zároveň se vygeneruje protivník s fixními vlastnostmi: umění boje 8 a zdraví 14. Stiskem druhého tlačítka dojde k boji mezi hrdinou a protivníkem - každá strana hodí dvěma kostkami a k výsledku přičte své umění boje. Kdo má vyšší číslo, vyhrál kolo boje a poraženému se odečtou dva životy (zapíše se do příslušného labelu). Opakovaným stiskem druhého tlačítka probíhají další kola souboje, dokud neumře jedna z postav (zdraví klesne na nulu).
Zvláštní požadavky: Hrdina i soupeř jsou reprezentováni instancemi stejné třídy, generování vlastností probíhá v konstruktoru. Měly by být dva konstruktory - jeden pracující s náhodou, a druhý, jenž nastaví fixní hodnoty.
Pozn.: Generátor náhody (třída Random) je vhodné mít v celém programu pouze jeden. Je-li potřeba, aby se generovala náhoda uvnitř nějaké třídy, předejte referenci na třídu Random jako parametr konstruktoru.

4. úkol - Přidávání grafických prvků kódem
Prvky ve formuláři: Button
Po stisknutí tlačítka se na formuláři zobrazí nové tlačítko s číslem 1. Opakovaným stiskem se pak vedle něj přidávají další a další tlačítka se stále vyššími čísly. Stiskem kteréhokoliv z těchto nových tlačítek se zobrazí MessageBox s číslem tlačítka, na které bylo kliknuto.
Zvláštní požadavky: Tlačítka se opravdu generují kódem a všechna tlačítka obsluhuje jediná metoda.