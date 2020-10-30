
## Zadání 6:

  

Souběžně běží 2 "procesy" v nekonečné smyčce. Simulují tak virus Cookie. Po spuštění je uživatel v sériové komunikaci nalákán na past, aby 3x stisk tlačítko. Učiní-li tak, supstí se nekonečné vypisování žádosti o sušenku. Proto musí uživatel dát sušenku opětovným stisknutím tlačítka.


**Thread č. 1** se stará o výpis požadavku o sušenku.

**Thread č. 2** pracuje s tlačítkem a jeho stavy.
  

> Zdrojový soubor: [https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_6/zadani_6.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_6/zadani_6.cpp)

>

*V repositáři je pouze hlavní zdrojový soubor, nejsou zde dodány všechny potřebné soubory.*