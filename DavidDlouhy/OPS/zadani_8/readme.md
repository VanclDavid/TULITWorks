
## Zadání 8:

  

Řešení úlohy běží na nastavbě Mbed OS zvané **[WinExtension](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/tree/master/WinExtension)**. V tomto adresáři je soubor [main.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_8/main.cpp), který implementuje program Minutka do WinExtension. Program minutka je k dispozici v souboru [win_ext_minutka.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_8/win_ext_minutka.cpp).

Úloha je řešena tak, že se na obrazovce zobrazí GUI, ve kterém lze provést následující 3 akce:
- Ukončit program - pokud se uživatel dotkne křížku, bude ukončeno (asynchronní)
- Upravit čas - je li stisknuto + nebo - přidá se / ubere se 1s
- Spustit odpočet - Spustí časovač

Po dokončení odpočtu se zobrazí červená obrazovka. pokud se stiskne tlačítko, tak se vrátíme zpět do časovače.
  

> WinExtension: [https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/tree/master/WinExtension](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/tree/master/WinExtension)

*V repositáři je pouze hlavní zdrojový soubor, nejsou zde dodány všechny potřebné soubory. Kompletní systém je v adreáři s WinExtension (obsahuje zadání č. 8)*
