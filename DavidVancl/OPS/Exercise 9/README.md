# Cvičení 9
1. Appka spustí vlákno se snímáním tlačítka.<br>
2. Pokud je tl ON -> vypíše se "SENDING DATA" na display.<br>
3. Po dobu 2 second nemůže poslat znovu request aby nedošlo ke spamu.<br>
4. Poté znovu dovolí odeslat request.<br>
5. Čas je trochu nešikovně řešen, ale snažím se využívat novějších OS, na nichž knihovna NTBClient na stažení času z netu nefunguje(6.x +).<br>
 a alternativu jsem nedohledal, bohužel.
6. Podrobnější info o průběhu odeslání vypisuje na serial.
