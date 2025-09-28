# Rock Paper Scissors (Extended)

Et simpelt C-program, der simulerer en udvidet udgave af sten-saks-papir med 5 mulige valg. Programmet lader spilleren spille mod en agent, og første til 5 point vinder spillet. Flowcharts viser både oversigten og den interne gamelogik.

## Brug
```bash
gcc RockPaperScissors.c -o RockPaperScissors
./RockPaperScissors
```

Programmet reagerer på input:

Spørger spiller om at vælge et tal mellem 0–4 (🪨 0, 📄 1, ✂️ 2, 🦎 3, 🖖 4).

Validerer input (ugyldigt valg → ny forespørgsel).

Agenten vælger tilfældigt mellem 0–4.

Resultat afgøres af reglerne i check_winner:
- Tie → ingen point.
- Player win → spiller får 1 point.
- Agent win → agent får 1 point.

Point vises efter hver runde.

Spillet slutter når en af deltagerne når 5 point.

Filer:
- RockPaperScissors.c – Program
- overview_flowchart.png – Flowchart over spiloversigten
- game_logic_flowchart.png – Flowchart over gamelogikken
