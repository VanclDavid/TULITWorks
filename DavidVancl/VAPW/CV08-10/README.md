8. úkol - E-shop
Prvky na základním formuláři: 4x Button, 3x ListBox, Label
Prvky na druhém formuláři: 2x Button, 2x TextBox
Naprogramujte jednoduché rozhraní pomyslného e-shopu. V prvním ListBoxu jsou zobrazeny položky zboží které je na skladě, počet dostupných kusů a cena. Ve druhém ListBoxu jsou zobrazení uživatelé e-shopu (jejich jméno). Ve třetím ListBoxu je zobrazený nákupní košík uživatele, který je zrovna rozkliknutý ve druhém ListBoxu. Tento uživatel si může tlačítky přidávat jednotlivé kusy zboží do svého košíku (ze skladu se odečte jedna položka, v košíku se přičte jedna položka), případně zboží z košíku vracet zpět do skladu. Výběrem jiného uživatele se v ListBoxu 3 zobrazí jeho košík. Stiskem třetího tlačítka se zobrazí formulář na zadávání nového uživatele: TextBoxy na jméno a email, Buttony OK a Zrušit. Stiskem čtvrtého tlačítka se zobrazí v Labelu celková hodnota položek v košíku.
Zvláštní požadavky: Každý uživatel si  pamatuje svůj košík formou vhodné kolekce. Zboží je řešeno vhodně navrženou třídou; je nepřípustné do listboxů dávat pouze stringy.

9. úkol - background worker
1x Button
Vytvořte program, který bude v backgroundwrokeru počítat číslo pí. Implementujte metodou Monte Carlo:
http://petrfaltus.net/petr-faltus-ludolfovo-cislo-vypocet-pi-na-201-desetinnych-mist.php
Background worker běží donekonečna, jednou za 1e4 iterací udělá update výpočtu v GUI (sleduje se také počet iterací). Tlačítkem lze worker spustit a pak workeru sdělit požadavek na ukončení.
Zajímavost: Jaká je přesnost výpočtu? Co vše ji ovlivňuje? Jaký generátor náhodných čísel se používá v .NET a lze jej změnit?

10. úkol - geometrické tvary (pokračování)
1x Button, 1x NumericUpDown, 1x TextBox, 1x ListBox
Abstraktní třída Utvar z pátého úkolu bude nově implementovat rozhraní IUtvar. Rozhraní IUtvar má:
getter na povrch
getter na objem
metodu ToString (vrátí v jednom stringu název N-stěnu, objem a povrch)
Proveďte patřičné změny ve vašem stávajícím kódu. Dále implementujte statickou třídu UtvarFactory se statickou veřejnou metodou:
public static IUtvar UtvarFactory(string tvar, double delkahrany) { ... }
Tato metoda vygeneruje jeden z N-stěnů podle předaného stringu a vrátí jej jako návratovou hodnotu. Stiskem tlačítka se vyčte string z TextBoxu a podle tohoto stringu se ve factory vygeneruje nějaký útvar. Délka hrany se bere z NumericUpDown. Nový útvar je pak přidán do listboxu, kde se zobrazí.
