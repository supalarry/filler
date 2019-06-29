# filler
Game where enemies compete who can place more random pieces on the board. The board is fixed and receives piece to be placed until a player gives incorrent coordinate or a piece cannot be placed anymore. The piece is randomly generated by the intermediary virtual machine which hands out board and piece to be placed for player executables.

## Getting Started
Run **make** in root folder and player executable will be created. **players** folder consists of executables ready for the battle. After copying the executable to **resources/players folder**, the game can be launched by running in terminal
```
./filler_vm -p1 players/lskrauci.filler -p2 players/carli.filler -v -f maps/map00
```
The filler_vm hands out random pieces to both players (executables) who need to place as many as they can
while blocking the enemy from doing the same. **-p1** denotes player 1 executable and **-p2** denotes player 2 executable.
## Battle
![](https://media.giphy.com/media/H3GaIBdbDKHUaFdyt1/giphy.gif)

![alt text](https://i.imgur.com/3p4lgwf.png)
![alt text](https://i.imgur.com/NCsvoHv.png)
