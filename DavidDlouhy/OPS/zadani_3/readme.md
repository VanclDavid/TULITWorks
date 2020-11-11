
## Zadání 3:

  

V `main()` si inicializuji display a spustím 4 thready.

  

**Thread č. 1** se stará o periodické vykreslování textu na display. Je ovlivněn také `load_counter`.

  

**Therad č. 2** při svém spuštění vykreslí logo a počítá do 100 + graficky znázorňuje tento počet.

  

**Thread č. 3** detekuje stisknutí tlačítka. Dojde-li k této akci, pak se zakáže provedení zápisu na display, zastaví se inkrementace `load_counter` a zobrazí se chybová hláška.

  

**Thread č. 4** obsluhuje blikání diody a čas se přičítá a odčítá v časovém intervalu (0.1;1) vždy o 0.1

  
  

> Zdrojový soubor: [https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_3/zadani_3.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_3/zadani_3.cpp)

>

*V repositáři je pouze hlavní zdrojový soubor, nejsou zde dodány všechny potřebné soubory.*